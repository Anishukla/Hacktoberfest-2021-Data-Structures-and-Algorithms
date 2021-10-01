/*
************** Merging Arrays *************
Merge Pseudo Code:
1. Create result array, initially make it empty.
2. Create two index pointer variables, set to 0
(Starts at first item for both input arrays)
3. While both index values are valid values for their respective arrays
  3.1 If value in 1st array < value in 2nd array, push former into result array. Increase 1st pointer
  3.2 Else push value from 2nd array into result array. Increase 2nd Pointer
4. While first pointer is valid, push value from first array into result array. Increase 1st pointer
5. While second pointer is valid, push value from second array into result array. Increase 2nd pointer
6. Return result array
*/

// merge([1, 3], [2, 4]) ====> [1, 2, 3, 4]
// merge([4, 6, 7], [1, 5]) ===> [1, 4, 5, 6, 7]

function merge(sortedArr1, sortedArr2) {
  let p1 = 0;
  let p2 = 0;
  let res = [];

  while (p1 < sortedArr1.length && p2 < sortedArr2.length) {
    if (sortedArr1[p1] < sortedArr2[p2]) {
      res.push(sortedArr1[p1]);
      p1++;
    } else {
      res.push(sortedArr2[p2]);
      p2++;
    }
  }

  while (p1 < sortedArr1.length) {
    res.push(sortedArr1[p1]);
    p1++;
  }

  while (p2 < sortedArr2.length) {
    res.push(sortedArr2[p2]);
    p2++;
  }

  return res;
}

merge([4, 6, 7], [1, 5]);

// BigO => 0(n + m)
