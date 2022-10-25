class Solution {
private:
    vector<vector<string>> result;
    void backtracking(int n, int cur, vector<string>& chessboard){
        if (cur == n){
            result.push_back(chessboard);
            return;
        }
        for(int i = 0; i<n; i++){
            if (isValid(cur, i, chessboard)){
                chessboard[cur][i] = 'Q';
                backtracking(n, cur+1, chessboard);
                chessboard[cur][i] = '.';
            }
        }
    }
    bool isValid(int row, int col, vector<string>& chessboard){
        for(int i =0; i<row; i++){
            if(chessboard[i][col] == 'Q') return false;
        }
        for(int i =row-1, j = col-1; i>=0 && j >=0; i--, j--){
            if(chessboard[i][j] == 'Q') return false;
        }
        for(int i = row-1, j = col+1; i>=0&&j>=0; i--, j++){
            if(chessboard[i][j] == 'Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> chessboard(n,std::string(n,'.'));
        backtracking(n,0,chessboard);
        return result;
    }
};