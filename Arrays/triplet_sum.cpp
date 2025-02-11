#include <iostream>
using namespace std;

//brute force approach
void tripletsum(int arr[],int size,int target){
  for(int i=0;i<size-2;i++){
    for(int j=i+1;j<size-1;j++){
      for(int k=j+1;k<size;k++){
        if(arr[i]+arr[j]+arr[k]==target){
          cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
        }
      }
    }
  }
}

int main(){
  int array[1000];
  int size;
  cout<<"Enter the size of the array:";
  cin>>size;
  cout<<"Enter the elemnts of the array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  int target;
  cout<<"Enter the target sum:";
  cin>>target;
  cout<<"The triplets with the given sum are:"<<endl;
  tripletsum(array,size,target);

  return 0;
}
