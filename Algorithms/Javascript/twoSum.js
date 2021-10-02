/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Challenge: Can you come up with an algorithm that is less than O(n^2) time complexity?
The code below fits this challenge!
*/

let twoSum = (array, sum) => {
    let storageHash = {}
    let nums = []
    
    for(let i in array){
      let addend = sum - array[i]
        
        if (addend in storageHash){
            nums.push([addend, array[i]])
        }
        storageHash[array[i]] = i
    }
    return nums
}
/* Code explanation: 
Essentially, we are using the O(1) time complexity of a javascript object to limit our time complexity. We have a "storageHash" object that is used to store every value we travel
to in the array. We also have an "addend" variable. For every value in the array, the addend value gets its complement number which will make both numbers add up to the target. If
this complement number is an existing number in the array that we stored in "storageHash", that means we have found our two numbers that add up to the target! We add this pair to 
our "nums" array and will return an array of the pairs at the end. Looking complement values up with an object heavily lowers the time complexity due to its O(1) lookup time. */
