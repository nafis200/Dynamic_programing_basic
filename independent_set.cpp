#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int N;
vector<vector<int>> adj;
vector<ll> dp0, dp1;
vector<bool> visited;

void dfs(int v, int p) {
    dp0[v] = 1;
    dp1[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue; 
        dfs(u, v);
        dp0[v] = (dp0[v] * ((dp0[u] + dp1[u]) % MOD)) % MOD; 
        dp1[v] = (dp1[v] * dp0[u]) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    adj.assign(N + 1, {});
    dp0.assign(N + 1, 0);
    dp1.assign(N + 1, 0);
    visited.assign(N + 1, false);

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    ll ans = (dp0[1] + dp1[1]) % MOD;
    cout << ans << "\n";

    return 0;
}
