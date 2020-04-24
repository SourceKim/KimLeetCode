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

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.length();

        if (len < 2) return s;

        int start = 0, maxLen = 0; // 分别存储 开头 & 最长长度

        int idx = 0; // 指向 string 的每一个 char

        while (len - idx > maxLen / 2)
        { // 出口：当 剩余长度 小于 最大长度的一半

            int left = idx, right = idx; // 定义 左右 指针，初始指向当前的 idx

            // 处理重复的 字符 【跳过该字符】，这样才能回文
            while (right < len - 1 && s[right + 1] == s[right])
            {
                right++;
            }

            // idx 指向 right 的下一个
            idx = right + 1;

            // 开始扩散 （下一位相同才向两边扩散）
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                right++;
                left--;
            }

            // 更新 maxLength 和 left
            if (maxLen < right - left + 1) {
                maxLen = right - left + 1;
                start = left;
            }
        }
        

        return s.substr(start, maxLen);
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string s = "bananas";
    Solution *sol = new Solution();
    string str = sol->longestPalindrome(s);
    cout << str << endl;
    return 0;
}


