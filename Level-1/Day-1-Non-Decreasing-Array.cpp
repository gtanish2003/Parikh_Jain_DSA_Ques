#include<iostream>
#include<vector>
using namespace std;

bool checkpossibility(vector<int>&arr){
    int modified=0;
    for(int i=1;i<arr.size();i++){
        if (arr[i-1]>arr[i]){
            modified++;

            if (modified >1 )return false;

            if (i>2 || arr[i-2]<=arr[i]){
                arr[i-1]=arr[i];
            }
            else{
                arr[i]=arr[i-1];
            }
        }

        
    }
  return true;
}

bool checkPossibility(vector<int>&arr)
{
    int pos=-1;
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            if(pos!=-1)
                return false;
            pos=i;
        }
    }

    return  pos==-1|| pos==0 || pos==n-2 || arr[pos-1]<=arr[pos+1] || arr[pos]<=arr[pos+2];
}




int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<checkpossibility(arr);
    return 0;
}

// Main Logic:
// We can modify atmost one element in the array to make it non-decreasing.
// We can modify the array in two ways:
// 1. arr[i-1] = arr[i]
// 2. arr[i] = arr[i-1]
// We will check for both the cases and if the array is non-decreasing in any of the cases, we will return true.
// If the array is non-decreasing in both the cases, we will return false.
// Time Complexity: O(n)
// Space Complexity: O(1)

// pos=0
// pos=length-2
// value[pos-1]<=value[pos+1]
// value[pos]<=value[pos+2]
