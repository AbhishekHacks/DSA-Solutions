/*Given two arrays of strings list1 and list2, find the common strings with the least index sum.

A common string is a string that appeared in both list1 and list2.

A common string with the least index sum is a common string such that if it appeared at list1[i] and list2[j] then i + j should be the minimum value among all the other common strings.

Return all the common strings with the least index sum. Return the answer in any order.*/

//Time Complexity -- O(n+m)

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size();
        int n2 = list2.size();
        unordered_map<string,int>m;
        for(int i=0;i<n1;i++){
            m[list1[i]]=i;
        }
        int minimum = INT_MAX;
        unordered_map<string,int>comp;
        for(int i=0;i<n2;i++){
            if(m.count(list2[i])){
                int sum = m[list2[i]]+i;
                if(sum<=minimum){
                    if(sum<minimum){
                        minimum=sum;
                        comp.clear();
                    }
                    comp[list2[i]]++;
                }
            }
        }
        vector<string>ans;
        for(auto i:comp){
            ans.push_back(i.first);
        }
        return ans;
    }
};
