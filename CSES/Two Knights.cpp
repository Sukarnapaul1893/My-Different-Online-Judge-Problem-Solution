#include<bits/stdc++.h>

using namespace std;
int n;
void input();

void solve(){
    for(long long k=1;k<=n;k++){
        long long total = k*k*(k*k-1);
        total/=2;
        total -= 4*(k-1)*(k-2);
        cout<<total<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
}

void input(){
    cin>>n;
}
