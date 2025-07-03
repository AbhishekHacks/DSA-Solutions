/*Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.*/

//Time Complexity -- O(n)

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans;
        vector<char>v;
        for(int i=0;i<k;i++){
            while(v.size()>0&&num[i]<v[v.size()-1]){
                v.pop_back();
            }
            if(v.size()==0||num[i]>=v[v.size()-1]){
                v.push_back(num[i]);
            }
        }
        int index=0;
        for(int i=k;i<n;i++){
            while(v.size()>0&&num[i]<v[v.size()-1]){
                v.pop_back();
            }
            if(v.size()==0||num[i]>=v[v.size()-1]){
                v.push_back(num[i]);
            }
            if(index>v.size()-1){
                index = v.size()-1;
            }
            ans.push_back(v[index]);
            index++;
        }
        int temp = -1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                temp=i;
                break;
            }
        }
        string output;
        for(int i=temp;i<ans.size();i++){
            output.push_back(ans[i]);
        }
        if(output.size()==0){
            output="0";
        }
        return output;
    }
};
