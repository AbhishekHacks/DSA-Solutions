#include<iostream>
#include<stack>
using namespace std;
//stack in c++ follows the principle of last in first out(LIFO)
int main(){
  stack<string> s;
  s.push("Love");
  s.push("Babbar");
  s.push("Codehelp");
  cout<<"Top element:"<<s.top()<<endl;
  s.pop();
  cout<<"Top element:"<<s.top()<<endl;
  cout<<"Size of element:"<<s.size()<<endl;
}
