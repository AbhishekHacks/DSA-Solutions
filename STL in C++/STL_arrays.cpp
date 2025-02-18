#include<iostream>
#include<array>
using namespace std;

//Using Standard Template Arrays(STL Arrays), these are also static in nature
int main(){
  array<int,4> a={1,2,3,4};
  cout<<"Size of the array is:"<<a.size()<<endl;
  cout<<"Element at the third index is:"<<a.at(3)<<endl;
  cout<<"Is the Array empty:"<<a.empty()<<endl;
  cout<<"The first element of the Array is:"<<a.front()<<endl;
  cout<<"The last element of the Array is:"<<a.back()<<endl;
}
