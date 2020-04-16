/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * 
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (43.35%)
 * Likes:    2009
 * Dislikes: 174
 * Total Accepted:    361.3K
 * Total Submissions: 833.1K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
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

/* 
    定义头尾指针 head tail

    用 i 遍历数组

    如果 i == 0，让 i 位置和 head 交换一下，然后 head++
    如果 i == 2，让 i 位置和 tail 交换一下，然后 tail++
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {

        // 头尾指针
        int head = 0;
        int tail = nums.size() - 1;

        for (int i=0; i<=tail; i++) { // 到 tail 就结束

            // 先找到 0，再去找 2。找到之后都交换一下位置

            if (nums[i] == 0) {
                cout << "a == " << i << " ==" << head << endl;  
                nums[i] = nums[head];
                nums[head] = 0;
                head++;
            } else if (nums[i] == 2) {
                cout << "b == " << i << " ==" << tail << endl;  
                nums[i] = nums[tail];
                nums[tail] = 2;
                tail--;

                // 换到 i 位置的这个数字，还没有去比较过，所以下一个循环依然是当前的 i
                i--;
            }
        }
        
    }
};
// @lc code=end

