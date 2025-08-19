/*We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.*/

//Time Complexity -- O(n)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()||(st.top()<0&&asteroids[i]<0)||(st.top()>0&&asteroids[i]>0)||(st.top()<0&&asteroids[i]>0)){
                st.push(asteroids[i]);
                continue;
            }
            bool both = false;
            bool single = false;
            while(!st.empty()&&(st.top()>0&&asteroids[i]<0)){
                if(abs(st.top())>abs(asteroids[i])){
                    single=true;
                    break;
                }
                else if(abs(st.top())==abs(asteroids[i])){
                    st.pop();
                    both=true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!single&&!both){
                st.push(asteroids[i]);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
