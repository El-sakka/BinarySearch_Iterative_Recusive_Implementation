#include <bits/stdc++.h>
using namespace std;

// Assume n ---> size of array
// Assume x ---> Search Number

int BinarySearchIterative(int a[],int n,int x){
    int low = 0, high = n -1;
    while(low <= high){
        int mid = low + (high - low)/2; // could be written as (low+high)/2 but to avoid overflow
        if(a[mid]== x)
            return mid;
        else if(x < a[mid])
            high = mid -1;
        else
            low = mid +1;
    }
    // if not found the number return -1
    return -1;
}

int BinarySearchRecursive(int a[],int low , int high,int x){
    if(low >high)
        return -1;
    int mid = low +(high - low)/2;
    if(a[mid] == x) return mid;
    else if (x < a[mid]) BinarySearchRecursive(a,low,mid-1,x);
    else    BinarySearchRecursive(a,low+1,high,x);
}

int main() {
    int arr[100] , n , x;
    cout<<"Enter Array Size :\n";
    cin>>n;
    cout<<"Enter Array Elements :\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    cout<<"Enter the Searched Number :\n";
    cin>>x;
    cout<<BinarySearchIterative(arr,n,x);
    cout<<BinarySearchRecursive(arr,0,n-1,x);

    return 0;
}