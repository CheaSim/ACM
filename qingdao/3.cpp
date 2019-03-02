#include<bits/stdc++.h>
using namespace std;

#define debug puts("YES");
#define rep(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define read(x,y) scanf("%d%d",&x,&y)
#define ll long long

#define lrt int l,int r,int rt
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int  maxn =1e4+5;
const int mod=256;

int n,q;
char op[maxn][30];
int tp[maxn][2],x,y;
int val[maxn][256];

int main()
{
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    int t;scanf("%d",&t);
    int ttt = 0;
    while(t--)
    {
        ttt++;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%s",op[i]);
            if(op[i][0]=='a')
            {
                scanf("%d",&x);
                tp[i][0]=x;
            }
            else
            {
                scanf("%d%d",&x,&y);
                tp[i][0]=x,tp[i][1]=y;
            }
        }

        int num=0,tmp,flag=1;
        int cnt=0;
        for(int i=1;i<=q;i=tmp,cnt++)
        {
            if(val[i][num]==ttt) {flag=0;break;}
            else val[i][num]=ttt;
            if(op[i][0]=='a')   ///添加操作
            {
                num+=tp[i][0];
                num%=mod;
                tmp=i+1;
            }
            else if(op[i][1]=='e')
            {
                if(tp[i][0]==num)  tmp=tp[i][1];
                else tmp=i+1;
            }
            else if(op[i][1]=='n')
            {
                if(tp[i][0]!=num)  tmp=tp[i][1];
                else tmp=i+1;
            }
            else if(op[i][1]=='l')
            {
                if(tp[i][0]>num)  tmp=tp[i][1];
                else tmp=i+1;
            }
            else if(op[i][1]=='g')
            {
                if(tp[i][0]<num)  tmp=tp[i][1];
                else tmp=i+1;
            }
        }
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
