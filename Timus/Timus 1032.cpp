#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n;
vector<ll>arr,vec;
void input();

vector<int>rem[10004];

void solve(){
    vec[0]%=n;
    rem[vec[0]].pb(0);
    for(int i=1;i<n;i++){
        vec[i]+=vec[i-1];
        vec[i]%=n;
        rem[vec[i]].pb(i);
    }
    if(rem[0].size()>=1){
        int pos = rem[0][0];
        cout<<pos+1<<"\n";
        for(int i=0;i<=pos;i++){
            cout<<arr[i]<<"\n";
        }
        exit(0);
    }

    for(int j=1;j<n;j++){
        int sz = rem[j].size();
        if(sz<2)continue;
        int start = rem[j][0]+1;
        int End = rem[j][1];

        cout<<End+1-start<<"\n";

        for(int i=start;i<=End;i++)cout<<arr[i]<<"\n";

        exit(0);
    }
    cout<<0<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        arr.pb(a);
        vec.pb(a);
    }
}
