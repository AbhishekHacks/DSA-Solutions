/*Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/

//Time Complexity -- O(m*n)

class Solution {
public:

    vector<int> nsr(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n,n);
        stack<int>st_value;
        stack<int>st_index;
        for(int i=n-1;i>=0;i--){
            while(!st_value.empty()&&st_value.top()>=arr[i]){
                st_value.pop();
                st_index.pop();
            }
            if(st_value.empty()){
                st_value.push(arr[i]);
                st_index.push(i);
            }
            else if(st_value.top()<arr[i]){
                st_value.push(arr[i]);
                ans[i]=st_index.top();
                st_index.push(i);
            }
        }
        return ans;
    }
    
    vector<int> nsl(vector<int>&arr){
        int n = arr.size();
        vector<int>ans(n,-1);
        stack<int>st_value;
        stack<int>st_index;
        for(int i=0;i<n;i++){
            while(!st_value.empty()&&st_value.top()>=arr[i]){
                st_value.pop();
                st_index.pop();
            }
            if(st_value.empty()){
                st_value.push(arr[i]);
                st_index.push(i);
            }
            else if(st_value.top()<arr[i]){
                st_value.push(arr[i]);
                ans[i]=st_index.top();
                st_index.push(i);
            }
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>mat;
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(matrix[i][j]-'0');
            }
            mat.push_back(temp);
        }
        int maxarea = 0;
        vector<int>vec(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                temp.push_back(mat[i][j]);
            }
            for(int j=0;j<n;j++){
                if(temp[j]==0){
                    vec[j]=0;
                }
                else{
                    vec[j]+=temp[j];
                }
            }
            vector<int>widthleft = nsl(vec);
            vector<int>widthright = nsr(vec);
            for(int j=0;j<n;j++){
                int area = vec[j]*(widthright[j]-widthleft[j]-1);
                maxarea = max(maxarea,area);
            }
        }
        return maxarea;
    }
};
