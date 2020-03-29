#include<iostream>
#include<string.h>
#define N 100005
using namespace std;

/// suffix array
int cmp_for_sa(int *r,int a,int b,int l){
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);
}
int wa[N],wb[N],wws[N],wv[N],rnk[N],lcp[N], sa[N],data[N];
void DA(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wws[i]=0;
    for(i=0;i<n;i++) wws[x[i]=r[i]]++;
    for(i=1;i<m;i++) wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wws[i]=0;
        for(i=0;i<n;i++) wws[wv[i]]++;
        for(i=1;i<m;i++) wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++) x[sa[i]]=cmp_for_sa(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void cal_lcp(int *r,int *sa,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rnk[sa[i]]=i;
    for(i=0;i<n;lcp[rnk[i++]]=k)
        for(k?k--:0,j=sa[rnk[i]-1];r[i+k]==r[j+k];k++);
}
void suffix_array (char *A){
    int n = strlen(A) ;
    for(int i = 0; i<=128; i++){
        wa[i] = wb[i] = wws[i] = wv[i] = rnk[i] = lcp[i] = sa[i] = data[i] = 0;
    }
    for (int i = 0 ; i <= n ; i++) {
        wa[i] = wb[i] = wws[i] = wv[i] = rnk[i] = lcp[i] = sa[i] = data[i] = 0;
        if(i<n) data[i] = A[i] ;
    }
    DA(data,sa,n+1,128);
    cal_lcp(data,sa,n);
    for (int i = 0 ; i < n ; i++) { /// transforming it into 0-based SA
        sa[i] = sa[i+1] ;
        lcp[i] = lcp[i+2] ;
        rnk[i]--;
    }
}


char s[100005];
char nds[100005];

void init(int n){
    for(int i=0;i<n+5;i++){
        wa[i]=0;
        wb[i]=0;
        wws[i]=0;
        wv[i]=0;
        rnk[i]=0;
        lcp[i]=0;
        sa[i]=0;
        data[i]=0;
        s[i]='\0';
        nds[i]='\0';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("output.txt","w",stdout);
    int t;
    cin>>t;

    for(int tt=0; tt<t;tt++){

        string s1;
        cin>>s1;

        string s2;
        cin>>s2;

        string s3;
        cin>>s3;

        string S = s1+"$"+s2+"#"+s3;
        init(S.length());
        int cur=0;
        int mp[S.length()+1];
        memset(mp,0,sizeof mp);
        for(int i=0;i<S.length();i++){
            s[i]=S[i];
            if(s[i]=='$' || s[i]=='#'){
                cur++;
                mp[i]=3;
                continue;
            }
            mp[i]=cur;
        }

        suffix_array (s);


        int ans = 0;
        int lst[4];
        memset(lst,0,sizeof lst);
        //continue;
        for(int i=0;i<S.length()-1;i++){
            lst[mp[sa[i]]]=lcp[i];
            lst[mp[sa[i+1]]]=lcp[i];
            lst[0]=min(lst[0], lcp[i]);
            lst[1]=min(lst[1], lcp[i]);
            lst[2]=min(lst[2], lcp[i]);
            ans = max(min(lst[0],min(lst[1],lst[2])),ans);

        }
        cout<<"Case "<<tt+1<<": "<<ans<<"\n";
    }


}
