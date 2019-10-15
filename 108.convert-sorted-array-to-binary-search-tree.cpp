/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (53.05%)
 * Likes:    1461
 * Dislikes: 151
 * Total Accepted:    305.9K
 * Total Submissions: 576.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int mid = nums.size() / 2;
        if (nums.size() == 0) {
            return NULL;
        }
        // cout << mid << endl;
        TreeNode *root = new TreeNode(nums[mid]);

        int leftIdx = mid - 1;
        if (leftIdx < 0) {
            root->left = NULL;
        } else {
            vector<int> left (nums.begin(), nums.begin() + leftIdx + 1);
            root->left = sortedArrayToBST(left);
        }

        int rightIdx = mid + 1;
        if (rightIdx >= nums.size()) {
            root->right = NULL;
        } else {
            vector<int> right (nums.begin() + rightIdx, nums.end());
            root->right = sortedArrayToBST(right);   
        }

        return root;

    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    vector<int> nums = {-10,-3,0,5,9};
    Solution *sol = new Solution();
    TreeNode *node = sol->sortedArrayToBST(nums);

    cout << node->val << endl;
    cout << node->left->val << endl;
    cout << node->left->left->val << endl;
    cout << node->right->val << endl;
    cout << node->right->left->val << endl;
    return 0;
}

