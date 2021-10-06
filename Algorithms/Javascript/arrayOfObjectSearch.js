const _ = require("lodash");

module.exports.ArrayOfObjectSearch = class {
  constructor(data) {
    this.indexes = [];
    this.data = data; // object or array to be searched
  }
  /**
   * 
   * @param {*} index 
   */
  addIndex(index) {
    if(_.isArray(index)) return this.indexes = _.concat(this.indexes, index)
     this.indexes.push(index);
  }

  /**
   * @Info A recursive function to get the value of an index at any depth in an object
   * @param {*, *} (index, object )
   */
  getIndexValue(index, object){
    let temp = object;
    const indexes = `${index}`.split(".");
    _.forEach(indexes, function(child){
      if(temp[child]) temp = temp[child];
    })
    return temp;
  }

  /**
   * 
   * @param {*} keyword 
   * @returns Promise that resolves a result matching the keyword at the specified indexes
   */
  find(keyword) {
    return new Promise((resolve, reject) => {
      try {
        const filtered = _.filter(
          this.data,
          function (data) {
            return !_.isEmpty(
              _.find(
                // dynamically generate searchable indexes
                _.concat(
                  _.map(this.indexes, function (index) {
                    // get index value to depth n
                    const value = this.getIndexValue(index, data);
                    return `${value}`
                      .toLowerCase()
                      .split(/[^a-zA-Z0-9]/g);
                  }.bind(this))
                ),
                function (word) {
                  return _.find(
                    `${keyword}`.toLowerCase().split(/[^a-zA-Z0-9]/g),
                    function (keyPhrase) {
                      return `${word}`.toLowerCase().includes(keyPhrase);
                    }
                  );
                }
              )
            );
          }.bind(this)
        );
        resolve(filtered)
      } catch (error) {
        reject(error);
      }
    });
  }
};
