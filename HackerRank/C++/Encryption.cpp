/*
    Solution Added By: Anish Kumar
    Github Profile: https://github.com/KmrAnish04

    Hackerrank Problem: Encryption
    Problem Link: https://www.hackerrank.com/challenges/encryption/problem
    Difficulty Level: Medium

    Time Complexitiy: O(N^2) (approx)
    Space Complexitiy: O(1) 

    Algorithm:
    1. Firstly, we will remove all the space from the string and will calculate the floor and ceil values of the final string.
    2. Now will form row and column values for the grid of minimum possible area.
    3. After all the above operation now we will add final characters in the resultant string.
       Please note that here we dont have an actual grid (matrix) we just have the string and we have to print the all the column values seprated by a space.
       So, here we will start from first character (or first column) of the string and will print character after "column" no. of characters till the actual length
       of the string, similarly we will do the same for each column.
    
    *If you did'nt got, please try to dry run by yourself.

    We can optimize the space complexity more by removing the spaces from the given string "s" insted of making a different string like "actualStr" in below code.

*/


string encryption(string s) {
    int sLen=s.length();
    string actualStr;
    string res="";
    
    for(int i=0; i<sLen; i++){
        if(s[i]!=32) actualStr+=s[i]; // removing spaces
    }
    
    int actualLen=actualStr.length();
    float sqrtVal=sqrt(actualLen);
    int flr=floor(sqrtVal); // floor value
    int cel=ceil(sqrtVal); // ceil value
    
    int row=flr; // rows of the grid
    int col=cel; // column of the grid

    int i=1;
    while(row*col<actualLen){
        if(i%2!=0 && col<cel) col++; // forming the grid of minimum possible area
        else if(i%2==0 && row<col) row++;
        i++;
    }
    
    for(int i=0; i<col; i++){
        int tmprow=i;
        while(tmprow<actualLen){
            res+=actualStr[tmprow]; // adding the characters into final string
            tmprow+=col;
        }
        if(i!=col-1) res+=" ";
    }
    
    return res;
}


