/*You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.*/

//Time Complexity -- O(n^2logn)

class Solution {
  public:
  
    bool isPossible(string& s1,string& s2,int n1,int n2,int mid){
        unordered_map<string,int>m;
        for(int i=0;i<=n1-mid;i++){
            string str;
            for(int j=i;j<i+mid;j++){
                str.push_back(s1[j]);
            }
            m[str]++;
        }
        for(int i=0;i<=n2-mid;i++){
            string str;
            for(int j=i;j<i+mid;j++){
                str.push_back(s2[j]);
            }
            if(m.count(str)){
                return true;
            }
        }
        return false;
    }
  
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n1 = s1.size();
        int n2 = s2.size();
        int start=1;
        int end=min(n1,n2);
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(s1,s2,n1,n2,mid)){
                answer=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return answer;
    }
};
