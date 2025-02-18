#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(5);
  v.push_back(6);
  v.push_back(7);
  v.push_back(8);

  //binary search
  cout<<"Is 4 present in the vector:"<<binary_search(v.begin(),v.end(),5)<<endl;
  cout<<"Lower Bound:"<<lower_bound(v.begin(),v.end(),5)-v.begin()<<endl;
  cout<<"Upper Bound"<<upper_bound(v.begin(),v.end(),5)-v.begin()<<endl;
  
  //maximum and minimum
  int a=5;
  int b=3;
  int maximum=max(a,b);
  int minimum=min(a,b);
  cout<<"Maximum:"<<maximum<<" "<<"Minimum:"<<minimum<<endl;
  
  //swapping
  swap(a,b);
  cout<<a<<" "<<b<<endl;;
  
  //sorting
  vector<int> vec;
  vec.push_back(9);
  vec.push_back(8);
  vec.push_back(7);
  vec.push_back(6);
  vec.push_back(5);
  sort(vec.begin(),vec.end());
  for(int i:vec){
      cout<<i<<" ";
  }
}
