/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 *
 * https://leetcode.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (64.24%)
 * Likes:    1192
 * Dislikes: 646
 * Total Accepted:    642.9K
 * Total Submissions: 971.2K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * Write a function that reverses a string. The input string is given as an
 * array of characters char[].
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * You may assume all the characters consist of printable ascii
 * characters.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["h","e","l","l","o"]
 * Output: ["o","l","l","e","h"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["H","a","n","n","a","h"]
 * Output: ["h","a","n","n","a","H"]
 * 
 * 
 * 
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
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;

        char tmp;
        while (i < j)
        {
            tmp = s[i]; 
            s[i++] = s[j];
            s[j--] = tmp; 
        }
        
    }
};
// @lc code=end

