/*You are given an integer n. We say that two integers x and y form a prime number pair if:

1 <= x <= y <= n
x + y == n
x and y are prime numbers
Return the 2D sorted list of prime number pairs [xi, yi]. The list should be sorted in increasing order of xi. If there are no prime number pairs at all, return an empty array.

Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.*/

//Time Complexity -- O(NloglogN)

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        //sieve of eratosthenes
        vector<bool>v(n+1,true);
        v[0]=false;
        v[1]=false;
        for(int i=2;i<v.size();i++){
            int mult=2;
            while(i*mult<=n){
                v[(i*mult)]=false;
                mult++;
            }
        }
        vector<int>prime;
        unordered_map<int,int>m;
        for(int i=0;i<v.size();i++){
            if(v[i]==true){
                prime.push_back(i);
                m[i]=1;
            }
        }
        for(int i=0;i<prime.size();i++){
            int key = n-prime[i];
            if(m.count(key)==1){
                vector<int>temp;
                temp.push_back(prime[i]);
                temp.push_back(key);
                ans.push_back(temp);
                m.erase(prime[i]);
            }
        }
        return ans;
    }
};
