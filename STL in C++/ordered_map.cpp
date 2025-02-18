#include<iostream>
#include<map>
using namespace std;

//ordered map always return elements in a sorted order and contain unique keys.
//unordered map is same as ordered map , the difference is that in unordered map the time complexity is O(1) for searching while in ordered map the time complexity for searching is O(logn).

int main(){
  map<int,int> m;
  m[1]=2;
  m[2]=3;
  m[3]=4;
  m[4]=5;
  m.insert(5,6);
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
  }
  m.erase(4);
  for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
}
