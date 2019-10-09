/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (48.21%)
 * Likes:    867
 * Dislikes: 84
 * Total Accepted:    293.1K
 * Total Submissions: 608K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> v;

        if (numRows == 0) {
            return v;
        }

        vector<int> v1;
        v1.push_back(1);
        v.push_back(v1);

        if (numRows == 1) {
            return v;
        }

        vector<int> lastVec = v1;
        for (int i=1; i<numRows; i++) {

            vector<int> vec;
            vec.push_back(1);
            for (int j=0; j<i-1; j++) {
                vec.push_back(lastVec[j] + lastVec[j+1]);
            }
            vec.push_back(1);
            v.push_back(vec);
            lastVec = vec;

        }

        return v;
    }
};
// @lc code=end

