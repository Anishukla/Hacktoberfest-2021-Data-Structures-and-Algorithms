//LOGIC:
// It's similar to how human solve Sudoku.
// Each time, start from the location with fewest possible values, choose one value from it and then update the board and possible values at other locations. If this update is valid, keep solving. 
//If this update is invalid (leaving zero possible values at some locations) or this value doesn't lead to the solution, undo the updates and then choose the next value.
// Since we calculated val at the beginning and start filling the board from the location with fewest possible values, the amount of calculation and thus the runtime can be significantly reduced:

class Solution {
public:
    
    //ValidRow
    bool checkRow(vector<vector<char>>& board,int row,char num){
        for(int i=0;i<board.size();i++){
            if(board[row][i]==num){
                return false;
            }
        }
        return true;
    }
    //valid column
    bool checkCol(vector<vector<char>>& board,int col,char num){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==num){
                return false;
            }
        }
        return true;
    }
    //valid box
    bool checkBox(vector<vector<char>>& board,int startRow,int startCol,char num){
        for(int row=0;row<3;row++){
            for(int col=0;col<3;col++){
                if(board[row+startRow][col+startCol]==num){
                    return false;
                }
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char>>& board,int row,int col,char num){
        bool validRow=checkRow(board,row,num);
        bool validCol=checkCol(board,col,num);
        bool validBox=checkBox(board,row-row%3,col-col%3,num);
        
        return validRow && validCol && validBox && (board[row][col]=='.');
    }
    bool sudokuSolver(vector<vector<char>>& board,int row,int col) {
       
        if(row==9){
            return true;
        }
        if(col==9){
            return sudokuSolver(board,row+1,0);
        }
        if(board[row][col]!='.'){
            return sudokuSolver(board,row,col+1);
        }
        
        for(int i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col]=i;
                
                if(sudokuSolver(board,row,col+1)){
                    return true;
                }
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board){
        sudokuSolver(board,0,0);
    }
};
//Time Complexity:O(9^(n*n))
//Space Complexity:O(n*n)