/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

*/

//Time Complexity -- O(n)

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

    void treetraversal(TreeNode* root , vector<vector<int>>&output,vector<int>temp){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr && root->right==nullptr){
            temp.push_back(root->val);
            output.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        treetraversal(root->left,output,temp);
        treetraversal(root->right,output,temp);
    }

    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        vector<vector<int>>output;
        vector<int>temp;
        treetraversal(root,output,temp);
        int maximum = 0;
        for(int i=0;i<output.size();i++){
            int len = output[i].size();
            maximum = max(maximum,len);
        }
        return maximum;
    }
};
