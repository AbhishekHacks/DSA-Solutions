//Give row wise sum of matrix

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

  //row wise sum
  for(int i=0;i<3;i++){
    int sum=0;
    for(int j=0;j<4;j++){
      sum+=arr[i][j];
    }
    cout<<"Sum of Row "<<(i+1)<<" : "<<sum;
  }

  return 0;
}
