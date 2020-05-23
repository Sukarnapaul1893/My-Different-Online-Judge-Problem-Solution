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

pair<int,int>st,en;
int n,m,lim;
int ans[45][45];
string mat[45];

bool check (int x, int y){
    if(x>=m || y>=n || x<0 || y<0)return false;
    if(mat[x][y]=='s'){
        return true;
    }
    else if(mat[x][y]=='.'){
        return true;
    }
    else if(mat[x][y]=='x'){
        return true;
    }
    else{
        return false;
    }
}

void dfs(int x, int y){
    int cx = x+1;
    int cy = y;
    if(check(cx,cy)){
        int add;
        if(mat[cx][cy]=='.')add=0;
        if(mat[cx][cy]=='x')add=0;
        if(mat[cx][cy]=='s')add=1;
        if(ans[cx][cy]>ans[x][y]+add){
            ans[cx][cy]=ans[x][y]+add;
            dfs(cx,cy);
        }

    }
    cx = x;
    cy = y+1;
    if(check(cx,cy)){
        int add;
        if(mat[cx][cy]=='.')add=0;
        if(mat[cx][cy]=='x')add=0;
        if(mat[cx][cy]=='s')add=1;
        if(ans[cx][cy]>ans[x][y]+add){
            ans[cx][cy]=ans[x][y]+add;
            dfs(cx,cy);
        }
    }
    cx = x-1;
    cy = y;
    if(check(cx,cy)){
        int add;
        if(mat[cx][cy]=='.')add=0;
        if(mat[cx][cy]=='x')add=0;
        if(mat[cx][cy]=='s')add=1;
        if(ans[cx][cy]>ans[x][y]+add){
            ans[cx][cy]=ans[x][y]+add;
            dfs(cx,cy);
        }
    }
    cx = x;
    cy = y-1;
    if(check(cx,cy)){
        int add;
        if(mat[cx][cy]=='.')add=0;
        if(mat[cx][cy]=='x')add=0;
        if(mat[cx][cy]=='s')add=1;
        if(ans[cx][cy]>ans[x][y]+add){
            ans[cx][cy]=ans[x][y]+add;
            dfs(cx,cy);
        }
    }
}

int main(){
    IOS
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>lim;

    for(int i=0;i<n;i++){
        cin>>mat[i];
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j]=lim+1;
            if(mat[i][j]=='@'){
                st = {i,j};
                ans[i][j]=0;
            }
            if(mat[i][j]=='x'){
                en = {i,j};
            }
        }
    }
    int stx = st.first;
    int sty = st.second;

    dfs(stx,sty);

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }*/

    int enx = en.first;
    int eny = en.second;

    if(ans[enx][eny]<=lim/2)cout<<"SUCCESS\n";
    else cout<<"IMPOSSIBLE\n";
}
