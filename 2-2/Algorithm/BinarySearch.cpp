#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& v, int tar){
    int a = 0;
    int b = v.size() - 1;
    while(a < b){
        int m = a + (b - a) / 2;
        if(v[m] < tar){
            a = m + 1;
        }
        else{
            b = m;
        }
    }
    return (a < v.size() && v[a] == tar) ? a : -1;
}

int main(){
    vector<int>v = {1, 3, 5, 8, 10, 13, 17};
    sort(v.begin(),v.end());
    int target = 10;
    int result = binarySearch(v, target);
    if (result != -1) {
        cout << "Element found at index: " <<  result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}