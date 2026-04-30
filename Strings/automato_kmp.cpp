#include <bits/stdc++.h>
using namespace std;

// Template do Autômato do KMP (Prefix Automaton)
// Complexidade de Construção: O(N * ALPHABET_SIZE)
struct KMPAutomaton {
    int n;
    vector<int> pi;
    vector<vector<int>> aut;
    const int ALPHABET_SIZE = 26;
    const char BASE_CHAR = 'a'; // Mude para 'A' ou '0' se o problema exigir

    KMPAutomaton(string& s) {
        n = s.size();
        pi.assign(n, 0);
        aut.assign(n + 1, vector<int>(ALPHABET_SIZE, 0));

        if (n == 0) return;
        
        aut[0][s[0] - BASE_CHAR] = 1;
        
        for (int i = 1; i <= n; i++) {
            
            for (int c = 0; c < ALPHABET_SIZE; c++) {
                if (i < n && s[i] - BASE_CHAR == c) {
                    aut[i][c] = i + 1;
                } 
                else {
                    
                    int fallback = (i == n) ? pi[n - 1] : pi[i - 1];
                    aut[i][c] = aut[fallback][c];
                }
            }
            
            if (i < n) {
                pi[i] = aut[pi[i - 1]][s[i] - BASE_CHAR];
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string padrao = "abacaba";
    KMPAutomaton kmp(padrao);

    
    string texto = "abacabacaba";
    int estado = 0;
    
    for(auto val:kmp.pi) cout<<val<<" ";
    cout<<endl;

    return 0;
}