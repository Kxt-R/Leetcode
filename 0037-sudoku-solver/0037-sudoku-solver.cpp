class Solution {
public:
    bool issafe(int r,int c,int val,vector<vector<bool>> &grid,vector<vector<char>> &sudoku){
        int gridno=(3*(r/3))+(c/3);
        if(grid[gridno][val]) return false;
        for(int i=0;i<9;i++){
            if(sudoku[r][i] - '0'==val)return false;
            if(sudoku[i][c]- '0'==val) return false;
        }

        return true;
    }

    void  runner(int r,int c,bool &done,vector<vector<bool>> &grid,vector<vector<char>> &sudoku){
        if(r==9) {
            done=true;
            return;
        }

        if(c==9) {
            runner(r+1,0,done,grid,sudoku);
            return;
        }

        if(sudoku[r][c]!='.'){
            runner(r,c+1,done,grid,sudoku); 
            return;
        }

        for(int i=1;i<=9;i++){
            if(issafe(r,c,i,grid,sudoku)){
                sudoku[r][c]=i + '0';
                grid[(3*(r/3))+(c/3)][i]=true;
                runner(r,c+1,done,grid,sudoku);
                if(done) return;
                grid[(3*(r/3))+(c/3)][i]=false;
                sudoku[r][c]='.';
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> grid(9,vector<bool>(10));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int val=board[i][j]-'0';
                grid[(3*(i/3))+(j/3)][val]=true;
            }
        }
        bool done=false;
        runner(0,0,done,grid,board);
        return;
    }
};