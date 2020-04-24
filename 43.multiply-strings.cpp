/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (31.76%)
 * Likes:    1532
 * Dislikes: 704
 * Total Accepted:    269.1K
 * Total Submissions: 816.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

using std::vector;
using std::string;

/*
 89 * 69

 89
 69
 --------
        81
       72
       54
      48
----------
    6141


    1. 先初始化一个容器 vals，来保存结果

    2. 从后遍历两个字符串，i j

    4. 每次遍历算得：
        p1 = i + j 这一轮计算的前一位
        p2 = i + j + 1 这一轮的计算的位

        res = num1[i] * num[j] 当前这两个相乘

        res += nums[p2] // 还要加上上一次的结果

        vals[p2] = res % 10 // 这次要留下的值
        vals[p1] += res / 10 前一位要加上的值 
    
*/

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) { 
        
        string res = "";
        int size1 = num1.size();
        int size2 = num2.size();

        vector<int> vals(size1 + size2);

        for (int i = size1 - 1; i >= 0; i--) { // 从后遍历
            for (int j = size2 - 1; j >= 0; j--) { // 从后遍历
                int mul = (num1[i] - '0') * (num2[j] - '0'); // 获取相乘的结果
                int p1 = i + j; // 前一位 （存要进位的数，好下一次相加）
                int p2 = i + j + 1; // 当前位
                int sum = mul + vals[p2]; // 这次计算出来的总结果 （算上上次的结果）

                vals[p1] += sum / 10; // 把进位保存
                vals[p2] = sum % 10;  // 把当前位保存

                // cout << i << " " << j << " " << sum << endl;
            }
        }

        for (int val : vals) {
            if ( !res.empty() || val != 0 ) {
                res.push_back(val + '0');
            }
        }

        return res.empty() ? "0" : res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    string res = sol->multiply("89", "69");
    std::cout << res << std::endl;
    return 0;
}
