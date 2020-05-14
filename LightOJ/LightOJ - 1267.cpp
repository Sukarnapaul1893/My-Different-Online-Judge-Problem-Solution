//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/*
0 5 2 4 7
0 2 4 5 7

1

5 6

0 0

5 9

2 3

4 6

7 7

0 0 5 9

2 2 10 11

4 6 7 9

3 3 4 5

4 6 5 7

5 7 7 9
*/

vector<pair<ll,ll> >points;

void getpoints(int p){
    for(int i=0;i<p;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);

        points.pb({x,y});
    }
    sort(points.begin(),points.end());
}

ll arr[50004];
ll Arr[50004];
void CreateArray(int p){
    Arr[0]=-1;
    arr[0]=-1;
    for(int i=1;i<=p;i++){
        Arr[i]=points[i-1].first;
        arr[i]=points[i-1].second;
    }
}
vector<ll>data[200020];

int query(int at, int L, int R, int l, int r,ll k){
    if(r<L || R<l)return 0;
    if(l<=L && R<=r){
        int cnt = upper_bound(data[at].begin(),data[at].end(),k)-data[at].begin();
        return (data[at].size()-cnt);
    }

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r,k);
    int y = query(at*2+1,mid+1,R,l,r,k);

    return (x+y);
}
void build(int at , int L, int R){
    if(L==R){
        data[at].pb(arr[L]);
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    int i,j;
    for(i=0,j=0;i<data[at*2].size() && j<data[at*2+1].size();){
        if(data[at*2][i]<=data[at*2+1][j]){
            data[at].pb(data[at*2][i]);
            i++;
        }
        else{
            data[at].pb(data[at*2+1][j]);
            j++;
        }
    }
    for(;i<data[at*2].size();i++){
        data[at].pb(data[at*2][i]);
    }
    for(;j<data[at*2+1].size();j++){
        data[at].pb(data[at*2+1][j]);
    }

}
void Clear(int p){
    points.clear();
    for(int i=0;i<=p*4;i++)data[i].clear();
}
int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int tc=1;
    while(t--){
        printf("Case %d:\n",tc++);
        int p,q;

        scanf("%d %d",&p,&q);
        Clear(p);
        getpoints(p);

        CreateArray(p);

        build(1,1,p);
        for(int qq=0;qq<q;qq++){
            ll a,b,c,d;
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);

            int L = upper_bound(Arr+1,Arr+p+1,a-1)-(Arr);
            int R = upper_bound(Arr+1,Arr+p+1,c)-(Arr);

            R--;
            if(L>R){
                printf("0\n");
                continue;
            }
            int ans1 = query(1, 1, p, L, R, b-1);
            int ans2 = query(1, 1, p, L, R, d);

            printf("%d\n",ans1-ans2);
        }

    }
}
