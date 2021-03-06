/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.68%)
 * Likes:    3083
 * Dislikes: 576
 * Total Accepted:    342.9K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
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
    bool isMatch(string s, string p) {
        
        int len = s.length();


        int pIndex = 0;

        for (int i=0; i<len; i++) {

            if (s[i] != p[pIndex]) {

                if (p[pIndex] != '.') {
                    
                    if (p[pIndex] != '*') {

                        return false;

                    } else {
                        
                        if (pIndex > 0) {
                            
                            char lastChar = p[pIndex - 1];
                            if (lastChar != s[i] && lastChar != '.') {

                                return false;
                            }
                        } else {
                            return false;
                        }
                    }
                }
            }

            pIndex++;
        }

        return true;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string s = "aa";
    string p = "a";
    Solution *sol = new Solution();
    bool res = sol->isMatch(s, p);
    cout << res << endl;
    return 0;
}

