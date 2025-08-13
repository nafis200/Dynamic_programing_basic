#include<bits/stdc++.h>
using namespace std;
int main(){
     int n; cin >> n;
     int count = 0;
     while(n){
        int mx = 0;
        int n1 = n;
        while(n1 > 0){
            mx = max(mx, n1 % 10);
            n1 = n1 / 10;
        }
        count++;
        n = n - mx;
     }
     cout << count << "\n";
}