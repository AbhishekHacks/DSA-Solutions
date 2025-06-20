/*You are given a string s consisting of the characters 'N', 'S', 'E', and 'W', where s[i] indicates movements in an infinite grid:

'N' : Move north by 1 unit.
'S' : Move south by 1 unit.
'E' : Move east by 1 unit.
'W' : Move west by 1 unit.
Initially, you are at the origin (0, 0). You can change at most k characters to any of the four directions.

Find the maximum Manhattan distance from the origin that can be achieved at any time while performing the movements in order.

The Manhattan Distance between two cells (xi, yi) and (xj, yj) is |xi - xj| + |yi - yj|.*/

//Time Complexity -- O(n)

class Solution {
public:

    int getmaximum(string s,int n,int k,char ch1,char ch2,char ch3){
        int maximum = INT_MIN;
        int x = 0;
        int y = 0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1){
                y+=1;
            }
            else if(s[i]==ch2){
                if(k>0){
                    y+=1;
                    k--;
                }
                else{
                    y-=1;
                }
            }
            else if(s[i]==ch3){
                x+=1;
            }
            else{
                if(k>0){
                    x+=1;
                    k--;
                }
                else{
                    x-=1;
                }
            }
            maximum = max(maximum,(abs(x)+abs(y)));
        }
        return maximum;
    }

    int maxDistance(string s, int k) {
        int n = s.size();
        int a = getmaximum(s,n,k,'N','S','E');
        int b = getmaximum(s,n,k,'N','S','W');
        int c = getmaximum(s,n,k,'S','N','E');
        int d = getmaximum(s,n,k,'S','N','W');
        int maximum=INT_MIN;
        maximum=max(maximum,a);
        maximum=max(maximum,b);
        maximum=max(maximum,c);
        maximum=max(maximum,d);
        return maximum;
    }
};
