#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Only for rotation left by 1 place
void rotate_by_one(vector<int>&arr , int n){
    int temp=arr[0];
    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];

    }
    arr[n-1]=temp;



}

//Now code for rotate left by k places
// Brute force approach    time complexity - O(n+k)  space complexity - O(k)
void left_roatate(vector<int>&arr,int n, int k){
    k=k%n;

    int temp[k];

    // storing elements in temp array
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }

    // shifting 
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];

    }

    // putting elements back in array
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i-(n-k)];
    }
}



// Method -2 easy approach  time complexity - O(2n)  space complexity - O(1)

void left_roatate_2(vector<int>&arr,int n,int k){
    k=k%n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
}

void print_array(vector<int> arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     
    cout<<"Printing original array:"<<endl;
    print_array(arr,n);
    left_roatate(arr,n,2);
    cout<<"Priting array after rotating:"<<endl;
    print_array(arr,n);
}