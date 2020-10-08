"""
Link to the problem: https://leetcode.com/problems/zigzag-conversion/
Problem Description: 
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
"""
def convert(s: str, numRows: int) -> str:
    # Base Case solution, i.e., return the string if len(string) = 1
    if numRows == 1:
        return s
    # For storing the string row-wise, i.e., for the example above:
    # Row 1 will contain: P I N
    # Row 2 will contain: A L S I G
    # and so on...
    str_index = ["" for x in range(len(s))]
    row = 0
    r = ''
    for i in range(len(s)):
        # Add the character at the respective row number
        str_index[row] += s[i]
        if row == 0:
            # Go down if row is anywhere between 0 and numRows - 2
            down = True
        elif row == numRows - 1:
            # Start going up if row is numRows - 1, i.e., if it reaches the last row
            down = False
        if down:
            row += 1
        else:
            row -= 1
    i = 0
    # Add the string in the variable 'r' row-wise
    while i < len(str_index):
        r += str_index[i]
        i += 1
    return r

print(convert("PAYPALISHIRING", 4), end = "")