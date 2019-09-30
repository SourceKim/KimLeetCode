/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (32.62%)
 * Likes:    2431
 * Dislikes: 230
 * Total Accepted:    310K
 * Total Submissions: 950K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {

        // 注意，每个 nums 的数字表示最多能走多少步

        int maxDistance = nums[0]; // 最大距离

        // 遍历首个数字能到达的位置
        for (int i=0; i<=maxDistance; i++) {

            // 可行步数 大于等于 数组长度减一，算是能完成
            if (nums[i] + i >= nums.size() - 1) {
                return true;
            } else {
                maxDistance = max(maxDistance, nums[i] + i);
            }
        }

        return maxDistance >= nums.size() - 1;
    }
};

