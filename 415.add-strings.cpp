/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (44.84%)
 * Likes:    790
 * Dislikes: 237
 * Total Accepted:    160.7K
 * Total Submissions: 345.5K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {

        string res = "";

        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        int r1 = 0, r2 = 0, sum = 1;

        while ( i >= 0 || j >= 0 )
        {
            r1 = i >= 0 ? num1[i] - '0' : 0;
            r2 = j >= 0 ? num2[j] - '0' : 0;
            sum = r1 + r2 + carry;

            res.insert(res.begin(), sum % 10 + '0');
            carry = sum / 10;

            i--;
            j--;
        }
        
        if (carry != 0) {
            res.insert(res.begin(), carry + '0');
        }
        return res;
        
    }
};
// @lc code=end

