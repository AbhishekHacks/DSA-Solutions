/*You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

*/

//Time Complexity -- O(N^2)

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

    void roottoleaf(TreeNode *root,vector<vector<int>>&output,vector<int>temp){
        if(root==nullptr){
            return;
        }
        if(root->left==nullptr&&root->right==nullptr){
            temp.push_back(root->val);
            output.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        roottoleaf(root->left,output,temp);
        roottoleaf(root->right,output,temp);
    }

    int sumNumbers(TreeNode* root) {
        vector<vector<int>>output;
        vector<int>temp;
        roottoleaf(root,output,temp);
        int sum=0;
        for(int i=0;i<output.size();i++){
            int num=0;
            for(int j=0;j<output[i].size();j++){
                num=(num*10)+output[i][j];
            }
            sum+=num;
        }
        return sum;
    }
};
