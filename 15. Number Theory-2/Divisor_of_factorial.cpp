#include <bits/stdc++.h>
using namespace std;

#define MAX 500001
#define MOD 1000000007
#define pb push_back

typedef long long ll;

vector<int> sieve()
{
    bool isPrime[MAX];

    vector<int> primes ;
    for (int i = 2; i <= MAX; i++)
    {
        isPrime[i] = true;
    }
    for (int i = 2; i * i <= MAX; i++)
    {

        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    primes.pb(2);
    for (int i = 3; i <= MAX; i += 2)
    {
        if (isPrime[i])
        {
            primes.pb(i);
        }
    }
    return primes;
}

ll divisors(int n, vector<int> primes)
{

    ll result = 1;
    for (int i = 0; primes.at(i) <= n; i++)
    {
        int k = primes.at(i);
        ll count = 0;
        while ((n / k) != 0)
        {
            count = (count + (n / k)) % MOD;
            k = k * primes.at(i);
        }
        result = (result * ((count + 1) % MOD)) % MOD;
    }
    return result;
}
int main()
{
    freopen("/home/spy/Desktop/input.txt", "r", stdin);
    freopen("/home/spy/Desktop/output.txt", "w", stdout);
    vector<int> primes = sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << divisors(n, primes) << endl;
    }
    return 0;
}