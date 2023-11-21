#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Method-1  (Brute Force)  -> Time Complexity - O(nlogn)  Space Complexity - O(1)
int second_largest(int n,vector<int>&arr){
    sort(arr.begin(),arr.end());
    
    int largest=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if (arr[i]!=largest){
            return arr[i];
        }

    }
    return -1;
    
    
}


// Method-2(Beter Approach)  -> Time Complexity - O(n)  Space Complexity - O(1)
int second_largest_2(int n, vector<int>&arr){
    int largest=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }

    int slargest=INT_MIN;
    for(int i=0;i<n;i++){
        if (arr[i]>slargest  && arr[i]!=largest){
            slargest=arr[i];
        }
    }
    return slargest;
}


int second_largest_3(int n,vector<int>&arr){
    int largest=arr[0];
    int slargest=INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>slargest && arr[i]!=largest){
            slargest=arr[i];
        }
    
    }

    return slargest;

}



int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Second largest element in array is:"<<second_largest_3(n,arr)<<endl;
}