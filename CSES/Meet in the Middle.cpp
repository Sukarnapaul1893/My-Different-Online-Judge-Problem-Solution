#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll x;
    cin>>n>>x;
    vector<ll>vec1,vec2;
    if(n==1){
        ll a;
        cin>>a;
        if(a!=x){
            cout<<0<<"\n";
        }
        else{
            cout<<1<<"\n";

        }
        return 0;
    }
    for(int i=0;i<n/2;i++){
        ll a;
        cin>>a;
        vec1.pb(a);
    }
    for(int i=n/2;i<n;i++){
        ll a;
        cin>>a;
        vec2.pb(a);
    }

    vector<ll >sum1,sum2;
        sum1.pb(0LL);
        sum2.pb(0LL);
        for(int i=0;i<vec1.size();i++){

            int sz = sum1.size();
            for(int j=0;j<sz;j++){
                if(x<sum1[j]+vec1[i])continue;
                sum1.pb(sum1[j]+vec1[i]);
            }

        }
        for(int i=0;i<vec2.size();i++){

            int sz= sum2.size();
            for(int j=0;j<sz;j++){
                if(x<sum2[j]+vec2[i])continue;
                sum2.pb(sum2[j]+vec2[i]);
            }

        }

        unordered_map<ll,ll>mp;
        sort(sum2.begin(),sum2.end());
        for(int i=0;i<sum2.size();i++){
            //if(x<sum2[i])break;
            mp[sum2[i]]++;
        }
        ll ans = 0;
        sort(sum1.begin(),sum1.end());

        for(int i=0;i<sum1.size();i++){
            if(x<sum1[i])break;
            ans+=mp[x-sum1[i]];
        }
        cout<<ans<<"\n";
}
