/*There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.*/

//Time Complexity -- O(N)

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int i=1;
        int n=colors.size();
        int start=0;
        int prev = colors[0];
        int count=-1;
        int ans=0;
        bool beg=true;
        for(int j=1;j<k-1;j++){
            if(colors[j]==colors[j-1]){
                beg=false;
                break;
            }
        }
        while(start<n){
            if(start==0&&i==n+1){
                return n;
            }
            if(start==n-1&&beg==true&&(colors[n-1]!=colors[0])){
                ans+=1;
                break;
            }
            else if(start==n-1){
                break;
            }
            int curr=colors[i%n];
            if(prev==curr){
                if(i>(n-2+k)){
                    ans+=(n-start);
                    break;
                }
                int diff = (i-start);
                if((diff-k)>0){
                    ans+=(diff-k)+1;
                }
                else if((diff-k)==0){
                    ans+=1;
                }
                start=i;
            }
            prev=curr;
            i++;
        }
        return ans;
    }
};
