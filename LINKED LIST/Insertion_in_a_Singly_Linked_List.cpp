/*You are given a Singly Linked List of ‘N’ positive integers. Your task is to add a node having the value ‘VAL’ at position ‘POS’ in the linked list.

Note:
Assume that the Indexing for the linked list starts from 0.
EXAMPLE:
Input: ‘N’ = 5, 'LIST' = [1, 1, 2, 3, 4, -1], ‘VAL’ = 2, ‘POS’ = 1.

Output: 1 -> 2 -> 1 -> 2 -> 3 -> 4 */

//Time Complexity -- O(N)

/************************************************************

    Following is the LinkedList class structure:

    class Node {
    public:
        int data;
        Node *next;

        Node(int val) {
            this->data = val;
            next = NULL;
        }
        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

************************************************************/

Node * insert(Node * head, int n, int pos, int val) {
    // Write your code here

    Node *node = new Node(val);
    Node *temp=head;
    if(pos==0){
        node->next =head;
        head=node;
        return head;
    }
    int i=0;
    while(i!=pos-1){
        temp=temp->next;
        i+=1;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}
