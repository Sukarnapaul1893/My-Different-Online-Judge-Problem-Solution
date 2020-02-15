//Author : Sukarna Paul
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
    IOS
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        ll a,b;
        cin>>a>>b;
        cout<<binpow(a,b,10LL)<<"\n";
    }
}
