/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.83%)
 * Likes:    4583
 * Dislikes: 530
 * Total Accepted:    655.4K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
// @lc code=start
/* 
    1. 先对数组进行排序

    2. 遍历每一个数 i

    3. 设定 j = i + 1 指向 i 的下一个
       设定 k = nums.size() 指向最后
       设定 target = 0 - nums[i] 为我们要找到的 i & k 之和

    4. while （j < k） 直到指针相遇

    5. while 中判断：
        a 如果 j & k 的数字 == target 则继续寻找其他组合，所以 j++ k-- （此时要注意处理重复）
        b 如果 还小于 target，则增大，所以是 j++
        c 如果 已经大于 target，则因减小，所以是 k--
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> v;

        // 先排序，排序后就变成 [一堆负数, 0, 一堆正数]
        sort(nums.begin(), nums.end());

        // 如果 nums 的最后一个数都小于 0，则不可能存在（因为没有正数）
        if (!nums.empty() && nums.back() < 0) {
            return v;
        }

        // 遍历 nums 的 负数和 0 的部分
        for (int i=0; i<nums.size(); i++) {

            // 到正数部分就退出循环
            if (nums[i] > 0) {
                break;
            }

            // 如果这个数和上一个数一样，就不处理，因为不能有一样的
            if (i>0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // 目标数字 (也就是下面两个指针指向的数字的值之和要等于这个数字)
            int target = 0 - nums[i];

            int j = i + 1; // 从下一个数字开始 （首指针）
            int k = nums.size() - 1; // 到最后 （尾指针）

            // 开始移动两个指针，直到相遇或者错过
            while (j < k)
            {

                if (nums[j] + nums[k] == target) { // 和等于目标

                    // 加入到结果中
                    v.push_back({ nums[i], nums[j], nums[k] });

                    // 处理一下重复数字，直接跳过
                    while (j < k && nums[j] == nums[j + 1])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1])
                    {
                        k--;
                    }

                    // 指针一起移动
                    j++;
                    k--;

                } else if (nums[j] + nums[k] < target) { // 和还小于目标
                    j++; // 首指针移动
                } else { // 和还大于目标
                    k--;
                }
            }
        }
        return v;
    }
};
// @lc code=end
// int main(int argc, char const *argv[])
// {

//     vector<int> vec {-1, 0, 1, 2, -1, -4};

//     Solution *sol = new Solution();
//     vector<vector<int>> res = sol->threeSum(vec);
//     return 0;
// }


