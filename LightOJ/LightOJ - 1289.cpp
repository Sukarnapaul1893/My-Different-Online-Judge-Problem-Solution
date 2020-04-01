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
 
int prime[5800000];
bitset <100000010> bs;
int pos;
void sieve (int n){
    bs.set ();
    //prime.pb(2);
    for (int i = 2; i <= n; i++){
        if (bs[i])prime[pos++]=i;
 
        for (int j = 0; j<pos && i*prime[j]<=n; j++){
            bs[i*prime[j]] = 0;
            if(i%prime[j]==0)break;
        }
    }
}
 
 
int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    pos=0;
    sieve(100000000);
    int t;
    scanf("%d",&t);
 
    unsigned int pre_product[pos];
    for(int i=0;i<pos;i++){
        if(i==0){
            pre_product[i]=prime[i];
            continue;
        }
        pre_product[i]=prime[i]*pre_product[i-1];
    }
 
 
    for(int tt=0;tt<t;tt++){
        int n;
        scanf("%d",&n);
 
        int idx = upper_bound(prime,prime+pos,n)-prime;
 
        unsigned int ans=pre_product[idx-1];
        for(int i=0;prime[i]*prime[i]<=n;i++){
            int x=n;
            x/=prime[i];
            while(x/prime[i]){
                ans*=prime[i];
                x/=prime[i];
            }
        }
        printf("Case %d: %u\n",tt+1,ans);
    }
}
