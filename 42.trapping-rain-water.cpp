/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (45.06%)
 * Likes:    4653
 * Dislikes: 82
 * Total Accepted:    364K
 * Total Submissions: 804.8K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 当前位置可以接的雨水 = 左右两边最高的墙壁较小的高度 - 当前位置的高度

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {

        int h = height.size();

        if (h == 0) {
            return 0;
        }

        int sum = 0;

        // 对于每一个元素来说，左右边的最大高度
        vector<int> maxLeft(h), rightMax(h);
 
        int curMax = 0; // 当前位置的最大值 (包含自身)

        // 找到左边最大值
        for (int i=0; i<h; i++) {
            curMax = max(curMax, height[i]);
            maxLeft[i] = curMax;
        }

        curMax = 0;
        // 找到右边最大值
        for (int i=h-1; i>=0; i--) {
            curMax = max(curMax, height[i]);
            rightMax[i] = curMax;
        }

        // 计算高度
        for (int i=0; i<h; i++) {
            // cout << maxLeft[i] << " = " << rightMax[i] << endl;
            sum += min(maxLeft[i], rightMax[i]) - height[i];
        }
        
        return sum;
        
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    vector<int> v = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    Solution *sol = new Solution(); 
    int res = sol->trap(v);
    return 0;
}

