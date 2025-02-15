/*Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.

Example :
Input: arr = [2, 1, 5, 6, 2, 3], k = 2

Output: 11

Explanation:
First painter can paint boards 1 to 3 in 8 units of time and the second painter can paint boards 4-6 in 11 units of time. Thus both painters will paint all the boards in max(8,11) = 11 units of time. It can be shown that all the boards can't be painted in less than 11 units of time.*/

bool ispossiblesolution(vector<int>& boards , int k , int mid){
    int countpainter=1;
    int timesum=0;
    for(int i=0;i<boards.size();i++){
        if(timesum+boards[i]<=mid){
            timesum+=boards[i];
        }
        else{
            countpainter++;
            if(boards[i]>mid || countpainter>k){
                return 0;
            }
            timesum=boards[i];
        }
    }
    return 1;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s=0;
    int sum=0;
    for(int i=0;i<boards.size();i++){
        sum+=boards[i];
    }
    int e = sum;
    int ans=0;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(ispossiblesolution(boards,k,mid)){
            ans=mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
