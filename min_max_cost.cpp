#include<bits/stdc++.h> 
using namespace std; 
int n, m, a[10][10], inf = 1e9 + 7; 
int dp[10][10]; 
int min_cost(int i, int j){ 
    if( j > m or i > n) 
    return inf; 
    if(i == n and j == m){ 
        return a[i][j]; 
    } 
    if(dp[i][j] != -1) 
    return dp[i][j]; 
    return dp[i][j] = a[i][j] + min(min_cost(i+1, j), min_cost(i, j  + 1)); 
} 
int main(){ 
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){ 
        for(int j = 1; j <= m; j++){ 
            cin >> a[i][j]; 
        } 
    } 
    memset(dp, -1, sizeof(dp)); 
    cout << min_cost(1, 1) << "\n"; 
} 