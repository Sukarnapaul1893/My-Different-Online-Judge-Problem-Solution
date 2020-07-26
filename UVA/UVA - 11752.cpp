#include<bits/stdc++.h>
#define ll unsigned long long
#define pb push_back

using namespace std;

void input();

map<ll,int>mark;

void MarkingPrime(){
    ll arr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        mark[arr[i]]++;
    }
}
set<ll>st;
void solve(){
    MarkingPrime();
    st.insert(1);
    ll lim = ((1LL<<64) - 1);

    bool bl=false;
    for(ll i=2;;i++){
        ll a = i;

        for(ll j = 2;;j++){

            if(mark[j]==1){
               if(lim/a<i){
                    if(j==4)bl=true;
                    break;
               }
               a*=i;
               continue;
            }
            if(lim/a<i){
                if(j==4)bl=true;
                break;
            }
            a*=i;
            st.insert(a);
        }
        if(bl==true)break;
    }

    for(auto it = st.begin();it!=st.end();it++){
        cout<<(*it)<<"\n";
    }
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
    Clear();
}

void input(){

}
