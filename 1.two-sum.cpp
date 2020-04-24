/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.62%)
 * Likes:    14342
 * Dislikes: 525
 * Total Accepted:    2.8M
 * Total Submissions: 6.1M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

// @lc code=start
/* 
    每次遍历将数字用字典存起来
    遍历到第 n 个看是否存在即可
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {

            if (map.find(target - nums[i]) != map.end()) {
                return { i, map[target - nums[i]] };
            }

            map[nums[i]] = i;
        }

        return {};
    }
};
// @lc code=end

