#include <iostream>
using namespace std;

void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

void sort_0_1_2(int arr[],int size){
  int count_0=0,count_1=0,count_2=0;
  for(int i=0;i<size;i++){
    if(arr[i]==0){
      count_0+=1;
    }
    else if(arr[i]==1){
      count_1+=1;
    }
    else{
      count_2+=1;
    }
  }
  for(int i=0;i<size;i++){
    if(count_0>0){
      arr[i]=0;
      count_0--;
    }
    else if(count_1>0){
      arr[i]=1;
      count_1--;
    }
    else{
      arr[i]=2;
    }
  }
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
