#include <iostream>
#include <climits>
using namespace std;

bool uniqueoccurrences(int arr[],int size){
  int occurrence[size];
  int index=0;
  int count=1;
  for(int i=0;i<size;i++){
    if(arr[i]!=INT_MIN){
      for(int j=i+1;j<size;j++){
        if(arr[i]==arr[j]){
          count+=1;
          arr[j]=INT_MIN;
        }
      }
      for(int i=0;i<index;i++){
        if(occurrence[i]==count){
          return 0;
        }
      }
      occurrence[index++]=count;
      count=1;
    }
  }
  return 1;
}

int main(){
  int array[100];
  cout<<"Enter the size of the array:";
  int size;
  cin>>size;
  cout<<"Enter the elements of the array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  cout<<uniqueoccurrences(array,size);

  return 0;
}
