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

 /* 
    记录一下 nlogn 的查找：

    用二分：

        设 ends 为最终递增数组

        left & right 指向 ends 的头和尾
        
        如果没找到 （right 还在尾部），则在 ends 尾部加入这个值 （不覆盖） push_back
        否则找到则在 right 的位置覆盖（替换）元素，这么做可以保证获取最长的可能性

        对于没找到的情况如此理解：
        对于 3 5 10，此时来了个 6 7，如果不替换，7 就不能入列
        替换之后变成了 3 5 6，这样 7 就能入列了

    牛皮
  */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if (nums.empty()) return 0;
        
        vector<int> dp(nums.size(), 1);
        /*
            中途可能产生最长的值，
            因为是要和以前位置的数逐个对比逐个去对比 

            对于 4 5 6 1 2 7 8
            在位置 7 的时候，最长串应该是 dp[6] + 1 

        */
        int longest = 1; 

        // 使用 dp，和前面的值去对比，关键是要喝前面的对比
        for (int i = 1; i < nums.size(); i++) { // 1 - len
            
            for (int j = 0; j < i; j++) { // 0 - i

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
