/*Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.

For example, flipping [1,1,0] horizontally results in [0,1,1].
To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.

For example, inverting [0,1,1] results in [1,0,0].*/

//Time Complexity -- O(n^2)

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n= image.size();

        //flip
        for(int i=0;i<n;i++){
            int j1=0;
            int j2=n-1;
            while(j1<j2){
                int temp = image[i][j1];
                image[i][j1] = image[i][j2];
                image[i][j2] = temp;
                j1++;
                j2--;
            }
        }

        //invert
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(image[i][j]==0){
                    image[i][j]=1;
                }
                else{
                    image[i][j]=0;
                }
            }
        }

        return image;
    }
};
