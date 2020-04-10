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

const int MAx = 1<<16;

int dp[17][MAx];
int cost[17][17];
int n;


int rec(int groom, int mask){
    if(groom>=n)return 0;
    if(dp[groom][mask]!=-1)return dp[groom][mask];

    int mx = 0;
    for(int i=0;i<n;i++){
        if((mask&(1<<i)) != 0)continue; //married before
        int ans = cost[groom][i]+rec(groom+1,(mask|(1<<i)));
        mx = max(ans,mx);
    }
    return dp[groom][mask]=mx;
}
void Clear(){
    memset(dp,-1,sizeof dp);
    memset(cost,0,sizeof cost);
}
int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        Clear();
        scanf("%d",&n);

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){
                scanf("%d",&cost[i][j]);
            }
        }
        int ans = rec(0,0);
        printf("Case %d: %d\n",tt+1,ans);
    }

}
