/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * algorithms
 * Medium (41.63%)
 * Likes:    2664
 * Dislikes: 72
 * Total Accepted:    284.5K
 * Total Submissions: 668.2K
 * Testcase Example:  '[[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]]\n' +
  '5'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted in ascending from left to right.
 * Integers in each column are sorted in ascending from top to bottom.
 * 
 * 
 * Example:
 * 
 * Consider the following matrix:
 * 
 * 
 * [
 * ⁠ [1,   4,  7, 11, 15],
 * ⁠ [2,   5,  8, 12, 19],
 * ⁠ [3,   6,  9, 16, 22],
 * ⁠ [10, 13, 14, 17, 24],
 * ⁠ [18, 21, 23, 26, 30]
 * ]
 * 
 * 
 * Given target = 5, return true.
 * 
 * Given target = 20, return false.
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/* 

    1. 从左下角开始 （x, y）

    2. 如果这个值 > target，就往上 y--

    3. 如果这个值 < target，就往右 x++

    退出：

        x >= col || y < 0
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if  (matrix.empty() || matrix[0].empty()) return false;

        int row = matrix.size();
        int col = matrix[0].size();

        int x = 0, y = row - 1;
        while (true)
        {
           // 退出
           if (x >= col || y < 0) break; 

           // search
           if (matrix[y][x] > target) y--;
           else if (matrix[y][x] < target) x++;
           else return true;
        }

        return false;
        
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> input0 { 1, 1 };
    vector<vector<int>> input { input0 };

    Solution *sol = new Solution();
    bool res = sol->searchMatrix(input, 2);
    return 0;
}
