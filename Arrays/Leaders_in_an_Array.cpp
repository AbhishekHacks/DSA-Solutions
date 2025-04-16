/*Given a sequence of numbers. Find all leaders in sequence. An element is a leader if it is strictly greater than all the elements on its right side.

Note:
1. Rightmost element is always a leader.

2. The order of elements in the return sequence must be the same as the given sequence
Example:
The given sequence is 13, 14, 3, 8, 2 .

13 Not a leader because on the right side 14 is greater than 13.

14 lt is a leader because no one greater element in the right side.

3 Not a leader because on the right side 8 are greater than 3.

8 It is a leader because no one greater element on the right side.

2 It is a leader because it is the rightmost element in a sequence.

Hence there are 3 leaders in the above sequence which are 14, 8, 2.*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &elements, int n) {
    // Write your code here.

    stack<int>st;
    vector<int>output;

    for(int i=n-1;i>=0;i--){
        if(st.empty()||elements[i]>st.top()){
            st.push(elements[i]);
        }
    }

    while(!st.empty()){
        output.push_back(st.top());
        st.pop();
    }

    return output;
}
