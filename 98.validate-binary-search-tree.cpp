/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.30%)
 * Likes:    2403
 * Dislikes: 354
 * Total Accepted:    475.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
 * 
 * 
 */

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
    bool isValidBST(TreeNode* root) {
                // NULL 处理
        if (root == NULL) {
            return true;
        }
        
        stack<TreeNode *> st;
        TreeNode *cur = root;
        vector<int> vec;

        // 中序遍历
        while (!st.empty() || cur != NULL)
        {
            if (cur == NULL) {

                cur = st.top();
                st.pop();

                vec.push_back(cur->val);

                cur = cur->right;

            } else {

                st.push(cur);
                cur = cur->left;
            }
        }

        // 判断是否是升序
        for (int i=0; i<vec.size() - 1; i++) {
            if (vec[i] >= vec[i+1]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

