/*Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.*/

//Time Complexity -- O(q*k)

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) { // O(q*k)
        vector<int>temp;
        vector<int>power;
        int num = 1;
        //calculate every power of 2 less than equal to n -- O(log2(n))
        while(num<=n){
            temp.push_back(num);
            num*=2;
        }
        //generate the power array -- O(log2(n))
        int len = temp.size();
        int sum = 0;
        for(int i=len-1;i>=0;i--){
            sum+=temp[i];
            if(sum<n){
                power.push_back(temp[i]);
            }
            else if(sum==n){
                power.push_back(temp[i]);
                break;
            }
            else if(sum>n){
                sum-=temp[i];
            }
        }
        //sort the power array
        sort(power.begin(),power.end());
        //run the queries and perform the product -- O(k*n) where 1<=k<=31
        vector<int>answers;
        int q = queries.size();
        for(int i=0;i<q;i++){
            int start = queries[i][0];
            int end = queries[i][1];
            long long pro = 1;
            for(int j=start;j<=end;j++){
                pro=(pro*power[j])%1000000007;
            }
            pro=pro%1000000007;
            answers.push_back(pro);
        }
        //return the answers
        return answers;
    }
};
