#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int h[N];
int a[N];
const int inf = 1e9;

int frog(int n){
    if(n == 1){
        return 0;
    }
    if(n < 1){
        return inf;
    }
    if(a[n] != -1){
        return a[n];
    }
    int ans = inf;
    for(int i = 1; i <= 2; i++){
        ans = min(ans,frog(n - i) + abs(h[n] - h[n - i]));
        a[n] = ans;
    }
    return ans;
}
int main(){
    memset(a,-1,sizeof(a));
    int n; cin >> n;
    h[0] = inf;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    int ans = frog(n);
    cout << ans << "\n";
}