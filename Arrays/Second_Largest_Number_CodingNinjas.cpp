/*You have been given an array ‘a’ of ‘n’ unique non-negative integers.



Find the second largest and second smallest element from the array.



Return the two elements (second largest and second smallest) as another array of size 2.*/

//Time Complexity -- O(n)

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    vector<int>v;
    int secondlargest=INT_MIN;
    int secondsmallest=INT_MAX;
    int firstlargest=INT_MIN;
    int firstsmallest=INT_MAX;
    int index1=-1;
    int index2=-1;
    for(int i=0;i<n;i++){
        if(firstlargest<a[i]){
            firstlargest=a[i];
            index1=i;
        }
        if(firstsmallest>a[i]){
            firstsmallest=a[i];
            index2=i;
        }
    }
    a[index1]=-1;
    a[index2]=-1;
    for(int i=0;i<n;i++){
        if(a[i]!=-1){
            if(secondlargest<a[i]){
                secondlargest=a[i];
            }
            if(secondsmallest>a[i]){
                secondsmallest=a[i];
            }
        }
    }
    v.push_back(secondlargest);
    v.push_back(secondsmallest);
    return v;
}
