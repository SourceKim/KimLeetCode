/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (36.97%)
 * Likes:    1323
 * Dislikes: 3101
 * Total Accepted:    423.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
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
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int p1 = m - 1;
        int p2 = n - 1;

        // 从后遍历，倒数第二个数开始，到 0
        for (int i = m + n - 1; i>=0; i--) {

            // cout << p1 << " ++ " << p2 << endl;

            // cout << nums1[p1] << " == " << nums2[p2] << endl;

            if (p1 < 0) {
                // cout << "a" << endl;
                nums1[i] = nums2[p2];
                p2--;
            } else if (p2 < 0) {
                // cout << "b" << endl;
                nums1[i] = nums1[p1];
                p1--;
            } else {
                // cout << "c" << endl;
                if (nums1[p1] > nums2[p2]) {
                    nums1[i] = nums1[p1];
                    p1--;
                } else {
                    nums1[i] = nums2[p2];
                    p2--;
                }
            }

        }
    }
};

// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> n1 = { 1,2,3,0,0,0 };
    vector<int> n2 = { 2,5,6 };

    Solution *sol = new Solution();
    sol->merge(n1, 3, n2, 3);

    for (int i=0; i<6; i++) {
        cout << n1[i] << endl;
    }
    return 0;
}

