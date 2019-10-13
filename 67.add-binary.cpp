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

        string::reverse_iterator iter0 = a.rbegin();
        string::reverse_iterator iter1 = b.rbegin();

        string res = string();

        bool needCarry = false;
        while (iter0 != a.rend() || iter1 != b.rend())
        {
            char c;
            bool nextNeedCarry = false;

            if (iter0 == a.rend()){
                
                c = *iter1;
                iter1++;

            } else if (iter1 == b.rend()) {

                c = *iter0;
                iter0++;

            } else {

                if (*iter0 == *iter1) {

                    cout << "a" << endl;

                    if (*iter1 == '0') {

                        c = '0';

                    } else {

                        c = '0';
                        nextNeedCarry = true;

                    }

                } else {
                    cout << "d" << endl;
                    c = '1';
                }

                iter0++;
                iter1++;

            }

            if (needCarry) {

                if (c == '1') {
                    c = '0';
                    nextNeedCarry = true;
                } else {
                    c = '1';
                }
            }
            cout << c << endl;
            needCarry = nextNeedCarry;
            res.insert(res.begin(), c);            
        }

        if (needCarry) {
            res.insert(res.begin(), '1');
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    string res = sol->addBinary("1010", "1011");
    cout << res << endl;
    return 0;
}
