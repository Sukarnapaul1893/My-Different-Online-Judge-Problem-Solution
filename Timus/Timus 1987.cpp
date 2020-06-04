#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,m;

vector<pair<pair<ll,char >, int > >points;

ll p[100005];

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        points.pb({{a,'a'},i+1});
        points.pb({{b,'c'},i+1});
    }
    cin>>m;
    for(int i=0;i<m;i++){

        cin>>p[i];
        points.pb({{p[i],'b'},-1});
    }
}

unordered_map<ll,int>ans;

void solve(){
    sort(points.begin(),points.end());
    stack<int >open;
    for(int i=0;i<points.size();i++){
        ll a = points[i].first.first;
        int ch = points[i].first.second;
        int idx = points[i].second;
        if(ch=='a')open.push(idx);
        else if(ch=='b'){
            if(open.size()==0){
                ans[a]=-1;
            }
            else{
                int A = open.top();
                ans[a]=A;
            }
        }
        else {
            open.pop();
        }
    }

    for(int i=0;i<m;i++){
        if(ans[p[i]]==0)ans[p[i]]=-1;
        cout<<ans[p[i]]<<"\n";

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);


    input();

    solve();
}
