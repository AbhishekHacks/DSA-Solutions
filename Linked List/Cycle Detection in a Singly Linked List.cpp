/*You are given a Singly Linked List of integers. Return true if it has a cycle, else return false.



A cycle occurs when a node's next points back to a previous node in the list.

*/

//Time Complexity -- O(N)

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    Node *hare = head;
    Node *rabbit = head->next;
    while(rabbit!=NULL && rabbit->next!=NULL){
        if(hare==rabbit){
            return true;
        }
        hare=hare->next;
        rabbit=rabbit->next->next;
    }
    return false;
}
