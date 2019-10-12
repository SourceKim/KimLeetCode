/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.80%)
 * Likes:    2526
 * Dislikes: 82
 * Total Accepted:    448K
 * Total Submissions: 774.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
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
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        int size = nums.size();

        backtrace(0, size, nums, res);

        return res;
    }

private:
    void backtrace(int k, int n, vector<int>& nums, vector<vector<int>>& res) {

        cout << "==== k=" << k << " ====" << endl;

        // for (int j=0; j<nums.size(); j++) {
        //     cout << nums[j];
        // }
        // cout << endl;

        if (k >= n) {
            cout << " ++++ rtn0 ++++" << endl;
            res.push_back(nums);
            return;
        } 

        for (int i=k; i<nums.size(); i++) {
            cout << "k=" << k << " == i=" << i << endl;
            swap(nums[k], nums[i]);
            backtrace(k+1, n, nums, res);
            swap(nums[k], nums[i]);
        }
        cout << " ++++ k=" << k << " rtn1 ++++ " << endl;
        return;
    }

    void swap(int& a, int& b) {

        int tmp = a;
        a = b;
        b = tmp;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    vector<int> nums = { 1, 2, 3,};

    Solution *sol = new Solution();
    vector<vector<int>> res = sol->permute(nums);

    for (int i=0;i<res.size(); i++) {
        vector<int> v = res[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j];
        }
        cout << endl;
    }
    return 0;
}

