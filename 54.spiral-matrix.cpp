/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (37.95%)
 * Likes:    4576
 * Dislikes: 698
 * Total Accepted:    544.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * 
 * 
 */

/*
设 m 为行数，n 为列数；
设 row 为当前的行，col 为当前的列
*/

#include "helper/helper.hpp"

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0, col = -1; // 因为使用的是 ++col，所以 col=-1
        while (true){
            for (int i=0; i<n; i++) res.push_back(matrix[row][++col]); // →
            if (--m == 0) break; // 遍历完行数要 -1，并且要判断是否已经没有行或者列了
            for (int i=0; i<m; i++) res.push_back(matrix[++row][col]); // ↓
            if (--n == 0) break;
            for (int i=0; i<n; i++) res.push_back(matrix[row][--col]); // ← 
            if (--m == 0) break;
            for (int i=0; i<m; i++) res.push_back(matrix[--row][col]); // ↑
            if (--n == 0) break;
        }
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution *sol = new Solution();
    vector<int> res = sol->spiralOrder(matrix);
    printVector(res);
    return 0;
}
