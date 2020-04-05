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

int N2[1000006];
int N5[1000006];
int Nf2[1000006];
int Nf5[1000006];

void pre(){
    for(int i=1;i<1000001;i++){
        int cur = i;
        while(cur%2==0){
            N2[i]++;
            cur/=2;
        }
        while(cur%5==0){
            N5[i]++;
            cur/=5;
        }

    }

    for(int i=1;i<1000001;i++){
        Nf2[i]=Nf2[i-1]+N2[i];
        Nf5[i]=Nf5[i-1]+N5[i];

    }
}


int main(){
    //IOS
    //freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    pre();
    for(int tt=0;tt<t;tt++){
        int n,r,p,q;
        scanf("%d %d %d %d",&n,&r,&p,&q);

        int ans2 = (Nf2[n]-(Nf2[r]+Nf2[n-r])) + (N2[p]*q);
        int ans5 = (Nf5[n]-(Nf5[r]+Nf5[n-r])) + (N5[p]*q);
        printf("Case %d: %d\n",tt+1,min(ans2,ans5));

    }
}
