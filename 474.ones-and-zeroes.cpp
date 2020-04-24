/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 *
 * https://leetcode.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (40.77%)
 * Likes:    832
 * Dislikes: 200
 * Total Accepted:    43.2K
 * Total Submissions: 102.6K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * In the computer world, use restricted resource you have to generate maximum
 * benefit is what we always want to pursue.
 * 
 * For now, suppose you are a dominator of m 0s and n 1s respectively. On the
 * other hand, there is an array with strings consisting of only 0s and 1s.
 * 
 * Now your task is to find the maximum number of strings that you can form
 * with given m 0s and n 1s. Each 0 and 1 can be used at most once.
 * 
 * Note:
 * 
 * 
 * The given numbers of 0s and 1s will both not exceed 100
 * The size of given string array won't exceed 600.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
 * Output: 4
 * 
 * Explanation: This are totally 4 strings can be formed by the using of 5 0s
 * and 3 1s, which are “10,”0001”,”1”,”0”
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: Array = {"10", "0", "1"}, m = 1, n = 1
 * Output: 2
 * 
 * Explanation: You could form "10", but then you'd have nothing left. Better
 * form "0" and "1".
 * 
 * 
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// @lc code=start

/* 给到 m 个 0 & n 个 1，找出给定数组中最多有几个字符串符合

    使用 dp 解决

        dp[][] 二维数组，存着 m & n，代表最多有几个字符串符合，初始值为 0

        1. 遍历数组中的字符串 str
        2. 统计这个字符串中 0 & 1 的数量 cnt0 cnt1

        // 然后找到这个字符串加入后，和以往的相比（没加入时）哪个大

        3. 遍历 dp 数组，i , j （i 表示有 i 个 0， j 表示有 j 个 1）

            其中 i 从 cnt0 ~ m，j 从 cnt1 ~ n 对应的 dp 值与先有的 + 1 取大的

            上述原先有的表达为：dp[i - cnt0][j - cnt1]

            注意 i & j 要从后遍历


    递推公式：

        dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);

 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // dp 从 0 个开始算，所以是 m+1 n+1
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, 0));

        for (string str : strs) {

            // 统计 cnt0，cnt1
            int cnt0 = 0, cnt1 = 0;
            for (char c : str) {
                if (c == '0') cnt0++;
                else cnt1++;
            }

            // 递推
            for (int i = m; i >= cnt0; i--) {
                for (int j = n; j >= cnt1; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<string> input {"10","0001","111001","1","0"};
    Solution *sol = new Solution();
    int res = sol->findMaxForm(input, 5, 3);
    cout << res << endl;
    return 0;
}
