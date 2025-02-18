#include<iostream>
#include<queue>
using namespace std;
//queue follows principle first in first out(FIFO)
int main(){
  queue<string> q;
  q.push("Love");
  q.push("Babbar");
  q.push("Codehelp");
  cout<<"Front Element:"<<q.front()<<endl;
  q.pop();
  cout<<"Front Element:"<<q.front()<<endl;
}
