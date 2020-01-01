#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
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


ll sum[400020];
ll carry[400020];

int n;

ll query(int at, int L, int R, int l, int r){
    if(r<L || R<l){
        sum[at]+=carry[at]*(R-L+1);
        if(L!=R){
            carry[at*2]+=carry[at];
            carry[at*2+1]+=carry[at];
        }
        carry[at]=0;
        return 0;
    }
    if(l<=L && R<=r){
        sum[at]+=carry[at]*(R-L+1);
        if(L!=R){
            carry[at*2]+=carry[at];
            carry[at*2+1]+=carry[at];

        }
        carry[at]=0;
        return sum[at];
    }

    int mid = (L+R)/2;
    carry[at*2]+= carry[at];
    carry[at*2+1]+= carry[at];
    carry[at]=0;
    ll x = query(at*2,L,mid,l,r);
    ll y = query(at*2+1,mid+1,R,l,r);
    sum[at] = sum[at*2]+sum[at*2+1];
    return (x+y);
}

void update(int at, int L, int R, int l, int r, ll v){
    if(R<l || L>r){
        sum[at]+= carry[at]*(R-L+1);
        if(L!=R){
            carry[at*2]+=carry[at];
            carry[at*2+1]+=carry[at];
        }
        carry[at]=0;
        return ;
    }
    if(L>=l && R<=r){
        sum[at]+=(v+carry[at])*(R-L+1);
        carry[at]=v+carry[at];

        if(L!=R){
            carry[at*2]+=carry[at];
            carry[at*2+1]+=carry[at];
        }
        carry[at]=0;
        return ;
    }
    carry[at*2]+=carry[at];
    carry[at*2+1]+=carry[at];
    carry[at]=0;

    int mid = (L+R)/2;
    update(at*2,L,mid,l,r,v);
    update(at*2+1,mid+1,R,l,r,v);

    sum[at] = sum[at*2]+sum[at*2+1];
}

void build(int at , int L, int R){
    carry[at]=0;
    if(L==R){
        sum[at]=0;

        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    sum[at] = sum[at*2] + sum[at*2+1];

}

int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int q;
        scanf("%d %d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",tt+1);
        for(int qq=0;qq<q;qq++){
            int type ;
            scanf("%d",&type);
            if(type==0){
                int x,y;
                ll v;

                scanf("%d %d %lld",&x,&y,&v);
                x++;
                y++;
                update(1,1,n,x,y,v);
            }
            else{
                int x,y;
                scanf("%d %d",&x,&y);
                x++;
                y++;
                ll ans = query(1,1,n,x,y);
                printf("%lld\n",ans);
            }
        }
        //memset(carry,0,sizeof carry);

    }
}
