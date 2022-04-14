#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int L;

void Input();

void Solve(){
    L-=2;
    if(L==-1)    cout<<0<<"\n";
    else if(L&1) cout<<max(0,(L/2)+1)<<"\n";
    else    cout<<max(0,(L/2))<<"\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();
    Solve();
    Clear();

}

void Input(){
    cin>>L;
}
