#include <iostream>
using namespace std;

//Approach 1: Count the total number of set bits in the number 
bool totalsetbits(int number){
  int count=0;
  while(number>0){
    if((number&1)==1){
      count+=1;
    }
    number=number>>1;
  }
  //Check if the number of set bits is equal to 1
  if(count==1){
    return 1;
  }
  return 0;
}

//Approach 2: Doing Bitwise AND
bool bitwiseand(int number){
  //check if the number is greater than 0
  if(number<=0){
    return 0;
  }
  //bitwise AND of that number with the number lesser than it by 1
  int result = number & (number-1);
  //check if the result is equal to 0
  if(result==0){
    return 1;
  }
  return 0;
}

int main(){
  int num;
  cout<<"Please enter the number:";
  cin>>num;

  cout<<"Using Approach 1"<<endl;
  int approach1 = totalsetbits(num);
  if(approach1){
    cout<<"The number is a power of 2"<<endl;
  }
  else{
    cout<<"The number is not a power of 2"<<endl;
  }

  cout<<"Using Approach 2"<<endl;
  int approach2 = bitwiseand(num);
  if(approach2){
    cout<<"The number is a power of 2"<<endl;
  }
  else{
    cout<<"The number is not a power of 2"<<endl;
  }

  return 0;
}
