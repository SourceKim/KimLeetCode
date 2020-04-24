/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (47.57%)
 * Likes:    1419
 * Dislikes: 90
 * Total Accepted:    291.3K
 * Total Submissions: 586.1K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if (!root) return {};

        // 这一分组的最后一个
        if (!root->left && !root->right) return { to_string(root->val) };

        vector<string> res;

        // 找左边的，所有结果，放到集合里
        for (string str: binaryTreePaths(root->left)) {
            res.push_back(to_string(root->val) + "->" + str);
        }
        // 找右边的，所有结果，放到集合里
        for (string str: binaryTreePaths(root->right)) {
            res.push_back(to_string(root->val) + "->" + str);
        }

        return res;
    }
};
// @lc code=end

