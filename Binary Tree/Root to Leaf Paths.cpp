/*Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

*/

//Time Complexity -- O(n)

class Solution {
  public:
  
  
    void pathtoleaf(Node *root,vector<vector<int>>&output,vector<int>temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            temp.push_back(root->data);
            output.push_back(temp);
            return;
        }
        temp.push_back(root->data);
        pathtoleaf(root->left,output,temp);
        pathtoleaf(root->right,output,temp);
    }
  
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>output;
        vector<int>temp;
        pathtoleaf(root,output,temp);
        return output;
    }
};
