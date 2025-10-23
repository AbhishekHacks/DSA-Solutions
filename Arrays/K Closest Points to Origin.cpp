/*Given an integer k and an array of points points[][], where each point is represented as points[i] = [xi, yi] on the X-Y plane. Return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance, defined as:
distance = sqrt( (x2 - x1)2 + (y2 - y1)2 )

Note: You can return the k closest points in any order, the driver code will print them in sorted order.
Test Cases are generated such that there will be a unique ans.*/

//Time Complexity -- O(nlogn)

class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        multimap<double,vector<int>>mm;
        int n = points.size();
        for(int i=0;i<n;i++){
            double distance = sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            vector<int>temp;
            temp.push_back(points[i][0]);
            temp.push_back(points[i][1]);
            mm.insert({distance,temp});
        }
        vector<vector<int>>answer;
        for(auto i:mm){
            answer.push_back(i.second);
            if(answer.size()==k){
                break;
            }
        }
        return answer;
    }
};
