/*A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
*/

//Time Complexity -- O(n^2)

class Solution {
public:
    int countTriples(int n) {
        int count=0;
        for(int a=1;a<=n;a++){
            int limit_b = sqrt(pow(n,2)-pow(a,2));
            for(int b=1;b<=limit_b;b++){
                int added_square = pow(a,2)+pow(b,2);
                double c = sqrt(added_square);
                if(floor(c)==c){
                    count++;
                }
            }
        }
        return count;
    }
};
