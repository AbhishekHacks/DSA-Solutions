//Basic operations like input and output in matrix

#include<iostream>
using namespace std;

int main(){
  int arr[3][4];

  //take input
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      cin>>arr[i][j];
    }
  }

  //take output
  for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
