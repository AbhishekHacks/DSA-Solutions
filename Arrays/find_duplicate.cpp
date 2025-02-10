#include <iostream>
using namespace std;

//Brute force approach -- count the number of occurences of each element in array , the element with 2 occurence is the answer
int approach1(int arr[],int size){
  int count=0;
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(arr[i]==arr[j]){
        count+=1;
      }
    }
    if(count>1){
      return arr[i];
    }
    count=0;
  }
  return 0;
}

//optimised approach -- do the xor of all elements of array than the result will xored will elements from 1-n
int approach2(int arr[],int size){
  int ans=0;
  for(int i=0;i<size;i++){
    ans=ans^arr[i];
  }
  for(int i=1;i<size;i++){
    ans=ans^i;
  }
  return ans;
}

int main(){
  int array[1000];
  int size;
  cout<<"Enter the size of the array:";
  cin>>size;
  cout<<"Enter the elements of array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  cout<<"Using approach 1"<<endl;
  cout<<"Duplicate element is:"<<approach1(array,size)<<endl;
  cout<<"Using approach 2"<<endl;
  cout<<"Duplicate element is:"<<approach2(array,size)<<endl;

  return 0;
}
