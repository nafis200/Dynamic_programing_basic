// N ke koyti number er sum hisabe lekha jay 
// 4 
// 1+1+1+1 
// 1+2+1 
// 1+3 
// 2+2 
// 3+1 
// 2+1+1 
// 1 + 1 + 2 
// 4 
// Total = 8 
#include<bits/stdc++.h> 
using namespace std; 
const int N = 1e3 + 9, mod = 1e9 + 7; 
int ways[N]; 
int count(int n){ 
    if(n == 0){ 
        return 1; 
    } 
    if(ways[n] != -1){ 
        return ways[n]; 
    } 
    int ans = 0; 
    for(int i = 1; i <= n; i++){ 
        ans += count(n - i); 
        ans %= mod; 
    } 
    return ways[n] = ans; 
} 
int main(){ 
    int n; cin >> n; 
    memset(ways, -1, sizeof(ways)); 
    cout << count(n) << "\n"; 
} 
 
 
// Iterative ways 
// #include<bits/stdc++.h> 
// using namespace std; 
// const int N = 1e3 + 9, mod = 1e9 + 7; 
// int ways[N]; 
// int main(){ 
//     int n; cin >> n; 
//     ways[0] = 1; 
//     int ans = 0; 
//     for(int i = 1; i <= n; i++){ 
//         ans += ways[i - 1]; 
//         ways[i] = ans; 
//     } 
//     cout << ways[n] << "\n"; 
// }