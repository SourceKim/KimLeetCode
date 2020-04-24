/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (28.66%)
 * Likes:    1243
 * Dislikes: 2763
 * Total Accepted:    426.8K
 * Total Submissions: 1.5M
 * Testcase Example:  '2.00000\n10'
 *
 * Implement pow(x, n), which calculates x raised to the power n (x^n).
 * 
 * Example 1:
 * 
 * 
 * Input: 2.00000, 10
 * Output: 1024.00000
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2.10000, 3
 * Output: 9.26100
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 2.00000, -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 
 * Note:
 * 
 * 
 * -100.0 < x < 100.0
 * n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]
 * 
 * 
 */

// @lc code=start
/* 
    求一个数的平方：

    使用 二分法 + 递归 实现

    性质： 
        x^n = x^2^(n/2) = (x * x)^(n/2)

        但是如果 n 是奇数或者负数处理不一样，见 `边界处理`

    递归出口:
         n = 0 -> 1
         n = 1 -> x

    边界处理：

        如果 n 是奇数，应该要多乘一个 x, 如 x^5 = (x * x)^(5/2) * x，因为 5 整除 2 是 2
        如果 n 是负数，则应该 n = -n，x = 1/x，如 3^(-2) = 1/(3^2)

    trick:

        如果 n 是负数， n = -n 会溢出，因为 n : [−2^31, 2^31 − 1]
        所以有个小技巧，先除以 2，在 -n
 */
class Solution {
public:
    double myPow(double x, int n) {
        
        if (n == 0) return 1;
        if (n == 1) return x;

        int pf = n / 2; // trick: 先除以 2，防止溢出

        // 处理负数
        if (n < 0) {
            pf = -pf;
            x = 1 / x;
        }

        double res = myPow(x, pf);

        // 处理偶数奇数
        if (n % 2 == 0) {
            return res * res;
        } else {
            return res * res * x;
        }
    }
};
// @lc code=end

