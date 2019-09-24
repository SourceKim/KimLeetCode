/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.93%)
 * Likes:    4372
 * Dislikes: 400
 * Total Accepted:    661.3K
 * Total Submissions: 2.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// #include <stdio.h>
// #include <iostream>

// using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        const int len = s.length();

        if (len < 2) {
            return s;
        }

        // 使用动态规划
        
        bool dp[len][len];
        memset(dp, false, len * len * sizeof(bool));

        // for (int i=0; i<len; i++) {

        //     for (int j=0; j<len; j++) {
        //         cout << dp[i][j] << endl;
        //     }
        // }

        int start = 0; // 最长回文起点
        int maxLen = 1; // 最长回文长度

        // 1. 先找出 1 个相同 & 2 个相同的回文串 "a" "aa"
        for (int i=0; i<len; i++) {

            // 1 个
            dp[i][i] = true;

            // 2 个
            if (i < len - 1) {
                bool isSame = s[i] == s[i+1];
                dp[i][i+1] = isSame;

                if (isSame) {
                    // 保存状态
                    start = i;
                    maxLen = 2;
                }

            }
            
        }

        // 2. 递推 3 个以及以上的回文串
        for (int subLen = 3; subLen <= len; subLen++) { // 回文串的长度 subLen

            for (int left = 0; left + subLen - 1 < len; left++) { // 回文串左边（起始

                int right = left + subLen - 1; // 回文串右边

                // 状态转移
                if (s[left] == s[right] && dp[left + 1][right -1]) {

                    dp[left][right] = true;

                    // 保存下标
                    start = left;
                    maxLen = subLen;

                }
            }
        }

        // cout << start << endl;
        // cout << maxLen << endl;

        return s.substr(start, maxLen);
        
    }
};

// int main(int argc, char const *argv[])
// {
//     string s = "abcda";
//     Solution *sol = new Solution();
//     string str = sol->longestPalindrome(s);
//     cout << str << endl;
//     return 0;
// }


