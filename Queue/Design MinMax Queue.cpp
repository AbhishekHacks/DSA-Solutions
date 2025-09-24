/*Design a SpecialQueue data structure that functions like a normal queue but with additional support for retrieving the minimum and maximum element efficiently.
The SpecialQueue must support the following operations:

enqueue(x): Insert an element x at the rear of the queue.
dequeue(): Remove the element from the front of the queue.
getFront(): Return the front element without removing.
getMin(): Return the minimum element in the queue in O(1) time.
getMax(): Return the maximum element in the queue in O(1) time.
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2:  Call dequeue()
3: Call getFront()
4: Call getMin()
5: Call getMax()
The driver code will process the queries, call the corresponding functions, and print the outputs of getFront(), getMin(), getMax() operations.
You only need to implement the above five functions.

Note: It is guaranteed that all the queries are valid.*/

//Time Complexity -- O(logn)

class SpecialQueue {

  public:
    queue<int>q;
    map<int,int>m;
    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        m[x]++;
    }

    void dequeue() {
        // Remove element from the queue
        int value = q.front();
        q.pop();
        m[value]--;
        if(m[value]==0){
            m.erase(value);
        }
    }

    int getFront() {
        // Get front element
        return q.front();
    }

    int getMin() {
        // Get minimum element
        auto it = m.begin();
        return it->first;
    }

    int getMax() {
        // Get maximum element
        auto it = m.end();
        it--;
        return it->first;
    }
};
