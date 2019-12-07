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




int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int n,q;
        scanf("%d %d",&n,&q);
        vector<pair<int,int> >vec;


        for(int i=0;i<n;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            vec.pb({a,0});
            vec.pb({b,1});

        }
        sort(vec.begin(),vec.end());
        vector<int>query;
        int p[q];
        for(int i=0;i<q;i++){
            scanf("%d",&p[i]);
            query.pb(p[i]);
        }
        sort(query.begin(),query.end());
        unordered_map<int,int>ans;
        int cq=0;
        int cur=0;
        for(int i=0;i<vec.size();i++){

            if(query[cq]<vec[i].first){
                ans[query[cq]]=max(ans[query[cq]],cur);
                cq++;
                if(cq>=q)break;
                i--;
                continue;
            }
            else if(query[cq]==vec[i].first){
                ans[query[cq]]=max(ans[query[cq]],cur);
            }

            if(vec[i].second==0)cur++;
            else cur--;
        }
        printf("Case %d:\n",tt+1);
        for(int i=0;i<q;i++){
            printf("%d\n",ans[p[i]]);
        }

    }
}
