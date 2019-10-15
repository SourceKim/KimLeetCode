/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (44.55%)
 * Likes:    1822
 * Dislikes: 241
 * Total Accepted:    270.9K
 * Total Submissions: 607.4K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
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
    void flatten(TreeNode* root) {

        vector<int> res;
        backtrack(root, res);

        TreeNode *p = root;

        for (int i=1; i<res.size(); i++) {
            p->right = new TreeNode(res[i]);
            p = p->right;
        }
        if (root) {
            root->left = NULL;
        }
        
        // root = &*(root->right);
 
    }

private:
    void backtrack(TreeNode *node, vector<int>& res) {

        if (!node) return;
        // cout << node->val << endl;
        // TreeNode *n = new TreeNode(node->val);
        // cout << toLinkNode->val << endl;
        // toLinkNode->right = n;
        res.push_back(node->val);
        backtrack(node->left, res);
        backtrack(node->right, res);

    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    TreeNode n0 = TreeNode(1);
    TreeNode n1 = TreeNode(2);
    TreeNode n2 = TreeNode(3);
    TreeNode n3 = TreeNode(4);
    TreeNode n4 = TreeNode(5);
    TreeNode n5 = TreeNode(6);

    n0.left = &n1;
    n0.right = &n4;
    n1.left = &n2;
    n1.right = &n3;
    n4.right = &n5;


    Solution *sol = new Solution();
    sol->flatten(NULL);

    TreeNode *p = &n0;

    while (p)
    {
        cout << p->val << endl;
        p = p->right;
    }
    

    return 0;
}

