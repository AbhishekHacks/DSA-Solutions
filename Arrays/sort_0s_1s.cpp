#include <iostream>
using namespace std;

void printArray(int arr[],int size){
  for(int i=0;i<size;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

//approach1 -- using two pointers
void sortarray(int arr[],int size){
  int i=0;
  int j=size-1;
  while(i<j){
    if(arr[i]==0&&arr[j]==1){
      i++;
      j--;
    }
    else if(arr[i]==0&&arr[j]==0){
      i++;
    }
    else if(arr[i]==1&&arr[j]==1){
      j--;
    }
    else{
      arr[i]=0;
      arr[j]=1;
      i++;
      j--;
    }
  }
}

int main(){
  int array[1000];
  int size;
  cout<<"Enter the size of the array:";
  cin>>size;
  cout<<"Enter the elements of the array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  cout<<"Original Array:";
  printArray(array,size);
  cout<<"Array after sorting:";
  sortarray(array,size);
  printArray(array,size);

  return 0;
}
