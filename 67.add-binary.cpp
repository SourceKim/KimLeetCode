/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (40.69%)
 * Likes:    1172
 * Dislikes: 220
 * Total Accepted:    344.1K
 * Total Submissions: 844.3K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {

        string res = "";

        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0, sum = 0;
        while (i >= 0 || j >= 0) {

            int c0 = i >= 0 ? a[i--] - '0' : 0;
            int c1 = j >= 0 ? b[j--] - '0' : 0;

            sum = c0 + c1 + carry;
            
            carry = sum <= 1 ? 0 : 1;
            res = (sum == 0 || sum == 2 ? '0' : '1') + res;
        }

        if (carry == 1) res = '1' + res;
        
        return res.empty() ? "0" : res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    string res = sol->addBinary("11", "1");
    cout << res << endl;
    return 0;
}
