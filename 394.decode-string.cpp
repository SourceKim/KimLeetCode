/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (53.97%)
 * Likes:    5688
 * Dislikes: 256
 * Total Accepted:    361.1K
 * Total Submissions: 668.8K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Example 1:
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * Example 2:
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * Example 3:
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * Example 4:
 * Input: s = "abc3[cd]xyz"
 * Output: "abccdcdcdxyz"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */

#include "helper/helper.hpp"

/*

    看到这种题，直接想到 栈 or 递归 了

    1. 遇到字符，直接 res += char

    2. 遇到数字，入栈 3 2

    3. 遇到 [ ，pop 一个数字 n，然后开始循环 n

    4. 遇到 ] ，写入 tmp，如果栈空了，写入 res
*/

// @lc code=start
class Solution {
public:
    string decodeString(string s) {

        string str = "";

        stack<int> numS;

        stack<string> strS;

        int cnt = 0;

        for (char c: s) {

            if (c >= '0' && c <= '9') { // 是数字
                cnt = cnt * 10 + (c - '0');
            } else if (c == '[') {
                numS.push(cnt);
                strS.push(str); // 先把之前的值压入栈，防止后面制作循环的时候影响到
                cnt = 0;
                str.clear();
            } else if (c == ']') {
                // pop 出一个数字
                int i = numS.top();
                numS.pop();

                // 制作循环的字符串
                while (i > 0) {
                    strS.top() += str; // 栈顶加上刚刚生成的字符串
                    i--;
                }

                // 制作完了就取出当前的值
                str = strS.top();
                strS.pop();

            } else { // 处理普通英文字符
                str += c;
            }
        }

        if (!strS.empty()) {
            str = strS.top();
        }

        return str;
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    string str = sol->decodeString("3[a]2[bc]");
    cout << str << endl;
    return 0;
}
