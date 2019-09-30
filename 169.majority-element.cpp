/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.28%)
 * Likes:    1997
 * Dislikes: 174
 * Total Accepted:    440.5K
 * Total Submissions: 811.4K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // 投票算法
        // 由于只有一个 majority element，因此可以通过不断消除不同的元素，剩下的就是主元素了

        int majorityElement = nums[0]; // 主元素
        int count = 1; // 计数

        for (int i=1; i<nums.size(); i++) {

            if (count == 0) { // 当前认为的主元素计数为 0，则不可将他认为是主元素了
                majorityElement = nums[i];
            }

            if (majorityElement == nums[i]) {
                count++;
            } else {
                count--;
            }
        }

        return majorityElement;
    }
};
// @lc code=end

