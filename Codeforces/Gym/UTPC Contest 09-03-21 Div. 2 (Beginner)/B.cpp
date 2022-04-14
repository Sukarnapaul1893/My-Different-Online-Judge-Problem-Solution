#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

string s;

void Input();

void Solve(){
    int len = s.length();
    ll ans = 1;
    for(int i=0;i<len;i++){
        ans *= ((s[i]-'a')+1);
        ans %= 1000000007;
    }
    cout<<ans<<"\n";

}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    Solve();
    Clear();

}

void Input(){
    cin>>s;
}
