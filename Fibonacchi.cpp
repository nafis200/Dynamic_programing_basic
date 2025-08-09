#include<bits/stdc++.h> 
using namespace std; 
const int N = 1e5 + 6; 
int d[N]; 
int fib(int n){ 
    if(n == 1) 
    return 1; 
    if(n == 0) 
    return 0; 
    if(d[n] != -1) 
    return d[n]; 
    d[n] = fib(n - 1) + fib(n - 2); 
    return d[n]; 
} 
int main(){ 
    memset(d, -1, sizeof(d)); 
    cout << fib(6) << "\n"; 
} 
 
// Iterative : 
// #include<bits/stdc++.h> 
// using namespace std; 
// const int N = 1e5 + 6; 
// int d[N]; 
// int main(){ 
//      memset(d, 0, sizeof(d)); 
//      d[0] = 0; 
//      d[1] = 1; 
//      for(int i = 2; i <= 6; i++){ 
//         d[i] = d[i-1] + d[i - 2]; 
//      } 
//      cout << d[6] << "\n"; 
// } 