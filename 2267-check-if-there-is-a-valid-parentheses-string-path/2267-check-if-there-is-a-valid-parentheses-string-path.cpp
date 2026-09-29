class Solution {
    int m, n;
    bool visited[100][100][201];

    bool dfs(const vector<vector<char>>& grid, int r, int c, int open) {
        if (grid[r][c] == '(') {
            open++;
        } else {
            open--;
        }

        if (open < 0 || open > (m + n - 1) / 2) return false;

        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }

        if (visited[r][c][open]) return false;
        visited[r][c][open] = true;

        if (r + 1 < m && dfs(grid, r + 1, c, open)) return true;
        if (c + 1 < n && dfs(grid, r, c + 1, open)) return true;

        return false;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        return dfs(grid, 0, 0, 0);
    }
};