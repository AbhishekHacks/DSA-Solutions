/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

//Time Complexity -- O(1)

class MinStack {
public:

    stack<int>s;
    stack<int>temp;
    MinStack() {

    }
    
    void push(int val) {
        if(temp.empty()||val<=temp.top()){
            temp.push(val);
        }
        s.push(val);
    }
    
    void pop() {
        if(temp.top()==s.top()){
            temp.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
