#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define debug(x) cerr<<#x<<" = "<<(x)<<endl
#define eps 1e-8
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN=(int)1e6+5;
const int MOD=(int)1e9+7;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int>p[MAXN];
vector<pii>ve[MAXN];
int n,m;
void add(int x,int y,int z){
    for(int i=x;i<=n;i+=i&-i){
        for(int j=y;j<=m;j+=j&-j){
            p[i][j]+=z;
        }
    }
}
int query(int x,int y){
    int re=0;
    for(int i=x;i;i-=i&-i){
        for(int j=y;j;j-=j&-j){
            re+=p[i][j];
        }
    }
    return re;
}
void add(int a,int b,int x,int y,int f){
    add(a,b,f);
    add(x+1,y+1,f);
    add(a,y+1,-f);
    add(x+1,b,-f);
}
void init(){
    for(int i=1;i<=n;i++)p[i].resize(m+1);
}
struct node{
    int a,b,x,y,k;
    void scan(){
        a=read();b=read();x=read();y=read();k=read();
    }
};
vector<node>op[MAXN];
 
int main()
{
    int q;
    n=read();m=read();q=read();
    init();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;x=read();
            ve[x].push_back(mp(i,j));
        }
    }
    for(int i=1;i<=q;i++){
        node now;
        now.scan();
        op[now.k].push_back(now);
        add(now.a,now.b,now.x,now.y,1);
    }
    int ans=0;
    for(int i=1;i<=n*m;i++){
           // debug(i);
        if(!ve[i].empty()){
            for(auto opi:op[i])add(opi.a,opi.b,opi.x,opi.y,-1);
            for(auto x:ve[i])if(query(x.fi,x.se))ans++;
            for(auto opi:op[i])add(opi.a,opi.b,opi.x,opi.y,1);
            //debug(ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
