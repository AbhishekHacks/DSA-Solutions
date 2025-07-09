/*Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

if no such substring exists, return 0.*/

//Time Complexity -- O(nlogn)

class Solution {
public:

    bool isPossible(string str ,int n, int k , int mid){
        unordered_map<char,int>m;
        for(int i=0;i<mid;i++){
            m[str[i]]++;
        }
        bool isgreater = true;
        for(auto i:m){
            if(i.second<k){
                isgreater = false;
                break;
            }
        }
        if(isgreater){
            return true;
        }
        int index=0;
        for(int i=mid;i<n;i++){
            m[str[i]]++;
            m[str[index]]--;
            if(m[str[index]]==0){
                m.erase(str[index]);
            }
            //check
            bool isgreater = true;
            for(auto i:m){
                if(i.second<k){
                    isgreater = false;
                    break;
                }
            }
            if(isgreater){
                return true;
            }
            index++;
        }
        return false;
    }

    int longestSubstring(string s, int k) {

        //edge case
        int n = s.size();
        unordered_map<char,int>edge;
        for(int i=0;i<n;i++){
            edge[s[i]]++;
        }
        bool isgreater = true;
        for(auto i:edge){
            if(i.second<k){
                isgreater = false;
                break;
            }
        }
        if(isgreater){
            return n;
        }

        int start=k;
        int end=n;
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(s,n,k,mid)){
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
