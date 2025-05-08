/*You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.*/

//Time Compelxity -- O(N^2)

class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
        
        //sieve of eratosthenes -- O(Nlog(logN))
        vector<bool>prime(10008,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=10007;i++){
            if(prime[i]){
                int mult=2;
                while((i*mult)<=10007){
                    prime[i*mult]=false;
                    mult++;
                }
            }
        }
        
        Node *curr_node = head;
        while(curr_node!=NULL){ //-- O(N)
            if(!prime[curr_node->val]){ //-- O(1)
                int previous_prime = -1;
                int next_prime = -1;
                for(int i = curr_node->val-1;i>=2;i--){ //--O(N)
                    if(prime[i]){
                        previous_prime=i;
                        break;
                    }
                }
                for(int i = curr_node->val+1;i<=10007;i++){ //--O(N)
                    if(prime[i]){
                        next_prime=i;
                        break;
                    }
                }
                if(previous_prime==-1){
                    curr_node->val = next_prime;
                }
                else if(next_prime==-1){
                    curr_node->val = previous_prime;
                }
                else{
                    int diff1 = curr_node->val - previous_prime;
                    int diff2 = next_prime - curr_node->val;
                    if(diff1<=diff2){
                        curr_node->val = previous_prime;
                    }
                    else{
                        curr_node->val = next_prime;
                    }
                }
            }
            curr_node=curr_node->next;
        }
        return head;
    }
};
