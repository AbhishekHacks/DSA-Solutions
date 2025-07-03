/*A 0-indexed array derived with length n is derived by computing the bitwise XOR (⊕) of adjacent values in a binary array original of length n.

Specifically, for each index i in the range [0, n - 1]:

If i = n - 1, then derived[i] = original[i] ⊕ original[0].
Otherwise, derived[i] = original[i] ⊕ original[i + 1].
Given an array derived, your task is to determine whether there exists a valid binary array original that could have formed derived.

Return true if such an array exists or false otherwise.

A binary array is an array containing only 0's and 1's*/

//Time Complexity -- O(n)

class Solution {
public:

    bool startwith(vector<int>& derived,int n,int a,int b){
        vector<int>original1;
        original1.push_back(a);
        original1.push_back(b);
        for(int i=1;i<n;i++){
            if(i==n-1){
                int x = original1[i]^original1[0];
                if(x==derived[i]){
                    return true;
                }
            }
            else{
                int x = derived[i]^original1[i];
                original1.push_back(x);
            }
        }
        return false;
    }

    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n==1){
            if(derived[0]==0){
                return true;
            }
            else{
                return false;
            }
        }
        //case -1
        if(derived[0]==0){
            //case -a
            bool result1 = startwith(derived,n,0,0);
            //case-b
            bool result2 = startwith(derived,n,1,1);

            if(result1||result2){
                return true;
            }
            else{
                return false;
            }
        }
        //case-2
        else{
            //case -a
            bool result1 = startwith(derived,n,0,1);
            //case-b
            bool result2 = startwith(derived,n,1,0);

            if(result1||result2){
                return true;
            }
            else{
                return false;
            } 
        }
    }
};
