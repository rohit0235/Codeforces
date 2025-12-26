#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

#define ll long long
const ll INF = 2e18; 

// Calculate cost to reach 2^D >= n via adding 4s then dividing
ll get_jump_cost(ll n) {
    if (n <= 0) return INF;
    ll d = 0;
    while ((1LL << d) < n) d++;
    return ((1LL << d) - n) / 4 + d;
}

// Calculate cost to reach 3 * 2^D >= n via adding 4s then dividing to 3 -> 1
ll get_jump3_cost(ll n) {
    ll d = 0;
    while (3 * (1LL << d) < n) d++;
    if (d < 2) d = 2; // Target must be divisible by 4
    return (3 * (1LL << d) - n) / 4 + d + 1;
}

void solve() {
    ll n;
    cin >> n;

    // Min-heap for Dijkstra: {cost, value}
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    map<ll, ll> dist;

    pq.push({0, n});
    dist[n] = 0;

    ll ans = INF;

    while (!pq.empty()) {
        ll cost = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        // Pruning
        if (cost >= ans) continue;
        if (dist.count(u) && dist[u] < cost) continue;

        // Base Cases
        if (u == 1) {
            ans = min(ans, cost);
            continue;
        }
        if (u == 2 || u == 3) {
            ans = min(ans, cost + 1);
            continue;
        }

        // If Odd and not 1 or 3, it's a dead end
        if (u % 2 != 0) continue;

        // Transitions for Even numbers
        if (u % 4 == 0) {
            // Strategy 1: Jump directly from u
            ans = min(ans, cost + get_jump_cost(u));
            ans = min(ans, cost + get_jump3_cost(u));

            // Strategy 2: Divide (u -> u/2)
            ll v1 = u / 2;
            ll w1 = cost + 1;
            if (!dist.count(v1) || w1 < dist[v1]) {
                dist[v1] = w1;
                pq.push({w1, v1});
            }

            // Strategy 3: Add 4 then Divide (u -> u+4 -> u/2 + 2)
            ll v2 = u / 2 + 2;
            ll w2 = cost + 2;
            if (!dist.count(v2) || w2 < dist[v2]) {
                dist[v2] = w2;
                pq.push({w2, v2});
            }
        } else {
            // u % 4 == 2: Must divide
            ll v = u / 2;
            ll w = cost + 1;
            if (!dist.count(v) || w < dist[v]) {
                dist[v] = w;
                pq.push({w, v});
            }
        }
    }

    if (ans == INF) cout << "-1\n";
    else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}