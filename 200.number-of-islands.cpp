/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (50.97%)
 * Likes:    9715
 * Dislikes: 263
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '[['1','1','1','1','0'],['1','1','0','1','0'],['1','1','0','0','0'],['0','0','0','0','0']]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ['1','1','1','1','0'],
 * ⁠ ['1','1','0','1','0'],
 * ⁠ ['1','1','0','0','0'],
 * ⁠ ['0','0','0','0','0']
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ['1','1','0','0','0'],
 * ⁠ ['1','1','0','0','0'],
 * ⁠ ['0','0','1','0','0'],
 * ⁠ ['0','0','0','1','1']
 * ]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 * 
 * 
 */

/*
    明显的一道 dfs 的题

    1. 遍历每一个点，dfs 找到其上下左右为 1 的区域

    2. 访问过得点记录为 visited （因为如果 a 是 b 的连通区，那么 b 也是 a 的连通区，所以不必重复访问）

    3. 如果 visited 的点，直接跳过就可以了 （区域 A & B 不会存在相同的连通点 c，如果存在，说明 A & B 本身也是连通的）

*/

#include "helper/helper.hpp"

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty() || grid[0].empty()) return 0;

        int cnt = 0;

        int rowLen = grid.size();
        int colLen = grid[0].size();

        vector<vector<bool>> visited(rowLen, vector<bool>(colLen)); // 访问过的点

        
        for (int row=0; row<rowLen; row++) {
            for (int col=0; col<colLen; col++) {
                if (visited[row][col] || grid[row][col] == '0')  continue; // 访问过了就跳过

                dfs(row, col, grid, visited);

                cnt++;
            }
        }

        return cnt;
    }

private:
    void dfs(int row, int col, 
    vector<vector<char>>& grid, 
    vector<vector<bool>>& visited) {

        if (row < 0 || row >= grid.size() || // 横向越界
            col < 0 || col >= grid[0].size()) { // 纵向越界
                return;
        } 
        if (visited[row][col] || // 访问过了
            grid[row][col] == '0') { // 是水
            return;
        }

        visited[row][col] = true; // 记录访问点

        // 深度搜索
        dfs(row+1, col, grid, visited);
        dfs(row-1, col, grid, visited);
        dfs(row, col+1, grid, visited);
        dfs(row, col-1, grid, visited);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid(4, vector<char>(5));
    int tmp[4][5] = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            grid[i][j] = tmp[i][j];
        }
    }

    vector<char> v = { '1' };
    vector<vector<char>> gr = { v, v }; 

    Solution *sol = new Solution();
    int res = sol->numIslands(gr);
    cout << res << endl;
    return 0;
}


