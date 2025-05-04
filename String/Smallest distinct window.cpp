/*Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
  
    bool isPossible(string& str,int n,int mid){
        unordered_map<char,int>m;
        unordered_map<char,int>temp;
        for(int i=0;i<n;i++){
            m[str[i]]=1;
        }
        for(int i=0;i<mid;i++){
            temp[str[i]]++;
        }
        if(temp.size()==m.size()){
            return true;
        }
        int startIndex=0;
        for(int i=mid;i<n;i++){
            if(temp[str[startIndex]]<=1){
                temp.erase(str[startIndex]);
            }
            else{
                temp[str[startIndex]]--;
            }
            temp[str[i]]++;
            if(temp.size()==m.size()){
                return true;
            }
            startIndex++;
        }
        return false;
    }
  
    int findSubString(string& str) {
        // code here
        int n = str.size();
        int start=1;
        int end=n;
        int answer=0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isPossible(str,n,mid)){
                answer = mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return answer;
    }
};
