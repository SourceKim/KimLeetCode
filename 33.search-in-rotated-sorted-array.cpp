/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.66%)
 * Likes:    9160
 * Dislikes: 725
 * Total Accepted:    1.1M
 * Total Submissions: 3M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * There is an integer array nums sorted in ascending order (with distinct
 * values).
 * 
 * Prior to being passed to your function, nums is rotated at an unknown pivot
 * index k (0 <= k < nums.length) such that the resulting array is [nums[k],
 * nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
 * For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become
 * [4,5,6,7,0,1,2].
 * 
 * Given the array nums after the rotation and an integer target, return the
 * index of target if it is in nums, or -1 if it is not in nums.
 * 
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * 
 * Example 1:
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * Example 2:
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * Example 3:
 * Input: nums = [1], target = 0
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5000
 * -10^4 <= nums[i] <= 10^4
 * All values of nums are unique.
 * nums is guaranteed to be rotated at some pivot.
 * -10^4 <= target <= 10^4
 * 
 * 
 */

#include "helper/helper.hpp"

/*

题目：升序数组，某个点旋转 O（n）

问题：我们不知道在哪个点旋转了

对于 0 1 2 4 5 6 7 有如下旋转：
      m
0 1 2 4 5 6 7
7 0 1 2 4 5 6
6 7 0 1 2 4 5 
5 6 7 0 1 2 4 
4 5 6 7 0 1 2 
2 4 5 6 7 0 1 
1 2 4 5 6 7 0 

观察得，当 m < arr[0] ，右边升序，反之左边升序

这样就可以确定在哪一半去查找 target 了，怎么确定？

通过判断有序的首尾值，看看 target 是否在区间中就可以了
*/

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        // 二分查找法


        int i = 0, j = nums.size() - 1; //  (左右指针)

        while (i <= j)
        {
            int mid = (i + j) / 2;

            if (nums[mid] == target) return mid;
            if (nums[i] == target) return i;
            if (nums[j] == target) return j;

            if (mid + 1 >= nums.size() || mid - 1 < 0) return -1;

            if (nums[mid] < nums[0]) { // 此时 mid 的右边升序

                if (target > nums[mid] && target < nums[j]) { // 在右边区间
                    i = mid + 1;
                } else {
                    j = mid - 1;
                }
            } else { // 此时 mid 的左边升序
                if (target > nums[i] && target < nums[mid]) { // 在左边区间
                    j = mid - 1;
                } else {
                    i = mid + 1;
                }
            }
        }
        
        return -1;

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{

    vector<int> nums =  { 4,5,6,7,0,1,2 };

    int res;

    Solution *sol = new Solution();
    // res = sol->search(nums, 4);
    // cout << res << endl;

    nums = {3 , 1};
    res = sol->search(nums, 4);
    cout << res << endl;
    
    return 0;
}
