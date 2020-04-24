/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (50.24%)
 * Likes:    3228
 * Dislikes: 227
 * Total Accepted:    566.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// @lc code=start
/* 
    应用堆排序
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int len = nums.size();

        for (int i = len - 1; i >= 0; i--) {
            heapAdjustBigAtTop(nums, i, len);
        }

        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[len - 1 - i]);
            heapAdjustBigAtTop(nums, 0, len - 1 - i);
        }

        return nums[0];
    }
private:
    void heapAdjustBigAtTop(vector<int> &nums, int start, int len) {

        int tmp = nums[start];

        for (int i = start * 2 + 1; i < len; i = i * 2 + 1) {

            if (i + 1 < len && nums[i + 1] > nums[i]) i++;

            if (nums[i] < tmp) break;

            nums[start] = nums[i];
            start = i;
        }

        nums[start] = tmp;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> input {2,3,1,2,4,5,5,6};
    Solution *sol = new Solution();
    int res = sol->findKthLargest(input , 4);
    cout << res;
    return 0;
}


