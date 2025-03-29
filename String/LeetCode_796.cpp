/*Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.*/

//Time Complexity -- O(N*M)

class Solution {
public:

    bool shiftstring(string s, string goal,int i,int j){

        int n=s.size();
        int m=goal.size();

        //now we got the index of first matching, match till i is equal to n-1 and if there is an unmatching in between return false
        int index = i;

        if(i!=n-1){
            while(i<n){
                if(s[i]!=goal[j]){
                    return false;
                }
                i++;
                j++;
            }

            //now if not false i becomes equal to n
            //set i to 0 and j same and keep comparing until i reaches index-1
            i=0;
            while(i<index){
                if(s[i]!=goal[j]){
                    return false;
                }
                i++;
                j++;
            }
        }

        //if matched at the last index set i to 0 and compare till index-1 or n-2 also increment j by 1 as we already looked one character in both the strings
        else{
            i=0;
            j++;
            while(i<index){
                if(s[i]!=goal[j]){
                    return false;
                }
                i++;
                j++;
            }
        }

        //finally everything was checked and the string could be made equal after some shifts
        return true;
    }

    bool rotateString(string s, string goal) {

        int n=s.size();
        int m=goal.size();

        //to be clear if one string must be equal to another , length must be same
        if(n!=m){
            return false;
        }
        
        //first take two pointers i and j
        int i=0;int j=0;

        bool answer=false;

        //start the loop
        while(i<n){
            
            //if character match note the index and break 
            //remember this loop is just for finding the index of first time matching
            if(s[i]==goal[j]){
                answer = shiftstring(s,goal,i,0);
                if(answer==true){
                    return answer;
                }
            }

            i++;
        }

        return answer;
    }
};
