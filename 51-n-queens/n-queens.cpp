class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));
        
        // Tracking sets for columns and diagonals
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // row + col
        vector<bool> diag2(2 * n - 1, false); // row - col + (n - 1)
        
        backtrack(0, n, board, results, cols, diag1, diag2);
        return results;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& results,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + (n - 1);

            // Check if column or diagonals are under attack
            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            // Place queen
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            // Move to next row
            backtrack(row + 1, n, board, results, cols, diag1, diag2);

            // Backtrack: remove queen
            board[row][col] = '.'; 
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};