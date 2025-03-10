/*There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its left and right tiles) is called an alternating group.

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.*/

//Time Complexity -- O(N)

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int start=0;
        int count=0;
        while(start<colors.size()){
            if(colors[start]!=colors[(start+1)%colors.size()]&&colors[(start+1)%colors.size()]!=colors[(start+2)%colors.size()]){
                count+=1;
            }
            start++;
        }
        return count;
    }
};
