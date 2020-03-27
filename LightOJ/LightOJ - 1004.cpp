//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll unsigned long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;




int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){


        int n;
        scanf("%d",&n);
        vector<ll>dp(n+1,0);

        for(int j=0;j<n;j++){
            vector<ll>newdp;
            for(int i=0;i<=j;i++){
                ll a;
                scanf("%lld",&a);
                if(i==0)newdp.pb(dp[i]+a);
                else if(i==j)newdp.pb(dp[i-1]+a);
                else newdp.pb(max(dp[i]+a,dp[i-1]+a));
            }
            dp=newdp;

        }
        for(int j=0;j<n-1;j++){
            vector<ll>newdp;
            for(int i=0;i<=n-j-2;i++){
                ll a;
                scanf("%lld",&a);
                newdp.pb(max(dp[i]+a,dp[i+1]+a));
            }
            dp=newdp;
        }
        printf("Case %d: %lld\n",tt+1,dp[0]);

    }
}
