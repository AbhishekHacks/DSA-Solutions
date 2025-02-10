#include <iostream>
using namespace std;

//Brute Force approach -- count the occurence of every number , the number that appear one time is the result
int findunique(int arr[],int size){
  int count=0;
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(arr[i]==arr[j]){
        count+=1;
      }
    }
    if(count==1){
      return arr[i];
    }
    count=0;
  }
  return 0;
}

//Optimized approach -- taking the XOR of numbers in array to find the unique element
int uniqueXOR(int arr[],int size){
  int result=0;
  for(int i=0;i<size;i++){
    result=result^arr[i];
  }
  return result;
}

int main(){
  int array[1000];
  cout<<"Enter the size of the array:";
  int size;
  cin>>size;
  cout<<"Enter the elements of array:";
  for(int i=0;i<size;i++){
    cin>>array[i];
  }
  cout<<"Using approach 1:"<<endl;
  cout<<"Unique element in array is: "<<findunique(array,size)<<endl;
  cout<<"Using approach 2:"<<endl;
  cout<<"Unique element in array is: "<<uniqueXOR(array,size)<<endl;

  return 0;
}
