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


string multiply( string a, long long b ) {
    // a contains the biginteger in reversed form
    int carry = 0;
    for( int i = 0; i < a.size(); i++ ) {
        carry += (a[i] - 48) * b;
        a[i] = ( carry % 10 + 48 );
        carry /= 10;
    }
    while( carry ) {
        a += ( carry % 10 + 48 );
        carry /= 10;
    }
    return a;
}
vector<pair<ll,ll> >vec[10004];
void pre(){
    for(ll i=2;i<=10000;i++){
        ll cur = i;
        ll sq = sqrt(cur)+1;
        for(ll j=2;j<=sq+1;j++){
            ll cnt = 0;
            while(cur % j==0){
                cur/=j;
                cnt++;
            }
            if(cnt>0)vec[i].pb({j,cnt});
        }
        if(cur>1)vec[i].pb({cur,1LL});
    }
}
unordered_map<ll,ll>mp;
int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    pre();
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int n;
        scanf("%d",&n);
        ll arr[n+1];
        string ans= "1" ;

        for(int i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            if(arr[i]==1)continue;
            for(int j=0;j<vec[arr[i]].size();j++){
                ll u = vec[arr[i]][j].first;
                ll v = vec[arr[i]][j].second;
                mp[u]= max(mp[u],v);
            }
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            ll lim = (*it).second;
            ll m = (*it).first;
            for(int i=0;i<lim;i++){
                string temp =  multiply(ans,m);
                ans="";
                ans += temp;
            }
        }
        reverse(ans.begin(),ans.end());
        printf("Case %d: ",tt+1);
        for(int i=0;i<ans.size();i++){
            char c = ans[i];
            printf("%c",c);
        }
        printf("\n");
        mp.clear();
    }
}
