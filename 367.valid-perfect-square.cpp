/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {

        /*
        完全平方数的性质：

        1 = 1
        4 = 1 + 3
        9 = 1 + 3 + 5
        16 = 1 + 3 + 5 + 7
        25 = 1 + 3 + 5 + 7 + 9

        */
       int res = num;
       int i = 1;
       
       while (res > 0)
       {
           res -= i;
           i += 2;

       }
    //    cout << res << endl;
       return res == 0;
        
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution *sol = new Solution();
    bool res = sol->isPerfectSquare(2147483647);
    return 0;
}

