

\\ Function to calculate the Mobius function for all numbers up to MAXN in o(n) time
int mu[MAXN];
bool comp[MAXN];
vector<int> primes;

void mobius() {
    memeset(comp, 0, sizeof(comp));
    memeset(mu, 0, sizeof(mu));
    mu[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        if (!comp[i]) primes.push_back(i), mu[i] = -1;
        for (int p : primes) {
            if (i * p >= MAXN) break;
            comp[i * p] = 1;
            if (i % p == 0) { mu[i * p] = 0; break; }
            mu[i * p] = -mu[i];
        }
    }
}