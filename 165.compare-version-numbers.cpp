/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 *
 * https://leetcode.com/problems/compare-version-numbers/description/
 *
 * algorithms
 * Medium (31.41%)
 * Likes:    893
 * Dislikes: 1763
 * Total Accepted:    253.6K
 * Total Submissions: 806.7K
 * Testcase Example:  '"1.01"\n"1.001"'
 *
 * Given two version numbers, version1 and version2, compare them.
 * 
 * 
 * 
 * 
 * Version numbers consist of one or more revisions joined by a dot '.'. Each
 * revision consists of digits and may contain leading zeros. Every revision
 * contains at least one character. Revisions are 0-indexed from left to right,
 * with the leftmost revision being revision 0, the next revision being
 * revision 1, and so on. For example 2.5.33 and 0.1 are valid version
 * numbers.
 * 
 * To compare version numbers, compare their revisions in left-to-right order.
 * Revisions are compared using their integer value ignoring any leading zeros.
 * This means that revisions 1 and 001 are considered equal. If a version
 * number does not specify a revision at an index, then treat the revision as
 * 0. For example, version 1.0 is less than version 1.1 because their revision
 * 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
 * 
 * Return the following:
 * 
 * 
 * If version1 < version2, return -1.
 * If version1 > version2, return 1.
 * Otherwise, return 0.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: version1 = "1.01", version2 = "1.001"
 * Output: 0
 * Explanation: Ignoring leading zeroes, both "01" and "001" represent the same
 * integer "1".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: version1 = "1.0", version2 = "1.0.0"
 * Output: 0
 * Explanation: version1 does not specify revision 2, which means it is treated
 * as "0".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: version1 = "0.1", version2 = "1.1"
 * Output: -1
 * Explanation: version1's revision 0 is "0", while version2's revision 0 is
 * "1". 0 < 1, so version1 < version2.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: version1 = "1.0.1", version2 = "1"
 * Output: 1
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: version1 = "7.5.2.4", version2 = "7.5.3"
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= version1.length, version2.length <= 500
 * version1 and version2 only contain digits and '.'.
 * version1 and version2 are valid version numbers.
 * All the given revisions in version1 and version2 can be stored in a 32-bit
 * integer.
 * 
 * 
 */

#include "helper/helper.hpp"

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {

        int len1 = version1.size();
        int len2 = version2.size();

        int p1 = 0, p2 = 0;

        int res = 0;

        while (p1 < len1 || p2 < len2)
        {
            int sum1 = 0, sum2 = 0;

            while (p1 < len1 && version1[p1] != '.')
            {
                sum1 = sum1 * 10 + (version1[p1] - '0');
                p1++;
            }
            
            while (p2 < len2 && version2[p2] != '.')
            {
                sum2 = sum2 * 10 + (version2[p2] - '0');
                p2++;
            }

            // 后面的不需要比了
            if (sum1 > sum2) return 1;
            if (sum1 < sum2) return -1;

            p1++;
            p2++;
        }

        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    string v1 = "7.5.2.4";
    string v2 = "7.5.3";
    Solution *sol = new Solution();
    int res = sol->compareVersion(v1, v2);
    cout << res << endl;
    return 0;
}


