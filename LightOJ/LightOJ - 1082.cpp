#include<bits/stdc++.h>

using namespace std;

const int MAXN = 105000;
const int MAXLOG = 20;

int n;
int logs[MAXN];


void computeLogs(){
    logs[1] = 0;
    for(int i=2;i<=n;i++){
        logs[i] = logs[i/2]+1;
    }
}


int a[MAXN];
int table[MAXLOG][MAXN];

void buildSparseTable(){
    computeLogs();
    for(int i=0;i<=logs[n];i++){
        int curlen = 1<<i;
        for(int j=0;j+curlen<=n;j++){
            if(curlen==1){
                table[i][j]=a[j];
            }
            else{
                table[i][j]=min(table[i-1][j],table[i-1][j+curlen/2]);
            }
        }
    }
}


int getMin(int l, int r){
    int p = logs[r-l+1];
    int pLen=1<<p;
    return min(table[p][l], table[p][r-pLen+1]);

}


int main(){
    int t;
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++){
        int q;
        scanf("%d %d",&n,&q);
        for(int i=0;i<n;i++)cin>>a[i];
        buildSparseTable();
        printf("Case %d:\n",tt+1);
        for(int i=0;i<q;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            l--,r--;
            printf("%d\n",getMin(l,r));
        }
        for(int i=0;i<n;i++)a[i]=0;
    }
}
