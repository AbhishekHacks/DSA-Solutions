//Function for the problem remove element ( LeetCode 27 )

int removeElement(vector<int>& nums, int val) {
  int k=0;
  int index=0;
  for(int i=0;i<nums.size();i++){
    if(nums[i]!=val){
      nums[index++]=nums[i];
      k++;
    }
  }
  return k;
}
