/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.72%)
 * Likes:    1420
 * Dislikes: 221
 * Total Accepted:    270.2K
 * Total Submissions: 795.4K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if (obstacleGrid.empty()) return 0;

        // 设起点为 0 0
        int rowCnt = obstacleGrid.size();
        int colCnt = obstacleGrid[0].size();

        vector<vector<long>> dp (rowCnt, vector<long> (colCnt, 0));

        for (int x = 0; x < rowCnt; x++) {
            for (int y = 0; y < colCnt; y++) {
                
                // 1. 处理障碍物
                if (obstacleGrid[x][y] == 1) continue;

                // 2. 处理边界
                if (x == 0 && y == 0) dp[0][0] = 1;
                else if (x == 0) dp[x][y] = dp[0][y - 1];
                else if (y == 0) dp[x][y] = dp[x - 1][0];

                // 3. 处理正常情况
                else dp[x][y] = dp[x][y - 1] + dp[x - 1][y];

                // cout << dp[x][y] << endl;
            }
        }
        
        return dp[rowCnt - 1][colCnt - 1];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<int>> obstacleGrid {
        vector<int>{0, 0},
        // vector<int>{0, 1, 0},
        // vector<int>{0, 0, 0}
    };
   Solution *sol = new Solution();
   int res = sol->uniquePathsWithObstacles(obstacleGrid);
   cout << res << endl;
    return 0;
}


