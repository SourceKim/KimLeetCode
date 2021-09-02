/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.31%)
 * Likes:    5021
 * Dislikes: 729
 * Total Accepted:    507.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

#include "helper/helper.hpp"

/* 注意时间复杂度是 O(log(m+n))

    方法一：

    给定两个 **已经排序的数组**，找到中位数，这个问题可以转化为：

    把两个数组合并起来，得到 len=m+n 的数组 mArr，找到第 k=len/2 小的值 （如果 len 是偶数，则是中间两个数的平均值），即：

    res = (len % 2 == 0) ? (mArr[k] + mArr[k+1]) / 2 : mArr[k]

    因为找到 k 之后，k+1 也呼之欲出，因此问题转化成了：
    
    找到两个数组中第 k 小的数！

    比如两个数组：

    1 2 4 6 8 9 10 len=7

    3 5 7 11 len=4

    mArr = 1 2 3 4 5 6 7 8 9 10 11 len=11

    问题就变成了：找到上面两个数组中第 k=len/2=11/5=5，mArr[5]=6

    由于我们不能直接合并数组再排序，因此不能直接得到 mArr，所幸题目的数组是已经排序好了的，因此可以使用 "删减法"，每次删除一些肯定不是第 5 个的元素，然后得两个数组中 K/2 位置更小的值，前面的值都可以移除掉（反证法）。

    方法二：

    使用二分查找分割点：

    要知道，中位数的含义：就是数组左边子数组和右边子数组的长度相等。

    arr1: 1 2 4 6 8 9 10 len1=7

    arr2: 3 5 7  len2=3

    由上可得合并后的数组左边子数组和右边子数组都是 5 个数字。

    设两个分割线 p1 & p2，为 arr1 & arr2 各自的分割点：

    这样组成左边的数组就是对于 arr1[0, p1) + arr2[0, p2)，右边就是 arr1[p1, len1) + arr2[p2, len2)

    对于这题而言，p1=3, p2=2

    arr1: 1 2 4 6 8 9 10
                p1

    arr2: 3 5 7
              p2

    左边就是 1 2 4 3 5 右边是 6 8 9 10 7

    可以看出，满足条件的 p1 & p2 符合下面定律：

    - 1. p1+p2 = (len1 + len2) / 2 分割点之和为总长度的一半
    - 2. arr1[p1-1] < arr2[p2] 数组 1 的左子数组的最大值小于数组 2 的右子数组的最小值 
    - 3. arr1[p1] > arr2[p2-1] 数组 1 的右子数组的最小值大于数组 2 的左子数组的最大值

    此时中位数就是：(max(arr1[p1-1], arr2[p2-1]) + min(arr1[p1], arr2[p2])) / 2
    即，左子数组的最大值与右子数组的最小值之和的一半。

    （上面是总长度为偶数的 case） 如果是奇数，则 min(arr1[p1], arr2[p2])，取分割点的最小值即可

    由定律 a 可得：只要知道 p1 or p2，那么中位数就知道了。
    
    然后我们使用二分法递归寻找较短数组即可，为什么要较长的？

    如果指向了一个不存在的位置，假设是左边数组的值。直接让其为 INT_MIN，右边就 INT_MAX 即可。
*/

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();

        if (len1 > len2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int i = 0;
        int j = len1;
        while (i <= j)
        {
            int p1 = (i + j) / 2;
            int p2 = (len1 + len2) / 2 - p1;

            int left1 = (p1 > 0) ? nums1[p1 - 1] : INT_MIN; // 数组 1 的分割点左边子数组的最大值
            int right1 = (p1 < len1) ? nums1[p1] : INT_MAX; // 数组 1 的分割点右边子数组的最小值
            int left2 = (p2 > 0) ? nums2[p2 - 1] : INT_MIN; // 数组 2 的分割点左边子数组的最大值
            int right2 = (p2 < len2) ? nums1[p2] : INT_MAX; // 数组 2 的分割点右边子数组的最小值

            // 满足条件，先返回了
            if (left1 <= right2 && right1 >= left2) { // 数组 1 的左子数组的最大值小于数组 2 的右子数组的最小值  && 数组 1 的右子数组的最小值大于数组 2 的左子数组的最大值 {
                if ((len1 + left2) % 2 == 0) { // 偶数
                    return (max(left1, left2) + min(right1, right2)) / 2.f;
                } else { // 奇数
                    return min(right1, right2);
                }
            }

            // 不满足条件，调整一下 i & j （二分）
            if (left1 > right2) { // 数组 1 的左边最大，大于数组 2 的右边最小了
                i = p1 - 1;
            } else {
                j = p1 + 1;
            }
        }
        
        return 0;
        
    }
};

// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> n1 = { 1, 3 };
    vector<int> n2 = { 2 };
    Solution *sol = new Solution();
    double res = sol->findMedianSortedArrays(n1, n2);
    cout << res << endl;
    return 0;
}
