//Author : Sukarna Paul

#include<bits/stdc++.h>

#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f

using namespace std;



int main(){

    ios::sync_with_stdio(false);

    int t;

    cin>>t;
    for(int tt=0;tt<t;tt++){
        ll p,l;
        cin>>p>>l;
        p-=l;

        cout<<"Case "<<tt+1<<": ";
        if(p<=l){

            cout<<"impossible\n";
            continue;
        }
        set<ll>vec;
        ll sn = sqrt(p)+1;
        for(ll i=1;i<=sn;i++){
            if(p%i==0){
                ll div = p/i;
                vec.insert(i);
                vec.insert(div);
            }
            if(p/i<l)break;
        }
        int cnt=0;
        for(auto it = vec.begin();it!=vec.end();it++){

            ll x = (*it);
                if(x>l){
                    if(cnt!=0)cout<<" ";
                    cout<<x;
                    cnt++;
                }
        }

        cout<<"\n";

     }
}
