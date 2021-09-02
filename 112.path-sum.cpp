/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
 *
 * https://leetcode.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (38.70%)
 * Likes:    1141
 * Dislikes: 367
 * Total Accepted:    355K
 * Total Submissions: 915.9K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 * such that adding up all the values along the path equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \      \
 * 7    2      1
 * 
 * 
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 * 
 */

#include "helper/helper.hpp"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        if (root == NULL) {
            return false;
        }

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *top = st.top();
            st.pop();

            // 更新左右节点的值 （加上这个节点的值

            if (top->left == NULL && top->right == NULL) {
                // 到了节点的头
                if (top->val == sum) {
                    return true;
                }

            } else {

                if (top->left != NULL) {
                        top->left->val += top->val;
                        st.push(top->left);
                    }

                if (top->right != NULL) {
                    top->right->val += top->val;
                    st.push(top->right);
                }
            }

        }

        return false;
        
    }
};
// @lc code=end

