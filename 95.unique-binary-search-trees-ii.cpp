/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (37.00%)
 * Likes:    1486
 * Dislikes: 126
 * Total Accepted:    153.8K
 * Total Submissions: 414.8K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

        if (n == 0) {
            vector<TreeNode *> vec;
            return vec;
        }

        return recursion(1, n);
        
    }
private:
    vector<TreeNode *> recursion(int start, int end) {

        // cout << start << " == " << end << endl;

        vector<TreeNode *> vec;
        // 递归终点
        if (start > end) {
            // cout << "end" << endl;
            vec.push_back(NULL); // 这很重要, 即使这一个 vec 不合法，也要有 NULL 去和另一半去配对
            return vec;
        }

        // 遍历所有 start-end 的数，生成结果 vec
        for (int i=start; i<=end; i++) {

            // 将 i 分为左、右边树的数组 （包括了左、右边树的所有形状组合
            vector<TreeNode *> leftTrees = recursion(start, i - 1);
            vector<TreeNode *> rightTrees = recursion(i + 1, end);

            // cout << "left size: " << leftTrees.size() << endl;
            // cout << "right size: " << rightTrees.size() << endl;

            // 生成以 i 为根所有子树组合 （难
            for (int j=0; j<leftTrees.size(); j++) {
                for (int k=0; k<rightTrees.size(); k++) {
                    
                    // cout << "new: " << i << endl;
                    TreeNode *node = new TreeNode(i);
                    node->left = leftTrees[j];
                    node->right = rightTrees[k];
                    vec.push_back(node);
                }
            }
        }

        return vec;
    }
};
// @lc code=end

int main(int argc, char const *argv[]) {

    Solution *sol = new Solution();
    vector<TreeNode *> res = sol->generateTrees(3);
    for (int k=0; k<res.size(); k++) {
        cout << res[k]->val << endl;
    }
    
    
    return 0;
}

