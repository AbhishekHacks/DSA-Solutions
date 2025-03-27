/*There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.

*/

//Time Complexity -- O(N)

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        int n=candies.size();
        
        //take a boolean vector result
        vector<bool>result;

        //also calculate the highest amount of candy that a child has
        int highest=INT_MIN;
        for(int i=0;i<n;i++){
            if(highest<candies[i]){
                highest=candies[i];
            }
        }

        //now iterate the array to check if giving extra candy to a child makes it the highest amount
        for(int i=0;i<n;i++){
            if((candies[i]+extraCandies)>=highest){
                result.push_back(true);
            }
            else{
                result.push_back(false);
            }
        }

        //return the resulting boolean vector
        return result;
    }
};
