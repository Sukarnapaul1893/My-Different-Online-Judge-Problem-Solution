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



int z[200005];

string Zfunction(string s){
    int n=s.length();

    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
    int ans;
    int mx=-1;
    for(int i=1;i<n;i++){
        if(z[i]>mx){
            ans=i;
            mx=z[i];
        }
    }
    string str(s.begin(),s.begin()+z[ans]);
    return str;
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);
    string a;
    string b;
    cin>>a>>b;

    string s = a+"#"+b;
    Zfunction(s);

    int curend = s.length();
    vector<string>vec;
    int cnt = 0;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='#')break;
        if(z[i]+i>=curend){
            string str="";
            for(int j=i;j<curend;j++)str+=s[j],cnt++;
            vec.pb(str);
            curend=i;
        }
    }
    if(cnt!=b.length()){
        cout<<"Yes\n";
        return 0;
    }
    cout<<"No\n";
    for(int i=vec.size()-1;i>=0;i--){
        if(i!=0)cout<<vec[i]<<" ";
        else cout<<vec[i]<<"\n";
    }
}
