/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.58%)
 * Likes:    2146
 * Dislikes: 60
 * Total Accepted:    263.4K
 * Total Submissions: 603.9K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // 当先序遍历没有元素，返回 NULL
        if (preorder.size() == 0) {
            return NULL;
        }

        // 构造根节点 （先序遍历的第 0 个
        TreeNode *root = new TreeNode(preorder[0]);

        // 找到这个根在中序遍历中的位置
        vector<int>::iterator inIter = find(inorder.begin(), inorder.end(), root->val);
        int idx = distance(inorder.begin(), inIter);
        vector<int>::iterator preIter = preorder.begin() + idx;

        // 构建左右子树:

        // 左子树：
        vector<int> leftPre(preorder.begin()+1, preIter+1); // preorder[1,idx]
        vector<int> leftIn(inorder.begin(), inIter+1); // inorder[0, idx]
        root->left = buildTree(leftPre, leftIn);

        // 右子树
        vector<int> rightPre(preIter+1, preorder.end()); // preorder[idx+1, END]
        vector<int> rightIn(inIter+1, inorder.end()); // inorder[idx+1, END]
        root->right = buildTree(rightPre, rightIn);

        return root;

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
//      * preorder = [3,9,20,15,7]
//      * inorder = [9,3,15,20,7]

    vector<int> v0 = { 3,9,20,15,7 };
    vector<int> v1 = { 9,3,15,20,7 };

    Solution *sol = new Solution();
    TreeNode *n = sol->buildTree(v0, v1);

    cout << n->val << endl;
    cout << n->left->val << endl;
    cout << n->right->val << endl;
    cout << n->right->left->val << endl;
    cout << n->right->right->val << endl;
    return 0;
}
