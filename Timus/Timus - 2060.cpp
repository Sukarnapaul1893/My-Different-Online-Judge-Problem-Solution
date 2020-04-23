//Author : Sukarna Paul

#include<bits/stdc++.h>

#define pi acos(-1)
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define N 300005
#define INF 0x3f3f3f3f

using namespace std;


int pal[2*N];
char s[2*N];
int ses[2*N];
int shuru[2*N];

ll ans ;



void manach(char *str){
    int i;
    int now = 0;
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
        shuru[i-pal[i]]++;
        ses[i+pal[i]]++;
        shuru[i+1]--;
        ses[i-1]--;
        if(s[i]=='#') pal[i] = (pal[i]+1)/2;
        else pal[i] = pal[i]/2;
    }

    for(int i=strlen(s)-1;i>=0;i--){
        if(i!=strlen(s)-1)ses[i]+=ses[i+1];
    }
    for(i = 0; s[i]!='\0'; i++){
        if(i!=0)shuru[i]+=shuru[i-1];
        ll u = shuru[i];
        ll v = ses[i-2];
        if(i>0 && i%2==0)ans+=(u*v);
        //cout<<s[i]<<" "<<pal[i]<<" "<<shuru[i]<<" "<<ses[i]<<"\n";
    }


}


char arr[N];
int main(){
    //IOS
    //freopen("output.txt","w",stdout);

    scanf("%s",arr);
    manach(arr);
    //string str= arr;
    //solve(str);
    printf("%lld\n",ans);
    //cout<<answ<<"\n";
}
//edklscvvs
//eertree
