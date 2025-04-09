/*You have been given two sorted arrays/lists of closed intervals ‘INTERVAL1’ and ‘INTERVAL2’. A closed interval [x, y] with x < y denotes the set of real numbers ‘z’ with x <= z <= y.

Now, your task is to find the intersection of these two interval lists.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [0, 2] and [1, 3] is [1, 2].


Note :

1. Each list of intervals is pairwise disjoint.
2. 'INTERVAL1' and 'INTERVAL2' don't contain duplicate intervals.
3. If there is no intersection present in 'INTERVAL1' and 'INTERVAL2' return an empty array/list.
For example, if INTERVAL1 = [[0, 5], [7, 9], [10, 11]] and INTERVAL2 = [[0, 2], [3, 7], [12, 15]], then the intersection array/list will be [[0, 2], [3, 5], [7, 7]].*/

//Time Complexity -- O(n)

#include <bits/stdc++.h> 
vector<vector<int>> intersectionIntervals(vector<vector<int>>& interval1, vector<vector<int>>& interval2, int n1, int n2)
{
    // Write your code here.

    vector<vector<int>> output;

    int i=0;
    int j=0;
    while(i<n1&&j<n2){
        
        vector<int>interval;
        int opening1 = interval1[i][0];
        int closing1 = interval1[i][1];
        int opening2 = interval2[j][0];
        int closing2 = interval2[j][1];

        //case-1
        if(opening1>=opening2&&opening1<=closing2){
            interval.push_back(opening1);
            if(closing1>closing2){
                interval.push_back(closing2);
                j++;
            }
            else if(closing1<closing2){
                interval.push_back(closing1);
                i++;
            }
            else{
                interval.push_back(closing2);
                i++;
                j++;
            }
            output.push_back(interval);
        }

        //case-2
        else if(opening2>=opening1&&opening2<=closing1){
            interval.push_back(opening2);
            if(closing2>closing1){
                interval.push_back(closing1);
                i++;
            }
            else if(closing2<closing1){
                interval.push_back(closing2);
                j++;
            }
            else{
                interval.push_back(closing1);
                i++;
                j++;
            }
            output.push_back(interval);
        }

        //case-3
        else if(opening1>closing2){
            j++;
        }

        //case-4
        else if(opening2>closing1){
            i++;
        }
    }

    return output;
}
