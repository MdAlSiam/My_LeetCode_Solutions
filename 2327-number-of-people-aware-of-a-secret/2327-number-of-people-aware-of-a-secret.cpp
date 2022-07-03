class Solution {
    #define ll long long int 
    #define mod 1000000007

    bool deb = false;

    ll n;
    ll delay;
    ll forget;

    ll* personInDay;
    ll* starting;

    ll add(ll n1, ll n2) {
        return (n1%mod+n2%mod)%mod;
    }
public:
    int peopleAwareOfSecret(int _n, int _delay, int _forget) {
        n = _n;
        delay = _delay;
        forget = _forget;

        personInDay = new ll[n+10];
        starting = new ll[n+10];
        for (int i = 0; i < n+10; i++) {personInDay[i] = 0; starting[i] = 0;}
        starting[1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = i, kount = 0; j <= n and kount < forget; j++, kount++) {

                personInDay[j] = add(personInDay[j], starting[i]);

                if (kount < delay) {
                    
                }
                else {
                    starting[j] = add(starting[j], starting[i]);
                }
            }
        }

        for (int i = 0; i <= n and deb; i++) {
            cout << "|" << personInDay[i] << "|";
        } cout << endl;

        return personInDay[n];
    }
};