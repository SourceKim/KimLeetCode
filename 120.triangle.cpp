/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (41.03%)
 * Likes:    1706
 * Dislikes: 206
 * Total Accepted:    231.5K
 * Total Submissions: 540.1K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
/* 
    思路：
        在原三角形中做 DP

        边界特殊处理一下，其他情况对应 上一层的 ele - 1 和 ele 位置的值即可 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        for (int row = 1; row < triangle.size(); row++) { // 第一层不处理

            for (int ele = 0; ele < triangle[row].size(); ele++) {

                // 1. 处理边界 （直接和对应位置相加）

                // 第一个
                if (ele == 0) triangle[row][ele] += triangle[row - 1][0];

                else

                // 最后一个
                if (ele == triangle[row].size() - 1) triangle[row][ele] += triangle[row - 1][ele - 1];

                // 处理中间
                else {
                    triangle[row][ele] += min(triangle[row - 1][ele - 1], triangle[row - 1][ele]);
                }
            }
        }

        // 取最后一层最小值即可
        return *min_element(triangle.back().begin(), triangle.back().end());
        
    }
};
// @lc code=end

