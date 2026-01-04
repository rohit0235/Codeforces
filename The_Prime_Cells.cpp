#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    ll n;
    cin >> n;

    vector<vector<ll>> grid(n, vector<ll>(n, 0));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<ll> primes(401, 0);

    // 0 - primehai
    primes[0] = 1;
    primes[1] = 1;

    for (ll i = 2; i < 401; i++)
    {

        if (primes[i] == 0)
        {

            for (int j = 2; j * i <= 400; j++)
            {
                primes[j * i] = 1;
            }
        }
    }
    int ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            vector<int> dx = {-1, 0, 1, 0};
            vector<int> dy = {0, 1, 0, -1};
            int sum = 0;
            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n)
                {
                    sum += grid[x][y];
                }
            }

            if (primes[sum] == 0)
            {
                ans++;
            }
        }
    }

   cout<<ans;
}