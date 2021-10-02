/*
*********  Frequency Counter *******
Compares two positive integers and finds out if they both have the same frequency of digits
Returns boolean value based on comparison

example 1: 
    Given the numbers 1110001, 1001101 function returns true
example 2: 
    Given the numbers 123451, 123455 function will return false (the first integer has 1 twice, while the second integer has 5 twice)
example 3:
    Given the numbers 1200, 120 function will return false
*/

function sameFrequency(num1, num2){
    // Turn integers into numbers to be able to derive length from them
    let n1 = num1.toString();
    let n2 = num2.toString();
  
    // Edge Case: If numbers are not the same length Frequency cannot be the same - return false
    if(n1.length !== n2.length) return false;
    
    let obj1 = {};
  
    // Iterate over first integer and add each digit to object as a key with value of 1 
    //      if digit is already in object increase value by 1
    for(let digit of n1){
        obj1[digit] = ++obj1[digit] || 1;
    }
  
    // Iterate over second integer 
    //      - If digit is a key in the obj Object and has value > 0 decrease value by 1
    //      - Else frequency of digit is not the same, function will return false
    for(let digit2 of n2){
        if(obj1[digit2] > 0){
            --obj1[digit2]
        } else { 
            return false
        }
        
    }

    // At this point obj Object should have value of 0 for all keys 
    //      meaning frequencies are the same for all digits;
    //      Function can return true;
    
    return true;
    
  }

  // Time Complexity is 0(n)