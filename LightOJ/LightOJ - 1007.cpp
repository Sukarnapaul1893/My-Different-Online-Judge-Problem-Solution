
//Author : Sukarna Paul

#include<bits/stdc++.h>

#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll unsigned long long
#define MAX 300005
#define INF 0x3f3f3f3f

using namespace std;



ll phi[5000006];
bool mark[5000006];

void sievephi(ll n){
    ll i,j;
    for(i = 1; i <= n; i++) phi[i] = i;
    phi[1] = 1;
    mark[1] = true;
    for(i = 2;i <= n;i += 2){
        if(i != 2) mark[i] = true;
        phi[i] = phi[i] / 2;
    }
    for(i = 3; i <=n; i += 2)
        if(!mark[i]){
            phi[i] = phi[i]-1;
        for(j = 2*i; j <= n;j += i){
            mark[j] = true;
            phi[j] = phi[j] / i *(i -1);
        }
    }
}



int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int t;
    sievephi(5000004);
    scanf("%d",&t);
    for(int i=2;i<5000003;i++){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
    for(int tt=0;tt<t;tt++){
        int a,b;
        scanf("%d %d",&a,&b);
        ll ans =phi[b] - phi[a-1];
        printf("Case %d: %llu\n",tt+1,ans);
    }
}
