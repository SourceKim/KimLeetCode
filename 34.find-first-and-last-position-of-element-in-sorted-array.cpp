/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (38.39%)
 * Likes:    6777
 * Dislikes: 226
 * Total Accepted:    792.8K
 * Total Submissions: 2.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * If target is not found in the array, return [-1, -1].
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * Example 2:
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * Example 3:
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non-decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

#include "helper/helper.hpp"

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res = { -1, -1 };

        int i = 0, j = nums.size() - 1;

        if (j < 0) return res;
        // if (i == j) return { nums[0] == target ? 0 : -1, nums[0] == target ? 0 : -1 };
        if (nums[i] > target) return res;
        if (nums[j] < target) return res;

        while (i < j)
        {
            int mid = (i + j) / 2;

            if (nums[mid] > target) {
                j = mid - 1;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else { // nums[mid] = target
                i = mid;
                j = mid;
                while (i - 1 >= 0 && nums[i - 1] == target) i--;
                while (j + 1 < nums.size() && nums[j + 1] == target) j++;
                return { i, j };
            }
        }

        if (nums[i] == target) {
            res[0] = i;
            res[1] = i;
        }
        
        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> nums = { 1, 4 };
    int target = 4;

    Solution *sol = new Solution();
    vector<int> res =  sol->searchRange(nums, target);
    printVector(res);
    return 0;
}

