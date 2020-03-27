//Author : Sukarna Paul

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll int64_t
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

ll nCr(int n, int k)
{
    ll ans[n+1][k+1];
    int i,j;

    for(int i = 0; i <= n; i++){

        for(int j = 0; j <= min(i,k); j++){

            if(j == 0 || j == i)
                ans[i][j] = 1;
            else{
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
    }
    return ans[n][k];
}


int main(){
    //IOS
    //freopen("output.txt","w",stdout);


    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){

        ll n;
        scanf("%lld",&n);
        ll k;
        scanf("%lld",&k);
        printf("Case %d: ",tt+1);
        if(n<k){
            printf("0\n");
            continue;
        }
        ll ans = nCr(n,k);
        for(ll i=n;i>n-k;i--){
            ans*=i;
        }


        printf("%lld\n",ans);
    }
}
