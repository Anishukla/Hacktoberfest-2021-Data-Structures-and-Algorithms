/* 
Selection Sort is another Sorting Algorithm.
For sorting an array of numbers from least to greatest, Selection Sort sorts by moving smaller values to the start as it iterates smaller values to the start as it iterates through array 
*/

/* *************** Pseudo Code ************
1. Store the first element as the smallest value you've seen so far.
2. Compare this item to the next item in the array until you find a smaller number.
3. If a smaller number is found, designate that smaller number to be the new 'minimum' and continue until the end of the array.
4. If the 'minimum' is not the value (index) you initially began with, swap the two values.
5. Repeat this with the next element until the array is stored.
*/

const swap = (arr, i, j) => {
  let temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
};

function selectionSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    let lowest = i;
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[lowest]) {
        lowest = j;
      }
    }
    if (i !== lowest) {
      swap(arr, i, lowest);
    }
  }
  return arr;
}

selectionSort([34, 22, 10, 19, 17]);

// BigO => O(N^2)
