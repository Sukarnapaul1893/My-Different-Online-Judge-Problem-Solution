#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sum[400020];
ll arr[100005];

int query(int at, int L, int R, int l, int r){
    if(r<L || R<l)return 0;

    if(l<=L && R<=r)return sum[at];

    int mid = (L+R)/2;

    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);

    return (x+y);
}

void update(int at, int L, int R, int pos, ll u ){
    if(L==R){
        sum[at]+=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }

    sum[at] = sum[at*2] + sum[at*2+1];
}

void build(int at , int L, int R){
    sum[at]=0;
    if(L==R){
        sum[at]=arr[L];
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    sum[at] = sum[at*2] + sum[at*2+1];

}


int main(){
    int t;
    scanf("%d",&t);
    for(int tt=0;tt<t;tt++){
        int n,q;
        scanf("%d %d",&n,&q);

        for(int i=1;i<=n;i++){
            ll val;
            scanf("%lld",&val);
            arr[i]=val;
        }
        build(1,1,n);
        printf("Case %d:\n",tt+1);
        for(int i=0;i<q;i++){
            int type;
            scanf("%d",&type);

            if(type==1){
                int a;
                scanf("%d",&a);
                ll diff = query(1,1,n,a+1,a+1);
                printf("%d\n",diff);
                //arr[a+1]=0;
                update(1,1,n,a+1,-diff);
            }
            else if(type==2){
                int a;
                ll v;
                scanf("%d %lld",&a,&v);
                update(1,1,n,a+1,v);
            }
            else if(type==3){
                int L,R;
                scanf("%d %d",&L,&R);
                printf("%d\n",query(1,1,n,L+1,R+1));
            }
        }

    }
}
