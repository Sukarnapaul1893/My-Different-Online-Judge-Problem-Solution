#include<bits/stdc++.h>
#define pb push_back

using namespace std;

vector<int>adj[68];

int m(int a){
    if(a%8==0)return 8;
    else return a%8;
}

void pre(){
    for(int i=1;i<=64;i++){

        if(i+10>=1 && i+10<=64 && m(i)<m(i+10))adj[i].pb(i+10);
        if(i+6>=1 && i+6<=64 && m(i)>m(i+6))adj[i].pb(i+6);
        if(i-10>=1 && i-10<=64 && m(i)>m(i-10))adj[i].pb(i-10);
        if(i-6>=1 && i-6<=64 && m(i)<m(i-6))adj[i].pb(i-6);
        if(i+15>=1 && i+15<=64 && m(i)>m(i+15))adj[i].pb(i+15);
        if(i+17>=1 && i+17<=64 && m(i)<m(i+17))adj[i].pb(i+17);
        if(i-15>=1 && i-15<=64 && m(i)<m(i-15))adj[i].pb(i-15);
        if(i-17>=1 && i-17<=64 && m(i)>m(i-17))adj[i].pb(i-17);

    }
}
bool vis[100];
int ans ;
void bfs(int s, int des ){
    vis[s]=true;
    int level =0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            int u = q.front();
            if(u==des){
                ans=level;
                return ;
            }
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                int cur = adj[u][i];
                if(vis[cur]==false){
                    vis[cur]=true;
                    q.push(cur);
                }
            }

        }
        level++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int t;
    cin>>t;

    while(t--){
        for(int i=0;i<=64;i++){
            vis[i]=false;
        }
        string a,b;
        cin>>a>>b;
        ans = 200;
        int a1 = a[0]-'a';
        int a2 = a[1]-'0';

        int b1 = b[0]-'a';
        int b2 = b[1]-'0';

        int start = a1*8+a2;
        int End = b1*8+b2;
        //cout<<start<<" "<<End<<endl;
        bfs(start,End);
        cout<<ans<<"\n";
    }
}
