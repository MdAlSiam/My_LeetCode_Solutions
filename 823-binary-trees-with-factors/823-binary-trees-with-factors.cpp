class Solution {
    long long int mod = 1000000007;

    long long int add(long long int n1, long long int n2) {
        return (n1%mod + n2%mod) % mod;
    }

    long long int multiply(long long int n1, long long int n2) {
        return (n1%mod * n2%mod) % mod;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        map<int, long long int> mp;

        for (int num : arr) mp[num] = 1;   

        for (int i = 1; i < arr.size(); i++) {
            long long int kount = 0;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int n1 = arr[i] / arr[j];
                    int n2 = arr[j];

                    if (mp.count(n1) and mp.count(n2)) {
                        kount = add(kount, multiply(mp[n1], mp[n2]));
                    }
                }
            }

            mp[arr[i]] += kount;
        }

        long long int ans = 0;
        for (int num : arr) ans = add(ans, mp[num]);

        return (int) ans;
    }
};