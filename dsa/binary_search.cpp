//{ Driver Code Starts
// Initial template for C++

#include<iostream>
using namespace std;


// } Driver Code Ends
// User function template for C++
int binarysearch(int arr[], int n, int k) {
        int s = 0;
        int e = n;
        int m;
        while(s <= e) {
            m = s+(e-s)/2;
            if(arr[m] == k)
                return m;
            else if(arr[m] < k)
                s = m+1;
            else if(arr[m] > k)
                e = m-1;
        }
        return -1;
}

//{ Driver Code Starts.
int main() {
        int n;
        cout  << "Please enter n's value: ";
        cin >> n;
        int arr[n];
        cout << "Please enter array elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Please enter key: ";
        int key;
        cin >> key;
        int found = binarysearch(arr, n, key);
        cout << found << endl;
}

// } Driver Code Ends
