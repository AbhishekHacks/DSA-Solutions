/*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.*/

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

    int minDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        vector<vector<int>>output;
        vector<int>temp;
        treetraversal(root,output,temp);
        int minimum = INT_MAX;
        for(int i=0;i<output.size();i++){
            int len = output[i].size();
            minimum = min(minimum,len);
        }
        return minimum;
    }
};
