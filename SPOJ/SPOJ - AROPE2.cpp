#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#include <ext/rope>
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
using namespace __gnu_cxx;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;




int main(){
    IOS
    //freopen("output.txt","w",stdout);
    string s;
    cin>>s;

    rope<char>rop;

    for(int i=0;i<s.length();i++){
        rop.pb(s[i]);
    }
    int q;
    cin>>q;
    vector<char>ans;
    vector<pair<int,pair<int,int> > > query;
    map<int , vector<int> >mp;
    map<pair<int,int>,char>mp2;
    for(int tt=0;tt<q;tt++){
        int x,y;
        int t;
        cin>>t;
        if(t==3){
            x=-1;
            cin>>y;
            query.pb({3,{x,y}});
        }
        else if(t==4){
            cin>>x>>y;
            mp[x].pb(y);
            query.pb({t,{x,y}});
        }
        else{
            cin>>x>>y;
            if(x>y)swap(x,y);
            query.pb({t,{x,y}});
        }
    }
    for(int tt=0;tt<q;tt++){

        int type;
        type = query[tt].first;
        for(auto it=mp[tt].begin();it!=mp[tt].end();it++){
            mp2[{tt,(*it)}]=rop[(*it)];
        }
        if(type==1){
            int x,y;
            x = query[tt].second.first;
            y = query[tt].second.second;

            if(x==0 && y==s.length()-1)continue;
            auto temp = rop.substr(x,y-x+1);
            rop.erase(x,y-x+1);
            rop.insert(rop.mutable_begin(),temp);
        }
        else if(type==2){
            int x,y;
            x = query[tt].second.first;
            y = query[tt].second.second;

            if(x==0 && y==s.length()-1)continue;
            auto temp = rop.substr(x,y-x+1);
            rop.erase(x,y-x+1);
            rop.insert(rop.mutable_end(),temp);
        }
        else if(type==3){
            int y;
            y = query[tt].second.second;
            ans.pb(rop[y]);
        }
        else{
            int x = query[tt].second.first;
            int y = query[tt].second.second;
            ans.pb(mp2[{x,y}]);
        }

    }
    for(auto it=ans.begin();it!=ans.end();it++){
        cout<<(*it)<<"\n";
    }
}
