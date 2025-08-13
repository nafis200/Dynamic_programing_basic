
// suppose imagine 7 5 7 8

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> lis; 
   
    for(auto x : a){
        auto it = lower_bound(lis.begin(),lis.end(),x);
        if(it == lis.end()){
            lis.push_back(x);
        }
        else{
            *it = x;
        }
    }
 
    cout << lis.size() << "\n";
 
}


