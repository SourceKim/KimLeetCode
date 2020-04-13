/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.14%)
 * Likes:    1621
 * Dislikes: 1475
 * Total Accepted:    546.8K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string str = "";
        
        if (strs.empty()) {
            return str;
        }

        string first = strs[0];

        if (first.empty()) {
            return str;
        }

        if (first.size() == 1 && strs.size() == 1) {
            return first;
        }

        int pos = 0;

        while (true)
        {
            
            char base = first[pos];
            for (int i = 1; i < strs.size(); i++) {
                if (pos > strs[i].size() || strs[i][pos] != base) {
                    return str;
                }
            }

            str += base;

            pos++;
        }

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<string> input {"dog","racecar","car"};
    Solution *sol = new Solution();
    string res = sol->longestCommonPrefix(input);
    cout << res << endl;
    return 0;
}

