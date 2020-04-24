/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (50.19%)
 * Likes:    969
 * Dislikes: 56
 * Total Accepted:    232.5K
 * Total Submissions: 463.1K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
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
    /* 
        从 1 ~ n 中找出取 k 个数字组合
     */
public:
    vector<vector<int>> combine(int n, int k) {

        vector<int> tmp;
        backtrack(1, k, n, tmp);
        return res;
        
    }
private:
    vector<vector<int>> res;

    void backtrack(int cur, int k, int n, vector<int> &tmp) {

        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        for (int i = cur; i <= n; i++) {
            tmp.push_back(i);
            backtrack(i + 1, k, n, tmp);
            tmp.pop_back();
        }

    }
};
// @lc code=end
int main(int argc, char const *argv[]) {

    Solution *sol = new Solution();
    vector<vector<int>> res = sol->combine(4, 2);

    for (int i=0;i<res.size(); i++) {
        vector<int> v = res[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}
