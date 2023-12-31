#include<bits/stdc++.h>
using namespace std;

bool searchinarr(vector<vector<int> >& arr, int x) {
    int m = arr.size(), n = arr[0].size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == x) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int x;
    cout << "Please enter size of the array: ";
    cin >> x;
    vector<vector<int> > arr = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}};
    // for(int i = 0; i < x; i++) {
    //     for(int j = 0; j < x; j++) {
    //         cin >> arr[i][j];
    //     }
    // }
    if(searchinarr(arr, x)){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}