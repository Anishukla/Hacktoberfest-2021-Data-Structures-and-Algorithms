/*
 * Remove all elements from the initial array 
 * that are of the same value as these arguments.
*/

function seekAndDestroy(arr) {
  let newArr = [], args = [];

  args.push(...[...arguments]);
  args.shift();

  newArr = [...arr, ...args].filter(item => {
    return arr.indexOf(item) < 0 || args.indexOf(item) < 0;
  });

  return newArr;
}

console.log(
  seekAndDestroy([2, 5, 1, 4, 2, 3], 2, 3)
  // expected output [5, 1, 4]
);