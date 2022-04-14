#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int m,n;
int t[1003];

void Input();

void Solve(){
    sort(t,t+n);
    int sum = 0;
    for(int i=0;i<n;i++){
        if(sum+t[i]>m){
            cout<<i<<"\n";
            return;
        }
        else{
            sum+=t[i];
        }
    }
    cout<<n<<"\n";
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
    cin>>m;
    cin>>n;
    for(int i=0;i<n;i++)cin>>t[i];
}
