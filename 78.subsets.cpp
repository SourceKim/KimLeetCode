/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.59%)
 * Likes:    2440
 * Dislikes: 58
 * Total Accepted:    427.4K
 * Total Submissions: 768.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
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
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> tmp;
        backtrack(0, nums, res, tmp);

        return res;
        
    }

private:
    void backtrack(int k, vector<int> nums, vector<vector<int>>& res, vector<int>& tmp) {
        
        res.push_back(tmp);

        for (int i=k; i<nums.size(); i++) {

            tmp.push_back(nums[i]);
            backtrack(i+1, nums, res, tmp);
            tmp.pop_back();
        }
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    vector<int> nums = { 1, 2, 3 };
    Solution* sol = new Solution();
    vector<vector<int>> res = sol->subsets(nums);

    for (int i=0; i<res.size(); i++) {

        vector<int> v = res[i];

        for (int j=0; j<v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}
