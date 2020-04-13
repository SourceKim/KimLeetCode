/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (28.86%)
 * Likes:    6386
 * Dislikes: 367
 * Total Accepted:    1.1M
 * Total Submissions: 3.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        /* 
        pos 的作用是：记录字符最后出现的位置
        key - 字符 
        value - 最后出现的位置 (-1 为从未出现)
         */
        vector<int> pos(256, -1);

        int left = -1; // 左边指针

        int maxLength = 0; // 最长长度

        for (int right = 0; right < s.length(); right++) { // 遍历每个字符

            /* 
                当前字符出现过 - 更新 left 到当前字符
                当前字符没出现过 - 不更新 left 的位置 （left 最小为 0， pos 初始化全是 -1
             */
            left = max(left, pos[s[right]]); 

            /* 
                记录当前字符出现的 pos
             */
            pos[s[right]] = right;

            /* 
                更新最大长度
             */
            maxLength = max(maxLength, right - left);

        }

        return maxLength;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();

    string s = "abcabcbb";

    int length = sol->lengthOfLongestSubstring(s);

    cout << length << endl;
    
    return 0;
}


