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



int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0;tt<t;tt++){
        ll n;
        cin>>n;
        bool sn=true;
        if(n<0){
            sn=false;
            n= abs(n);
        }
        vector<ll>vec;
        ll sqrn=sqrt(n)+1;
        for(ll i=2;i<=sqrn;i++){
            ll p=0;
            while(n%i==0){
                p++;
                n/=i;

            }
            if(p>0)vec.pb(p);
        }
        cout<<"Case "<<tt+1<<": ";
        if(vec.size()==0){
            cout<<1<<"\n";
            continue;
        }
        sort(vec.begin(),vec.end());
        bool bl=true;
        ll g;
        for(int i=0;i<vec.size();i++){
            if(i==0){
                g=vec[i];
                continue;
            }
            g= __gcd(vec[i],g);
        }
        if(sn==false){
            if(vec[0]%2LL==1){
                cout<<g<<"\n";
            }
            else{
                int cur = g;
                while(cur%2==0){
                    cur/=2;

                }
                cout<<cur<<"\n";
            }
        }
        else{
            cout<<g<<"\n";
        }
    }
}
