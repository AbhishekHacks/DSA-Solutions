#include <iostream>
#include <climits>
using namespace std;

void arrayintersection(int arr1[],int arr2[],int size1,int size2){
  for(int i=0;i<size1;i++){
    for(int j=0;j<size2;j++){
      if(arr1[i]==arr2[j]){
        cout<<arr1[i]<<" ";
        arr2[j]=INT_MIN;
        break;
      }
    }
  }
}

int main(){
  int arr1[1000];
  int arr2[1000];
  cout<<"Enter the size of the first array:";
  int size1;
  cin>>size1;
  cout<<"Enter the size of the second array:";
  int size2;
  cin>>size2;
  cout<<"Enter the elements of the first array:";
  for(int i=0;i<size1;i++){
    cin>>arr1[i];
  }
  cout<<"Enter the elements of the second array:";
  for(int i=0;i<size2;i++){
    cin>>arr2[i];
  }
  cout<<"Intersection of both the arrays are:";
  arrayintersection(arr1,arr2,size1,size2);

  return 0;
}
