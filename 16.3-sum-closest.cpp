/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.74%)
 * Likes:    1355
 * Dislikes: 98
 * Total Accepted:    384.5K
 * Total Submissions: 840.6K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
// #include <stdio.h>
// #include <iostream>
// #include <stack>
// #include <vector>

// using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // 先排序，排序后就变成 [一堆负数, 0, 一堆正数]
        sort(nums.begin(), nums.end()); 

        int closet = nums[0] + nums[1] + nums[2];
        // 当前差值 (取前三个)
        int dif = abs(closet - target);

        // 逐个数取出来对比
        for (int i=0; i<nums.size() - 1; i++) {

            int head = i + 1;
            int tail = nums.size() - 1;

            while (head < tail)
            {
                int sum = nums[i] + nums[head] + nums[tail];
                int newDif = abs(sum - target);

                // 如果这一组更加近，就更新保存的值
                if (newDif < dif) {
                    dif = newDif;
                    closet = sum;
                }

                // 如果不够就头指针移动，否则移动尾指针
                if (sum < target) {
                    head++;
                } else {
                    tail--;
                }
            }
            
        }

        return closet;

    }
};

// int main(int argc, char const *argv[])
// {

//     vector<int> vec {-1,2,1,-4};

//     Solution *sol = new Solution();
//     int res = sol->threeSumClosest(vec, 1);
//     cout << res << endl;
//     return 0;
// }

