/*You are given an integer array nums and two integers k and numOperations.

You must perform an operation numOperations times on nums, where in each operation you:

Select an index i that was not selected in any previous operations.
Add an integer in the range [-k, k] to nums[i].
Return the maximum possible frequency of any element in nums after performing the operations.*/

//Time Complexity -- O(nlogn)

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        auto it1 = max_element(nums.begin(),nums.end());
        auto it2 = min_element(nums.begin(),nums.end());
        int maximum = *it1;
        int minimum = *it2;
        int answer = INT_MIN;
        for(int i=minimum;i<=maximum;i++){
            //left half
            int startl = 0;
            int endl = lower_bound(nums.begin(),nums.end(),i)-nums.begin()-1;
            int left = endl+1;
            while(startl<=endl){
                int mid = startl+(endl-startl)/2;
                if(nums[mid]+k>=i){
                    left = mid;
                    endl = mid-1;
                }
                else{
                    startl = mid+1;
                }
            }
            //right half
            int startr = upper_bound(nums.begin(),nums.end(),i)-nums.begin();
            int endr = n-1;
            int right = startr-1;
            while(startr<=endr){
                int mid = startr+(endr-startr)/2;
                if(nums[mid]-k<=i){
                    right = mid;
                    startr = mid+1;
                }
                else{
                    endr = mid-1;
                }
            }
            //take the maximum
            if(m.count(i)){
                answer = max(answer,min(right-left+1-m[i],numOperations)+m[i]);
            }
            else{
                answer = max(answer,min(right-left+1,numOperations));
            }
        }
        return answer;
    }
};
