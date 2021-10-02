/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
const rotateArray = (nums, k) => {
  for (let i = 0; i < k; i++) {
    const last = nums.pop();

    nums = [last, ...nums];
  }

  return nums;
};

export default rotateArray;
