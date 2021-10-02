/*
https://leetcode.com/problems/rotate-image/
Author: Aditi Rao (aditirao7 on github)
Time Complexity: O(n^2)
Space Complexity: O(1) extra space
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix.size()-1;
        // l corresponds to left/top, r corresponds to right/bottom
	// Matrix is considered to be made of concentric square shaped rings
	// elements are swapped layer by layer 
        while(l<r)
        {
            for(int i=0; i<r-l; i++)
            {
                swap(matrix[l][l+i], matrix[l+i][r]);
                swap(matrix[l][l+i], matrix[r][r-i]);
                swap(matrix[l][l+i], matrix[r-i][l]);
            }
            l++;
            r--;
        }
    }
};
