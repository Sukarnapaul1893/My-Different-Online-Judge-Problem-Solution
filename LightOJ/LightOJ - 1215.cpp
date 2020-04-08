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




int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        ll a,b;
        ll L;
        scanf("%lld %lld %lld",&a,&b,&L);
        ll ans =1LL;
        unordered_map<ll,int>u1;
        unordered_map<ll,int>u2;
        unordered_map<ll,int>u3;

        for(ll i=2;i*i<=L;i++){
            while(L%i==0){
                u1[i]++;
                L/=i;
            }
        }
        if(L>1)u1[L]++;

        for(ll i=2;i*i<=a;i++){
            while(a%i==0){
                u2[i]++;
                a/=i;
                if(u2[i]>u1[i])ans=-1;
            }
        }
        if(a>1){
            u2[a]++;
            if(u2[a]>u1[a])ans=-1;
        }
        for(ll i=2;i*i<=b;i++){
            while(b%i==0){
                u3[i]++;
                b/=i;
                if(u3[i]>u1[i])ans=-1;
            }
        }
        if(b>1){
            u3[b]++;
            if(u3[b]>u1[b])ans=-1;
        }
        //cout<<ans<<"\n";

        for(auto it=u1.begin();it!=u1.end();it++){
            ll x = (*it).first;
            if(max(u2[x],u3[x])==u1[x])u1[x] =0;
        }
        for(auto it=u1.begin();it!=u1.end();it++){
            ll x = (*it).first;

            if(u1[x]<=0)continue;

            for(int i=0;i<u1[x];i++){
                ans*=x;
            }
        }
        if(ans<0){
            printf("Case %d: impossible\n",tt+1);
            continue;
        }
        printf("Case %d: %lld\n",tt+1,ans);
    }
}
