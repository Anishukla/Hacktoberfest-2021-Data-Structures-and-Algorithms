const shuffle = (array) => {
  let m = array.length, t, i;

  // While there remain elements to shuffle...
  while (m) {

    // Pick a remaining element...
    i = Math.floor(Math.random() * m--);

    // And swap it with the current element
    t = array[m];
    array[m] = array[i];
    array[i] = t;
  }

  return array;
}

const array = [0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89];
console.log('array', array);

const mixedArray = shuffle(array);
console.log('mixedArray', mixedArray);
