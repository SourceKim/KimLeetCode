/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.96%)
 * Likes:    1435
 * Dislikes: 61
 * Total Accepted:    259.9K
 * Total Submissions: 567.7K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, tmp);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, int idx, vector<int> &tmp) {

        res.push_back(tmp);

        for (int i = idx; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            backtrack(nums, i + 1, tmp);
            tmp.pop_back();

            // 去重
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
            
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> nums = { 1, 2, 2 };
    Solution* sol = new Solution();
    vector<vector<int>> res = sol->subsetsWithDup(nums);

    for (int i=0; i<res.size(); i++) {

        vector<int> v = res[i];

        for (int j=0; j<v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}
