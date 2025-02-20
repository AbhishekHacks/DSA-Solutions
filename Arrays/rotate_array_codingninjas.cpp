/*Given an array 'arr' with 'n' elements, the task is to rotate the array to the left by 'k' steps, where 'k' is non-negative.
Example:
'arr '= [1,2,3,4,5]
'k' = 1  rotated array = [2,3,4,5,1]
'k' = 2  rotated array = [3,4,5,1,2]
'k' = 3  rotated array = [4,5,1,2,3] and so on.*/

void reverseArray(vector<int>& arr,int i,int j){
    while(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    k=k%arr.size();
    reverseArray(arr,0,k-1);
    reverseArray(arr,k,arr.size()-1);
    reverseArray(arr,0,arr.size()-1);
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
        answer.push_back(arr[i]);
    }
    return answer;
}
