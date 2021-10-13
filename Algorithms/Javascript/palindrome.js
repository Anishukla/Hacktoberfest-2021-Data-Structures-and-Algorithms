//determines whether a word is a palindrome or not
const isPalindrome = function (word) {
  let arr = [];

  //loops through word in reverse, then pushes to array
  for (let i = word.length - 1; i >= 0; i--) {
    arr.push(word[i]);
  }

  // combines the arr
  let newWord = arr.join("");

  // compares word with newWord, if they match true is returned else false is returned
  if (word == newWord) {
    return true;
  } else {
    return false;
  }
};
