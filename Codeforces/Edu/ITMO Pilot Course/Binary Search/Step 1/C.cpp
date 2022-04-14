#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,k;
vector<ll>vec;

void Input();

void Solve(){
    sort(vec.begin(),vec.end());

    for(int i=0;i<k;i++){
        int x;
        cin>>x;

        int ans = lower_bound(vec.begin(),vec.end(),x)-vec.begin();

        cout<<ans+1<<"\n";
    }
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
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.pb(x);
    }
}
