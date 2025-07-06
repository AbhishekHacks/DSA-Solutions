/*You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.*/


class FindSumPairs {
public:
    vector<int>nums1;
    vector<int>nums2;
    unordered_map<int,int>m1;
    unordered_map<int,int>m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) { //O(n+m)
        this->nums1=nums1;
        this->nums2=nums2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
    }
    
    void add(int index, int val) { //O(1)
        m2[nums2[index]]--;
        nums2[index]+=val;
        m2[nums2[index]]++;
    }
    
    int count(int tot) { //O(k)
        int totalpairs=0;
        for(auto i:m1){
            int target = tot-i.first;
            if(m2.count(target)){
                totalpairs+=(i.second*m2[target]);
            }
        }
        return totalpairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
