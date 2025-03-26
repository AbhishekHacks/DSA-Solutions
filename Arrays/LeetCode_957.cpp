/*There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).

*/

//Time Copmplexity -- O(1)

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        //there is a pattern that the cells repeat after n%14 days
        //therefore the days to be calculated for is n%14
        int days=n%14;

        //edge case-->if the remainder is 0 than we need to do it for 14 days
        if(days==0){
            days=14;
        }

        //lets calculate the cells for 'days'
        //we also need to store the previous vector cell somewhere to acess it the next iteration
        for(int i=1;i<=days;i++){
            vector<int>previous;
            for(int j=0;j<8;j++){
                previous.push_back(cells[j]); //store the vector cells in previous at each call and than work with that previous meanwhile updating the vector 'cells'
            }
            for(int j=0;j<8;j++){
                if(j==0||j==7){
                    cells[j]=0;
                }
                else{

                    //checking if neigbour elements are same
                    if((previous[j-1]==0&&previous[j+1]==0)||(previous[j-1]==1&&previous[j+1]==1)){
                        cells[j]=1; //if yes than cells[j] will be 1
                    }
                    else{
                        cells[j]=0; //if not than 0
                    }
                }
            }

            //when we come out of this loop after ith day we have a 'cells' vector which is updated and than in the next iteration previous will be updated with that and we work with another updated cells vector
        }

        //after 'n%14' days we get the modified answer vector ie 'cells' , return it
        return cells;
    }
};
