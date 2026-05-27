#include <bits/stdc++.h>
using namespace std;

\\ Standard O(n log n) algorithm to find the length of the longest increasing subsequence
int lis(vector<int> const& a) {
    int n = a.size();
    vector<int> temp;
    temp.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] > temp.back()) {
            temp.push_back(a[i]);
        } else {
            int it = lower_bound(temp.begin(), temp.end(), a[i])-temp.begin();
            temp[it] = a[i];
        }
    }
    return temp.size();
}