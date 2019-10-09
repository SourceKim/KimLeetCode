/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (45.43%)
 * Likes:    560
 * Dislikes: 180
 * Total Accepted:    228.4K
 * Total Submissions: 502.8K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
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
    vector<int> getRow(int rowIndex) {


        vector<int> result(rowIndex+1,1);
        if(rowIndex<2)
           return result;
        for(int i=2;i<=rowIndex;i++){
            for(int j=i-1;j>0;j--){
                result[j]+=result[j-1];
            }
        }
        return result;
        
    }
};
// @lc code=end

