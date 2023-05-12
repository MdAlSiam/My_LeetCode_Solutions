#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll n;
ll k;
ll primes[1120];
ll nPrimes;

ll dp[200][15][1121];  

bool isPrime(ll num) {
    for (ll i = 2; i*i <= num; i++) {
        if (num%i == 0) return false;
    }
    return true;
}

void makeprimes() {
    nPrimes = 0;
    primes[nPrimes++] = 2;
    for (ll i = 3; i <= 1120; i++) {
        if (isPrime(i)) {
            primes[nPrimes++] = i;
        }
    }
}

ll go(ll index, ll rem_coins, ll rem_sum) {
    if (index == nPrimes) {
        if (rem_coins == 0 && rem_sum == 0) return 1;
        return 0;
    }

    if (dp[index][rem_coins][rem_sum] != -1) return dp[index][rem_coins][rem_sum];

    ll ret1 = 0, ret2 = 0;
    
    if (rem_coins-1 >= 0 && rem_sum-primes[index] >= 0)
        ret1 = go(index+1, rem_coins-1, rem_sum-primes[index]);
    ret2 = go(index+1, rem_coins, rem_sum);

    return dp[index][rem_coins][rem_sum] = ret1+ret2;
}

int main() {
    makeprimes();
    memset(dp, -1, sizeof(dp));
    while (true) {
        cin >> n >> k;
        if (!n and !k) break;
        cout << go(0, k, n) << endl;
    }
}
