/*Given a board of dimensions n × m that needs to be cut into n*m squares. The cost of making a cut along a horizontal or vertical edge is provided in two arrays:

x[]: Cutting costs along the vertical edges (length-wise).
y[]: Cutting costs along the horizontal edges (width-wise).
Find the minimum total cost required to cut the board into squares optimally.*/

//Time Complexity -- O(mlogm+nlogn)

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int minC = 0;
        int horizontal_segment = 1;
        int vertical_segment = 1;
        int i=x.size()-1;
        int j=y.size()-1;
        while(i>=0&&j>=0){
            if(x[i]>y[j]){
                minC += (x[i]*horizontal_segment);
                vertical_segment++;
                i--;
            }
            else if(y[j]>x[i]){
                minC += (y[j]*vertical_segment);
                horizontal_segment++;
                j--;
            }
            else{
                if(horizontal_segment<vertical_segment){
                    minC += (x[i]*horizontal_segment);
                    vertical_segment++;
                    i--;
                }
                else if(vertical_segment<horizontal_segment){
                    minC += (y[j]*vertical_segment);
                    horizontal_segment++;
                    j--;
                }
                else{
                    if(m>=n){
                        minC += (x[i]*horizontal_segment);
                        vertical_segment++;
                        i--;
                    }
                    else{
                        minC += (y[j]*vertical_segment);
                        horizontal_segment++;
                        j--;
                    }
                }
            }
        }
        while(i>=0){
            minC += (x[i]*horizontal_segment);
            i--;
        }
        while(j>=0){
            minC += (y[j]*vertical_segment);
            j--;
        }
        return minC;
    }
};
