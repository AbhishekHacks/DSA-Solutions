/*Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.

An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.

You may return the answer in any order. In your answer, each value should occur at most once.*/

//Time Complexity -- O(logx(bound)*logy(bound))

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int>vx;
        vector<int>vy;
        if(x==1){
            vx.push_back(1);
        }
        else{
            int power = 0;
            while(pow(x,power)<=bound){ //logx(bound)
                vx.push_back(pow(x,power));
                power++;
            }
        }
        if(y==1){
            vy.push_back(1);
        }
        else{
            int power = 0;
            while(pow(y,power)<=bound){ //logy(bound)
                vy.push_back(pow(y,power));
                power++;
            }
        }
        vector<int>answer;
        unordered_map<int,int>m;
        int nx = vx.size();
        int ny = vy.size();
        for(int i=0;i<nx;i++){ //O(logx(bound)*logy(bound))
            for(int j=0;j<ny;j++){
                int sum = vx[i]+vy[j];
                if(!m.count(sum)&&sum<=bound){
                    answer.push_back(sum);
                    m[sum]++;
                }
            }
        }
        return answer;
    }
};
