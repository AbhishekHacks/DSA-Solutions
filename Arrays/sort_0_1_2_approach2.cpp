#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//approach 2 -- using sort function of the <algorithm> header
void sort_0_1_2(int arr[],int size){
  sort(arr,arr+size);
}
  
int main(){
  int array[1000];
  int size;
  cout<<"Enter the size of the array:";
  cin>>size;
  cout<<"Enter the elements of the array(0/1/2):";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  cout<<"Original Array:";
  printArray(array,size);
  cout<<"Sorted Array:";
  sort_0_1_2(array,size);
  printArray(array,size);

  return 0;
}

