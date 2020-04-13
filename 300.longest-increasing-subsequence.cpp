/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (41.52%)
 * Likes:    3930
 * Dislikes: 89
 * Total Accepted:    334.1K
 * Total Submissions: 793.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
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
    int lengthOfLIS(vector<int>& nums) {

        if (nums.empty()) return 0;
        
        vector<int> dp(nums.size(), 1);

        int longest = 1; // 中途可能产生最长的值，2020/04/13 这里没想到

        for (int i = 1; i < nums.size(); i++) {
            
            for (int j = 0; j < i; j++) {

                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            longest = max(longest, dp[i]);
        }

        return longest;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> arr {1,3,6,7,9,4,10,5,6};

    Solution *sol = new Solution();
    int res = sol->lengthOfLIS(arr);
    cout << res << endl;
    return 0;
}
