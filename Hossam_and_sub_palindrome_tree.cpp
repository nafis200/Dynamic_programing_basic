#include<bits/stdc++.h> 
using namespace std; 
string s; 
const int N = 2005; 
vector<int>g[N]; 
int nxt[N][N]; 
vector<int>vec; 
int dp[N][N]; 
void dfs(int u, int p){ 
    vec.push_back(u); 
    for(auto v : g[u]){ 
        if(v != p){ 
            dfs(v, u); 
        } 
    } 
} 
int f(int u, int v){ 
    if(u == v) 
    return 1; 
    int &ans = dp[u][v]; 
    if(ans != -1){ 
        return ans; 
    } 
    if(s[u] == s[v]){ 
        ans = 2 + (nxt[u][v] == v ? 0 : f(nxt[u][v], nxt[v][u])); 
    } 
    else{ 
        ans = max(f(nxt[u][v], v), f(u, nxt[v][u])); 
    } 
    return ans; 
} 
 
int32_t main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){ 
        int n; cin >> n; 
        cin >> s; 
        s = "." + s; 
        for(int i = 1; i < n; i++){ 
            int u, v; cin >> u >> v; 
            g[u].push_back(v); 
            g[v].push_back(u); 
        } 
        // memset(dp, -1, sizeof(dp)); 
        for(int i = 1; i <= n; i++){ 
            for(int j = 1; j <= n; j++){ 
                dp[i][j] = -1; 
            } 
        } 
    for(int u = 1; u <= n; u++){ 
        for(int x : g[u]){ 
            vec.clear(); 
            dfs(x, u); 
            for(auto v: vec){ 
                nxt[u][v] = x; 
            } 
        } 
    } 
    int ans = 0; 
    for(int u = 1; u <= n; u++){ 
        for(int v = 1; v <= n; v++){ 
            ans = max(ans, f(u, v)); 
        } 
    } 
    cout << ans << "\n"; 
    for(int i = 1; i <= n; i++){ 
        g[i].clear(); 
    } 
    } 
    return 0; 
} 
