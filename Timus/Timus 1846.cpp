#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

ll sum[400020];
ll arr[100005];



void update(int at, int L, int R, int pos, ll u ){
    if(L==R){
        sum[at]=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }
    if(sum[at*2]==-1)sum[at]=sum[at*2+1];
    else if(sum[at*2+1]==-1)sum[at]=sum[at*2];
    else sum[at] = __gcd(sum[at*2],sum[at*2+1]);
}

void build(int at , int L, int R){
    sum[at]=-1;
    if(L==R){
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    map<ll,vector<int> >mp;
    build(1,1,100003);
    int cur =1;
    int n=100001;
    for(int i=0;i<q;i++){
        char c;
        ll a;
        cin>>c>>a;

        if(c=='+'){
            mp[a].pb(cur);
            update(1,1,n,cur,a);
            cout<<max(1LL,sum[1])<<"\n";
            cur++;
        }
        else{
            auto at = mp[a].begin();
            int temp = (*at);
            mp[a].erase(at);

            update(1,1,n,temp,-1);
            cout<<max(1LL,sum[1])<<"\n";
        }
    }
}
