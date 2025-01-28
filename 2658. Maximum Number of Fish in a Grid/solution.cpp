class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int answer = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                answer = max(answer, dfs(grid, visited, i, j));
            }
        }
        return answer;
    }
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(row < 0 || row >= grid.size() || col <  0 || col >= grid[0].size() || grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        return grid[row][col] + dfs(grid, visited, row, col + 1) + dfs(grid, visited, row, col - 1) + dfs(grid, visited, row + 1, col) + dfs(grid, visited, row - 1, col);
    }
};