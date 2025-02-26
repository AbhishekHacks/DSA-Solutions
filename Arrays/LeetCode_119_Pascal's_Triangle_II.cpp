/*Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.*/
/*Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        vector<int>temp;
        v.push_back(1);
        if(rowIndex==0){
            return v;
        }
        for(int i=1;i<=rowIndex;i++){
            v[0]=1;
            int p1=0;
            int p2=1;
            int index=1;
            while(index<v.size()){
                v[index]=temp[p1]+temp[p2];
                index++;
                p1++;
                p2++;
            }
            v.push_back(1);
            temp.clear();
            for(int j=0;j<v.size();j++){
                temp.push_back(v[j]);
            }
        }
        return v;
    }
};
