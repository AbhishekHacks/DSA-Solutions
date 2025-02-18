#include<iostream>
#include<list>
using namespace std;
//lists in c++ 
int main(){
  list<int> l;
  l.push_back(1);
  l.push_front(2);
  for(int i:l){
    cout<<i<<" ";
  }
  cout<<endl;
  l.erase(l.begin());
  for(int i:l){
    cout<<i<<endl;
  }
}
