#include<bits/stdc++.h> 
using namespace std; 
int n; 
string s; 
const int N = 2e3 + 5; 
vector<int>g[N]; 
vector<int>vec; 
int nxt[N][N]; 
void dfs(int u, int p){ 
    vec.push_back(u); 
    for(auto x : g[u]){ 
        if(x != p){ 
            dfs(x, u); 
        } 
    } 
} 
void f(int u, int v){ 
    if(u == v){ 
        cout << u; 
      return; 
    } 
    cout << u << "-->"; 
    f(nxt[u][v], v); 
    return ; 
 
} 
int main(){ 
    int t; cin >> t; 
    while(t--){ 
         cin >> n; 
         cin >> s; 
         for(int i = 1; i < n; i++){ 
            int u, v; cin >> u >> v; 
            g[u].push_back(v); 
            g[v].push_back(u); 
         } 
         for(int u = 1; u <= n; u++){ 
              for(auto x : g[u]){ 
                vec.clear(); 
                 dfs(x, u); 
                 for(auto v : vec){ 
                    nxt[u][v] = x; 
                 } 
 
              } 
         } 
         cout << "after traversal" << "\n"; 
          f(1, 5); 
          
    } 
} 