/*Given the root of a binary tree, return the postorder traversal of its nodes' values.*/

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

    void postorder(TreeNode* root, vector<int>&output){
        if(root==nullptr){
            return;
        }
        postorder(root->left,output);
        postorder(root->right,output);
        output.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>output;
        postorder(root,output);
        return output;
    }
};
