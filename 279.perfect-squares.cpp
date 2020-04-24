/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.25%)
 * Likes:    2306
 * Dislikes: 174
 * Total Accepted:    257.2K
 * Total Submissions: 571.2K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        
        vector<long> dp (n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j * j <= i; j++) {
                
                dp[i] = min(dp[i - j * j] + 1, dp[i]);

            }

        }

        return dp[n];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    int res = sol->numSquares(12);
    cout << res << endl;
    return 0;
}

