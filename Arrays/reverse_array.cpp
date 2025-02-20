/*Given an array with N elements, the task is to reverse all the array elements and print the reversed array.*/

#include <iostream>
using namespace std;

void reverseArray(int arr[],int N){
    int i=0,j=N-1;
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

int main() {
    //Write your code here
    int arr[1000];
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    reverseArray(arr,N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
