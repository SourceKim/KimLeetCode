/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Easy (53.18%)
 * Likes:    1267
 * Dislikes: 1422
 * Total Accepted:    377.7K
 * Total Submissions: 710.3K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (i.e., buy one and sell one share of the stock
 * multiple times).
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [7,1,5,3,6,4]
 * Output: 7
 * Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit
 * = 5-1 = 4.
 * Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 =
 * 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

#include <vector>

using namespace std;

// @lc code=start
/* 
    无需考虑跳着卖出最赚钱

    只要后一个大于前一个即使利润了

    比如 3 7 8 1 5

    最大的是 (8 - 3) + (5 - 1)

    也就相当于是： (7 - 3) + (8 - 7) + (5 - 1)

    因此利润是会累加的
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit = 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            
            int delta = prices[i + 1] - prices[i];
            if (delta > 0) {
                maxProfit += delta;
            }
        }

        return maxProfit;
    }
};
// @lc code=end

