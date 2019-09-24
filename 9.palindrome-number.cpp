/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (44.92%)
 * Likes:    1633
 * Dislikes: 1381
 * Total Accepted:    681.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */

// #include <stdio.h>
// #include <iostream>

// using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        // 个位数 or 0 为 true， 小于 0 为 false
        if (x < 10) {
            return x >= 0;
        }

        // 小于 100 （只有两位
        if (x < 100) {

            return x / 10 == x % 10;
        }

        // 计算出最高位是 10 的多少倍
        int maxScale = 10;
        int xCopy = x;
        while (xCopy / 10 / maxScale > 0)
        {
            maxScale *= 10;
            
        }

        // 判断是否是回文
        int minScale = 10;
        while (minScale <= maxScale)
        {
            int tail = xCopy % 10; // 末位
            int head = xCopy / maxScale; // 首位

            // cout << tail << endl;
            // cout << head << endl;

            if (tail != head) {
                return false;
            }

            xCopy -= head * maxScale; // 去除首位
            xCopy /= 10; // 去除末位

            maxScale /= 100;

            // cout << xCopy << endl;
            // cout << maxScale << endl;
        }
        
        return true;
        
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution *sol = new Solution();
//     bool res = sol->isPalindrome(12321);
//     cout << res << endl;
//     return 0;
// }




