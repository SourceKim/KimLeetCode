/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.87%)
 * Likes:    1119
 * Dislikes: 51
 * Total Accepted:    256.3K
 * Total Submissions: 584.2K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        set<vector<int>> res; // 用 set 去重
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        backtrack(0, target, candidates, res, path);

        vector<vector<int>> vRes (res.begin(), res.end());
        return vRes;
        
    }

private:
    void backtrack(int k, int rest, vector<int> candidates, set<vector<int>>& res, vector<int> path) {

        if (rest <= 0) {
            if (rest == 0) {
                res.insert(path);
            }
            return;
        }

        for (int i=k; i<candidates.size(); i++) {

            int num = candidates[i];
            int r = rest - num;

            if (r >= 0) {

                path.push_back(num);
                backtrack(i+1, r, candidates, res, path);
                path.pop_back();
            } else {
                return;
            }
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> nums = { 10,1,2,7,6,1,5 };
    int target = 8;

    Solution *sol = new Solution();
    vector<vector<int>> res = sol->combinationSum2(nums, target);

    for (int i=0;i<res.size(); i++) {
        vector<int> v = res[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}