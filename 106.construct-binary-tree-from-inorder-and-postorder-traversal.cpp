/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] --
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    1033
 * Dislikes: 22
 * Total Accepted:    170.9K
 * Total Submissions: 415.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // for (int j=0; j<postorder.size(); j++) {
        //     cout << postorder[j] << " - ";
        // }
        // cout << endl;

        // for (int j=0; j<inorder.size(); j++) {
        //     cout << inorder[j] << " - ";
        // }
        // cout << endl;

        // 当先序遍历没有元素，返回 NULL
        if (postorder.size() == 0) {
            return NULL;
        }

        // 构造根节点 （先序遍历的第最后个
        TreeNode *root = new TreeNode(postorder[postorder.size()-1]);

        // 找到这个根在中序遍历中的位置
        vector<int>::iterator inIter = find(inorder.begin(), inorder.end(), root->val);
        int idx = distance(inorder.begin(), inIter);
        vector<int>::iterator postIter = postorder.begin() + idx;

        // cout << *postIter << endl;

        // 构建左右子树:

        // 左子树：
        vector<int> leftPost(postorder.begin(), postIter); // postorder[0,idx]
        vector<int> leftIn(inorder.begin(), inIter+1); // inorder[0, idx]
        root->left = buildTree(leftIn, leftPost);

        // 右子树
        vector<int> rightPost(postIter, postorder.end()-1); // preorder[idx, END-1]
        vector<int> rightIn(inIter+1, inorder.end()); // inorder[idx+1, END]
        root->right = buildTree(rightIn, rightPost); 

        // cout << "::::::" << endl;
        return root;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
//      * preorder = [3,9,20,15,7]
//      * inorder = [9,3,15,20,7]

    vector<int> v0 = { 9,3,15,20,7 };
    vector<int> v1 = { 9,15,7,20,3 };

    Solution *sol = new Solution();
    TreeNode *n = sol->buildTree(v0, v1);

    cout << n->val << endl;
    cout << n->left->val << endl;
    cout << n->right->val << endl;
    cout << n->right->left->val << endl;
    cout << n->right->right->val << endl;
    return 0;
}
