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

bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first<b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        ll ans = -1;
        ll a[n+1];
        vector<pair<ll,int> >vec;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            vec.pb({a[i],i});
        }
        int L;
        cin>>L;
        sort(vec.begin(),vec.end(),comp);
        build(1,1,n);

        for(int i=0;i<n;i++){
            int u = query(1,1,n,1,vec[i].second)+1;
            if(u==L){
                if(ans==-1)ans = vec[i].first;
                else ans = min(ans,vec[i].first);
            }
            update(1,1,n,vec[i].second,u);
        }

        cout<<ans<<"\n";
    }
}
