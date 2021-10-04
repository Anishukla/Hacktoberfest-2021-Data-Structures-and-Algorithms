/* Given an array of integers nums return Maximum time repeated elementt.

Example:
Input: nums = [2,2,11,15]
Output: 2
Output: Because 2 repeated maximum times
*/
function majorityElement(a) {
    let charMap = {}
    let MaxNum = 0;
    let MaxChar;
    //we are using object to store the maximum repeated number 
    a.forEach((word) => {
        if (charMap[word]) {
            charMap[word]++;
        } else {
            charMap[word] = "-1"
        }
    })
    //checking whether num is present  greater then MaxNum if yest we storing that number in MaxChar
    for (const char in charMap) {
        if (charMap[char] > MaxNum) {
            MaxNum = charMap[char]
            MaxChar = char
        }
    }
    return MaxChar
}
//complexity :O(n)
//console.log(majorityElement([6 ,1 ,15 ,19 ,9, 13 ,12, 6 ,7 ,2 ,10 ,4 ,1 ,14 ,11 ,14 ,14 ,13], 18))