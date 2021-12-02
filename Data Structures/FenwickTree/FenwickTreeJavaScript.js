//CREATED BY - HARSH BHARVADA
class FenwickTree {
    constructor(size = 0) {
        this.size = size;
        this.tree = Array(size + 1).fill(0);
    }

    /**
     * Add value to the original index
     * @param {*} index 
     * @param {*} val 
     */
    add(index, val) {
        while (index <= this.size) {
            this.tree[index] += val;
            index += (index & -index);
        }
    }

    /**
     * Get Sum Range
     * @param {*} range 
     * @returns 
     */
    getSum(range) {
        let res = 0;
        while (range > 0) {
            res += this.tree[range];
            range -= (range & -range);
        }
        return res;
    }

    /**
     * Get Tree
     * @returns 
     */
    getTree() {
        return this.tree;
    }
}

module.exports.FenwickTree = FenwickTree;