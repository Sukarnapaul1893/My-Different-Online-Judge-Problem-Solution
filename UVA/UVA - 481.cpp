#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int T[400020];
int arr[100005];

int query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r)return T[at];

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);

    return max(x,y);
}

void update(int at, int L, int R, int pos,int u ){
    if(L==R){
        T[at]=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }

    T[at] = max(T[at*2] , T[at*2+1]);
}

void build(int at , int L, int R){
    T[at]=0;
    if(L==R){
        T[at]=0;
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    T[at] = max(T[at*2] , T[at*2+1]);

}

bool comp(const pair<ll,int> &a, const pair<ll,int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll a[100004];
    map<ll,int>mp;
    vector<pair<ll,int> >vec;
    int t=1;
    while(cin>>n){
        a[t]=n;
        vec.pb({n,t++});
    }

    sort(vec.begin(),vec.end(),comp);
    n=t-1;
    build(1,1,n);

    for(int i=0;i<n;i++){
        int u = query(1,1,n,1,vec[i].second)+1;
        mp[vec[i].second]=u;
        update(1,1,n,vec[i].second,u);
    }
    int mx = T[1];

    vector<ll>ans;
    int prev=-1;
    cout<<mx<<"\n-\n";


    for(auto it=mp.rbegin();it!=mp.rend();it++){
        if((*it).second==mx){
            if(prev==-1){
                ans.pb(a[(*it).first]);
                mx--;
                prev = a[(*it).first];
            }
            else{
                if(a[(*it).first]<prev){
                    ans.pb(a[(*it).first]);
                    mx--;
                    prev = a[(*it).first];
                }
            }

        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}
