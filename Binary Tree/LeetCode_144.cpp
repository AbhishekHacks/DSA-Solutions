/*Given the root of a binary tree, return the preorder traversal of its nodes' values.*/

//Time Complexity -- O(N)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void preorder(TreeNode* root,vector<int>&output){
        if(root==nullptr){
            return;
        }
        output.push_back(root->val);
        preorder(root->left,output);
        preorder(root->right,output);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>output;
        preorder(root,output);
        return output;
    }
};
