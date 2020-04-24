/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (18.11%)
 * Likes:    888
 * Dislikes: 2693
 * Total Accepted:    369.9K
 * Total Submissions: 1.9M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string, reverse the string word by word.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "  hello world!  "
 * Output: "world! hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * A word is defined as a sequence of non-space characters.
 * Input string may contain leading or trailing spaces. However, your reversed
 * string should not contain leading or trailing spaces.
 * You need to reduce multiple spaces between two words to a single space in
 * the reversed string.
 * 
 * 
 * 
 * 
 * Follow up:
 * 
 * For C programmers, try to solve it in-place in O(1) extra space.
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
    /* 
        假设有 "Hello World"

        1. 先整体翻转： "dlroW olleH"
        2. 再单词内翻转 "World Hello"
     */
public:
    string reverseWords(string s) {

        // 1. 整体翻转
        reverse(s.begin(), s.end());

        // 2. 局部翻转
        int idx = 0; // 代表当前单词的 index
        int len = s.size();

        for (int i=0; i<len; i++) { // 中间会跳过某些 i，以单个单词的形式

            // 不对空格处理
            if (s[i] != ' ') {

                if (idx != 0) { // 不是首个，加个空格
                    s[idx] = ' ';
                    idx++;
                }

                // 找到单个单词的区域
                int j = i;
                while (j < len && s[j] != ' ') // 找到空格为止
                {
                    // 覆盖原字符串
                    s[idx++] = s[j++];
                }

                // 翻转
                reverse(s.begin() + idx - (j - i), s.begin() + idx);

                i = j;
                
            }
        }

        cout << idx << endl;
        s.resize(idx);
        return s;
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    string res = sol->reverseWords("  hello world!  ");
    cout << res << endl;
    return 0;
}

