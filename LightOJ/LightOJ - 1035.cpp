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

vector<pair<int,int> >query;
vector<pair<int,int> >query2;
unordered_map<int ,int>mp;
vector<pair<int,int> >ans[105];
void pre(){
    int now=0;
    for(int j=1;j<=100;j++){
        int n = j;
        for(int i=2;i*i<=j;i++){
            while(n%i==0){
                n/=i;
                mp[i]++;
            }
        }
        if(n>1)mp[n]++;
        for(auto it=mp.begin();it!=mp.end();it++){
            ans[j].pb({(*it).first,(*it).second});
        }

    }

}
int main(){
    //IOS
    //freopen("output.txt","w",stdout);


    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int n;
        scanf("%d",&n);
        query.pb({n,tt});
        query2.pb({n,tt});
    }
    sort(query.begin(),query.end());
    pre();

    for(int i=0;i<t;i++){
        int cur = query2[i].first;
        printf("Case %d: %d = ",i+1,cur);
        sort(ans[cur].begin(),ans[cur].end());
        for(int j=0;j<ans[cur].size();j++){
            if(j>0)printf("* ");
            printf("%d (%d)",ans[cur][j].first,ans[cur][j].second);
            if(j!=ans[cur].size()-1)printf(" ");
        }
        printf("\n");
    }

}
