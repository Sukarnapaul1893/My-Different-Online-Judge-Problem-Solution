#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin>>n;

    while(n>=1){
        cout<<n<<" ";
        if(n==1)break;
        if(n&1LL)n = 3LL*n+1LL;
        else n/=2LL;
    }
    cout<<"\n";
}
