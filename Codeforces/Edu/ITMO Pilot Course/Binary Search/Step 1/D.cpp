#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,k;
vector<ll>vec;

void Input();

void Solve(){
    sort(vec.begin(), vec.end());
    cin>>k;

    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;

        int lo = lower_bound(vec.begin(),vec.end(),l)-vec.begin();
        int hi = upper_bound(vec.begin(),vec.end(),r)-vec.begin();

        if(lo==hi){
            if(vec[lo]>=l and vec[lo]<=r){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<(hi-lo);
        }

        if(i==k-1)  cout<<"\n";
        else        cout<<" ";
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
    cin>>n;

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        vec.pb(x);
    }
}
