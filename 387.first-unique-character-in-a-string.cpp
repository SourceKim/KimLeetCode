/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.77%)
 * Likes:    1620
 * Dislikes: 106
 * Total Accepted:    423.6K
 * Total Submissions: 818K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
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
    int firstUniqChar(string s) {

        vector<int> dic (26, 0);

        for (char c : s) {
            dic[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (dic[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string input = "leetcode";
    Solution *sol = new Solution();
    int res = sol->firstUniqChar(input);
    cout << res << endl;
    return 0;
}

