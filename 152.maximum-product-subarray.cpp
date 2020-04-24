/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.19%)
 * Likes:    3484
 * Dislikes: 141
 * Total Accepted:    303.9K
 * Total Submissions: 978.5K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// @lc code=start

#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxVal = nums[0];

        int tmpMax = maxVal;
        int tmpMin = maxVal;

        for (int i = 1; i < nums.size(); i++) {

            int tm = tmpMax, tn = tmpMin;

            int cur = nums[i];

            tmpMax = max3(cur, cur * tm, cur * tn);
            tmpMin = min3(cur, cur * tm, cur * tn);

            maxVal = max(tmpMax, maxVal);
        }

        return maxVal;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> input { 0,2 };
    Solution *sol = new Solution();
    int res = sol->maxProduct(input);
    cout << res << endl;
    return 0;
}


