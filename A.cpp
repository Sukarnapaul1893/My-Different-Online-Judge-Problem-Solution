#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,k;
vector<ll>vec;

void Input();

void Solve(){
    sort(vec.begin(),vec.end());

    for(int i=0;i<k;i++){
        int x;
        cin>>x;

        int lo = 0;
        int hi = n-1;

        bool flag = false;

        while(lo<=hi){

            int mid = (lo+hi)/2;

            if(vec[mid]==x){
                flag = true;
                break;
            }
            else if(vec[mid]<x){
                lo = mid+1;
            }
            else if(vec[mid]>x){
                hi = mid-1;
            }

        }

        if(flag)    cout<<"YES\n";
        else        cout<<"NO\n";
    }
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
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.pb(x);
    }
}
