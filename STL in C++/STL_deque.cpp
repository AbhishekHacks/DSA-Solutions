#include<iostream>
#include<deque>
using namespace std;
//deque in c++ are dynamic in nature. Insertion and Deletion can be done from both the ends of the array
int main(){
  deque<int> d;
  d.push_back(1);
  d.push_front(2);
  for(int i:d){
    cout<<i<<" ";
  }
  cout<<endl;
  d.push_front(3);
  d.pop_front();
  for(int i:d){
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Front:"<<d.front()<<endl;
  cout<<"End:"<<d.back()<<endl;
  d.erase(d.begin(),d.begin()+1);
  for(int i:d){
    cout<<i<<" ";
  }
}
