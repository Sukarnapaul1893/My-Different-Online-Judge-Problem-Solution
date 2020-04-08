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
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        ll n;
        scanf("%lld",&n);

        string s="";
        while(n>0LL){
            if(n%2LL==0LL){
                s+='0';
            }
            else{
                s+='1';
            }
            n/=2LL;
        }
        int len = s.length();
        s+='0';
        //cout<<s<<"\n";
        for(int i=0;i<s.length();i++){

            if(s[i]=='1' && s[i+1]=='0'){

                s[i]='0';
                s[i+1]='1';
                sort(s.begin(),s.begin()+i+1);
                reverse(s.begin(),s.begin()+i+1);
                break;
            }
        }
        //fcout<<s<<"\n";
        ll pw =1LL;

        ll ans = 0LL;
        for(int i=0;i<s.length();i++){

            if(s[i]=='1'){
                ans+=pw;
            }
            pw<<=1;
        }
        printf("Case %d: %lld\n",tt+1,ans);
    }
}
