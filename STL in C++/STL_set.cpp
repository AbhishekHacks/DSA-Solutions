#include<iostream>
#include<set>
using namespace std;
int main(){
  set<int> s;
  s.insert(1);
  s.insert(5);
  s.insert(0);
  s.insert(2);
  s.insert(3);
  for(auto i:s){
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Is 5 present in set:"<<s.count(5)<<endl;
}
