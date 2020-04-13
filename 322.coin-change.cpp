/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (32.14%)
 * Likes:    2324
 * Dislikes: 82
 * Total Accepted:    253.8K
 * Total Submissions: 789.8K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
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
    int coinChange(vector<int>& coins, int amount) {

        /*
        初始化 dp 
        dp[i] 表示 i 元的时候，最少需要多少个银币
        数量为 amount + 1 个， 因为数组从 0 开始的
        初始值为 amount + 1，因为 第 i 个最多有 i 个 （1 元）银币， amount + 1 就是极大值 
        */
        int current_max = amount + 1;
        vector<int> dp(amount + 1, current_max);

        dp[0] = 0;

        // 为 dp 赋值
        for (int i = 1; i <= amount; i++) {
            
            /*
            尝试每一个面额的硬币 [1 2 5]，去不断更新 dp，因为第 j 个不一定是最小的

            (dp[i - coins[j]] + 1) 状态转移：
                比如 i=10, j=4 （找 10 元的最小组合数，现在找到了第 4 元硬币）：
                d[10] = d[10 - 4] + 1 = d[6] + 1
                我们只需要找到 6 元组合的最小值即可，其中 +1 是加上这个 4 元。
            */
           for (int j = 0; j < coins.size(); j++) {
               if (coins[j] <= i) { // 5 元面额不可能更新 dp[3]
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); // 反复更新
               }
           }
        }

        return dp[amount] > amount ? -1 : dp[amount];

    }
};
// @lc code=end

