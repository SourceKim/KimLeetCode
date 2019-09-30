/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (55.24%)
 * Likes:    2397
 * Dislikes: 87
 * Total Accepted:    533.1K
 * Total Submissions: 964.9K
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an array nums, write a function to move all 0's to the end of it while
 * maintaining the relative order of the non-zero elements.
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * 
 * Note:
 * 
 * 
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 * 
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int zeroPtr = 0;

        for (int i=0; i<nums.size(); i++) {

            if (nums[i] != 0) {
                // 交换位置
                int tmp = nums[zeroPtr];
                nums[zeroPtr] = nums[i];
                nums[i] = tmp;
                // 更新指针
                zeroPtr++;
            }
        }
        
    }
};
// @lc code=end

