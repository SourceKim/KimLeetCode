/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (51.10%)
 * Likes:    2525
 * Dislikes: 75
 * Total Accepted:    405.3K
 * Total Submissions: 792.6K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
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
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
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
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        backtracking(candidates, target, 0, tmp);

        return res;
    }

private:

    vector<vector<int>> res;

    // nums 解空间
    // target 本次搜索的目标值
    // idx 本次搜索在解空间的位置
    // tmp 本次搜索的值
    void backtracking(vector<int> &nums, int target, int idx, vector<int> &tmp) {

        // 递归出口，target <= 0
        if (target < 0) return;
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        // 遍历后面的
        for (int i = idx; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtracking(nums, target - nums[i], i, tmp);
            tmp.pop_back();
        }


    }
   
};
// @lc code=end
int main(int argc, char const *argv[])
{
    vector<int> nums = { 2, 3, 6, 7, };
    int target = 7;

    Solution *sol = new Solution();
    vector<vector<int>> res = sol->combinationSum(nums, target);

    for (int i=0;i<res.size(); i++) {
        vector<int> v = res[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}

