/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

 /*
 1. 求出数组的和
 2. 逐个做减法剩下的就是缺少的
  */
#include "helper/helper.hpp"
#include <vector>

// @lc code=start

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum = nums.size();
        for (int i=0; i<nums.size(); i++) {
            sum += i;
            sum -= nums[i];
        }
        return sum;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> a = { 0, 1 };
    printVector(a);

    Solution *s = new Solution;
    int res = s->missingNumber(a);
    printf("res: %d", res);

    return 0;
}