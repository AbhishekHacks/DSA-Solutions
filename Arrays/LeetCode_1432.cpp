/*You are given an integer num. You will apply the following steps to num two separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.*/

//Time Complexity -- O(n)

class Solution {
public:
    int maxDiff(int num) {
        vector<int>vec;
        while(num>0){
            int r = num%10;
            vec.push_back(r);
            num/=10;
        }
        reverse(vec.begin(),vec.end());
        vector<int>temp(vec);
        int n = vec.size();
        if(n==1){
            return 8;
        }
        bool replace=false;
        int val = 0;
        for(int i=0;i<n;i++){
            if(!replace){
                if(vec[i]!=9){
                    val = vec[i];
                    vec[i]=9;
                    replace = true;
                }
            }
            else{
                if(vec[i]==val){
                    vec[i]=9;
                }
            }
        }
        val=0;
        int ele=0;
        replace = false;
        if(temp[0]!=1){
            val=temp[0];
            temp[0]=1;
            ele=1;
            replace=true;
        }
        for(int i=1;i<n;i++){
            if(!replace){
                if(temp[i]!=1&&temp[i]!=0){
                    val=temp[i];
                    temp[i]=ele;
                    replace=true;
                }
            }
            else if(replace&&temp[i]==val){
                temp[i]=ele;
            }
        }
        int maximum = 0;
        int minimum = 0;
        for(int i=0;i<n;i++){
            maximum=(maximum*10)+vec[i];
            minimum=(minimum*10)+temp[i];
        }
        return maximum-minimum;
    }
};
