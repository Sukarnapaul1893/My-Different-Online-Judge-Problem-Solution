#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
#define mset(a,b) memset(a,b,sizeof(a))
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}
using namespace std;
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int main(){
	//IOS
	//freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int tt=0;tt<t;tt++){
        int n,q;
        scanf("%d %d",&n,&q);

        int p[n][20];
        int val[n];
        memset(p,-1,sizeof p);
        val[0]=1;
        p[0][0]=0;
        for(int i=0;i<n-1;i++){
            int P,S;
            scanf("%d %d",&P,&S);
            p[i+1][0]=P;
            val[i+1]=S;

        }

        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                int a = p[j][i-1];
                if(a==-1)continue;
                int b = p[a][i-1];
                if(b!=-1)p[j][i]=b;
            }
        }
        printf("Case %d:\n",tt+1);
        //cout<<p[4][1]<<"\n";
        //cout<<val[0]<<"\n";
        for(int ii=0;ii<q;ii++){
            int k,v;
            scanf("%d %d",&k,&v);
            for(int i=19;i>=0;i--){
                if(p[k][i]==-1)continue;
                //cout<<k<<" "<<i<<"\n";

                if(val[k]==v){
                    printf("%d\n",k);
                    break;
                }
                if(val[p[k][i]]>=v){
                    k = p[k][i];
                    //cout<<k<<"\n";
                }
                if(i==0){
                    printf("%d\n",k);
                    break;
                }

            }
        }
    }


}
