#include <bits/stdc++.h>

using namespace std;

/**
  Builds the Suffix Array for a given string. The Suffix Array `p`, where `p[i]` represents the starting index of the i-th lexicographically smallest suffix of `s`.
 * Time Complexity: O(n log n) - where n is the length of the string.
 * Space Complexity: O(n) - for the auxiliary vectors used during construction.
 */
vector<int> suffixArray(string s){ 
    int n = (s += "!").size();//if vector, s.push_back(-INF);
    vector<int> sf(n), ord(n), aux(n), cnt(n);
    iota(begin(sf), end(sf), 0);
    sort(begin(sf), end(sf), [&](int i, int j){ return s[i] < s[j]; });

    int cur = ord[sf[0]] = 0;
    for(int i=1; i<n; i++) 
        ord[sf[i]] = s[sf[i]] == s[sf[i-1]] ? cur : ++cur;
        
    for(int k=1; cur+1 < n && k < n; k<<=1){
        cnt.assign(n, 0);
        for(auto &i : sf)         i = (i-k+n)%n, cnt[ord[i]]++;
        for(int i=1; i<n; i++)    cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) aux[--cnt[ord[sf[i]]]] = sf[i];
        sf.swap(aux);

        aux[sf[0]] = cur = 0;
        for(int i=1; i<n; i++)
            aux[sf[i]] = ord[sf[i]] == ord[sf[i-1]] && 
            ord[(sf[i]+k)%n] == ord[(sf[i-1]+k)%n] ? cur : ++cur;
        ord.swap(aux);
    }
    return vector<int>(begin(sf)+1, end(sf));
}
\\ return the LCP array for a given string and its suffix array. The LCP array `lcp`, where `lcp[i]` represents the length of the longest common prefix between the i-th and (i-1)-th lexicographically smallest suffixes of `s`.
 * Time Complexity: O(n) - where n is the length of the string.
 * 
 */
vector<int> LCP(string &s, vector<int> &sf){ 
    int n = s.size();
    vector<int> lcp(n), pof(n);
    for(int i=0; i<n; i++) pof[sf[i]] = i;

    for(int i=0, j, k=0; i<n; k?--k:k, i++){
        if(!pof[i]) continue; 
        j = sf[pof[i]-1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[pof[i]] = k;
    }
    return lcp;
}