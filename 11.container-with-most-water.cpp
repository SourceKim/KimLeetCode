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

// #include <vector>
// #include <stdio.h>
// #include <iostream>
// using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxContainer = 0;

        for (int i=0; i<height.size() - 1; i++) {

            for (int j=i + 1; j<height.size(); j++) {

                int h0 = height[i];
                int h1 = height[j];
                int minH = h0 > h1 ? h1 : h0;
                int currentContain = (j - i) * minH;
                
                if (currentContain > maxContainer) {
                    maxContainer = currentContain;
                }
            }
        }

        return maxContainer;
    }
};

// int main(int argc, char const *argv[])
// {
//     int l[] = {1,8,6,2,5,4,8,3,7};
//     vector<int> v (l, l+9);
//     Solution *sol = new Solution();
//     int res = sol->maxArea(v);
//     cout << res << endl;
//     return 0;
//     return 0;
// }


