#include <iostream>
using namespace std;

//brute force approach
void pairsum(int arr[],int size,int target){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if((arr[i]+arr[j])==target){
                if(arr[i]<=arr[j]){
                    cout<<arr[i]<<" "<<arr[j]<<endl;
                }
                else{
                    cout<<arr[j]<<" "<<arr[i]<<endl;
                }
            }
        }
    }
}

int main(){
  int arr[1000];
  cout<<"Enter the size of the array:";
  int size;
  cin>>size;
  cout<<"Enter the elements of the array:";
  for(int i=0;i<size;i++){
    cin>>arr[i];
  }
  cout<<"Enter the target sumn:";
  int target;
  cin>>target;
  cout<<"Pairs with the target sum are:"<<endl;
  pairsum(arr,size,target);

  return 0;
}
