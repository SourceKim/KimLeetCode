/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.30%)
 * Likes:    3399
 * Dislikes: 160
 * Total Accepted:    708K
 * Total Submissions: 1.9M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for (int i=0; i<s.length(); i++) {
            char c = s[i];
            if (c == '[' || c == '{' || c == '(') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    char top = st.top();
                    if ((top == '[' && c == ']') || (top == '(' && c == ')') || (top == '{' && c == '}')) {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        return st.empty();
    }
};

