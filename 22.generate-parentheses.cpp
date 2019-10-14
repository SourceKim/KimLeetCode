/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (57.50%)
 * Likes:    3428
 * Dislikes: 204
 * Total Accepted:    405.2K
 * Total Submissions: 704.7K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
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
    vector<string> generateParenthesis(int n) {
        
        vector<string> res;

        string str = "";

        backtrack(n, n, "", res);

        return res;
    }

private:
    void backtrack(int leftCount, int rightCount, string str, vector<string>& res) {

        if (leftCount == 0 && rightCount == 0) {
            res.push_back(str);
            return;
        }

        if (leftCount > rightCount) {
            return;
        }

        if (leftCount > 0) {
            string newStr = str + "(";
            backtrack(leftCount-1, rightCount, newStr, res);
        }

        if (rightCount > 0) {
            string newStr = str + ")";
            backtrack(leftCount, rightCount-1, newStr, res);
        }
        

    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    vector<string> res = sol->generateParenthesis(2);

    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}


