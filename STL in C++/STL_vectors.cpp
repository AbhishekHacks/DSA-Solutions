#include<iostream>
#include<vector>
using namespace std;
//vectors in c++ are arrays that are dynamic in nature
int main(){
  vector<int> a;
  a.push_back(1);
  cout<<"Capacity of a:"<<a.capacity()<<endl;
  cout<<"Size of a :"<<a.size()<<endl;
  a.push_back(2);
  cout<<"Capacity of a:"<<a.capacity()<<endl;
  cout<<"Size of a :"<<a.size()<<endl;
  a.push_back(3);
  cout<<"Capacity of a:"<<a.capacity()<<endl;
  cout<<"Size of a:"<<a.size()<<endl;
  vector<int> vec(a);
  for(int i:vec){
    cout<<i<<" ";
  }
  cout<<"Element at 2nd index:"<<vec.at(2)<<endl;
  cout<<"Element at front:"<<vec.front()<<endl;
  cout<<"Element at back:"<<vec.back()<<endl;
  vec.pop_back();
  for(int i:vec){
    cout<<i<<" ";
  }
  cout<<endl;
  vector<int> v1(5,1);
  for(int i:v1){
    cout<<i<<" ";
  }
}
