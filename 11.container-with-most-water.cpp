/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (46.72%)
 * Likes:    3960
 * Dislikes: 473
 * Total Accepted:    450.8K
 * Total Submissions: 963.6K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

// @lc code=start
/* 
    定义两个指针 i j 分别指向两边

    最大容水量 = min(h[i], h[j]) * (j - i)

    每次移动小的那头，直到相遇即可
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxContainer = 0;

        int i = 0, j = height.size() - 1;

        while (i < j)
        {
            maxContainer = max(min(height[i], height[j]) * (j - i), maxContainer);

            height[i] < height[j] ? i++ : j--;
        }
        

        return maxContainer;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    int l[] = {1,8,6,2,5,4,8,3,7};
    vector<int> v (l, l+9);
    Solution *sol = new Solution();
    int res = sol->maxArea(v);
    cout << res << endl;
    return 0;
    return 0;
}


