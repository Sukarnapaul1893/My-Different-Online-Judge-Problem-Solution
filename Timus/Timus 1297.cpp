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


/// manachar
int pal[20005];
char s[20005];

int ans ;
int idx;
void manach(char *str){
    int i, now = 0;
    for(i = 0; str[i]!='\0'; i++){
        s[2*i] = str[i];
        s[2*i + 1] = '#';
    }
    s[2*i-1] = '\0';
    pal[0] = 0;
    for(i = 1; s[i]!='\0'; i++){
        pal[i] = max(0,min(pal[now]-(i-now),pal[now-(i-now)])) + 1;
        while(i-pal[i]>=0 && s[i+pal[i]]==s[i-pal[i]]) pal[i]++;
        pal[i]--;
        if(i+pal[i]>now+pal[now]) now = i;
    }
    for(i = 0; s[i]!='\0'; i++){
        if(s[i]=='#'){
            pal[i] = (pal[i]+1)/2;
            if(ans<pal[i]*2)ans = max(ans, pal[i]*2),idx=i;
        }
        else{
            pal[i] = pal[i]/2;
            if(ans<pal[i]*2+1)ans = max(ans, pal[i]*2 + 1),idx=i;
        }
    }
}

int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    char st[10005];
    scanf("%s",st);
    manach(st);
    int lim=pal[idx];
    deque<char>dq;
    if(s[idx]!='#')dq.push_back(s[idx]);
    for(int i=idx-1;i>=0;i--){
        if(lim==0){
            break;
        }

        if(s[i]!='#')dq.push_front(s[i]),lim--;
    }
    lim=pal[idx];
    for(int i=idx+1;;i++){
        if(lim==0){
            break;
        }

        if(s[i]!='#')dq.push_back(s[i]),lim--;
    }
    while(!dq.empty()){
        cout<<dq.front();
        dq.pop_front();
    }
    cout<<"\n";
}
