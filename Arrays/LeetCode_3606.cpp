/*You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

code[i]: a string representing the coupon identifier.
businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

*/

//Time Complexity -- O(n^2)

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string>electronics;
        vector<string>grocery;
        vector<string>pharmacy;
        vector<string>restaurant;
        for(int i=0;i<n;i++){
            string str = code[i];
            if(str.size()==0){
                continue;
            }
            int len = str.size();
            bool isvalid = true;
            for(int j=0;j<len;j++){ //coupon identifier
                if((str[j]<'a'||str[j]>'z')&&(str[j]<'A'||str[j]>'Z')&&(str[j]<'0'||str[j]>'9')&&str[j]!='_'){
                    isvalid=false;
                    break;
                }
            }
            if(!isvalid){
                continue;
            }
            if(isActive[i]==false){
                continue;
            }
            if(businessLine[i]=="electronics"){
                electronics.push_back(code[i]);
            }
            else if(businessLine[i]=="grocery"){
                grocery.push_back(code[i]);
            }
            else if(businessLine[i]=="pharmacy"){
                pharmacy.push_back(code[i]);
            }
            else if(businessLine[i]=="restaurant"){
                restaurant.push_back(code[i]);
            }
        }
        sort(electronics.begin(),electronics.end());
        sort(grocery.begin(),grocery.end());
        sort(pharmacy.begin(),pharmacy.end());
        sort(restaurant.begin(),restaurant.end());
        vector<string>ans;
        for(int i=0;i<electronics.size();i++){
            ans.push_back(electronics[i]);
        }
        for(int i=0;i<grocery.size();i++){
            ans.push_back(grocery[i]);
        }
        for(int i=0;i<pharmacy.size();i++){
            ans.push_back(pharmacy[i]);
        }
        for(int i=0;i<restaurant.size();i++){
            ans.push_back(restaurant[i]);
        }
        return ans;
    }
};
