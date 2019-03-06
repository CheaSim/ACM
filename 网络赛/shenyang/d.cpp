#include<bits/stdc++.h>
using namespace std;
#define INF 0xffffff
const int maxn = 100010;
const int maxv = 1000+10;
struct node{
    int to;
    int val;
    int next;
}edge[maxn],edge1[maxn];
struct node1{
    int to;
    int g,f;
    bool operator<(const node1 &r ) const  {  
        if(r.f==f)  
            return r.g<g;  
        return r.f<f;  
    }   
};
int n,m,s,t,k,cnt,cnt1,ans,T;
int dis[maxv],visit[maxv],head[maxv],head1[maxv];
void init(){
    memset(head,-1,sizeof(head));
    memset(head1,-1,sizeof(head1));
    cnt=cnt1=1;
}
void addedge(int from,int to,int val){
    edge[cnt].to=to;
    edge[cnt].val=val;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
void addedge1(int from,int to,int val){
    edge1[cnt1].to=to;
    edge1[cnt1].val=val;
    edge1[cnt1].next=head1[from];
    head1[from]=cnt1++;
}
bool inQ(int s,int n,int head[],node edge[],int dist[])  {  
    queue<int>Q1;  
    int inq[1010];  
    for(int i=0;i<=n;i++)  
    {  
        dis[i]=INF;  
        inq[i]=0;  
    }  
    dis[s]=0;  
    Q1.push(s);  
    inq[s]++;  
    while(!Q1.empty())  
    {  
        int q=Q1.front();  
        Q1.pop();  
        inq[q]--;  
        if(inq[q]>n)
            return false;  
        int k=head[q];  
        while(k>=0)  
        {  
            if(dist[edge[k].to]>dist[q]+edge[k].val)  
            {  
                dist[edge[k].to]=edge[k].val+dist[q];  
                if(!inq[edge[k].to])  
                {  
                    inq[edge[k].to]++;  
                    Q1.push(edge[k].to);  
                }  
            }  
            k=edge[k].next;  
        }  
    }  
    return true;  
}
int AA(int s,int t,int n,int k,int head[],node edge[],int dist[]) 
{  
    node1 e,ne;  
    int cnt=0;  
    priority_queue<node1>Q;  
    if(s==t)
        k++;  
    if(dis[s]==INF)  
        return -1;  
    e.to=s;  
    e.g=0;  
    e.f=e.g+dis[e.to];  
    Q.push(e);  

    while(!Q.empty())  
    {  
        e=Q.top();  
        Q.pop();  
        if(e.to==t)//ÕÒµ½Ò»Ìõ×î¶ÌÂ·¾¶  
        {  
            cnt++;  
        }  
        if(cnt==k)//ÕÒµ½k¶ÌÂ·  
        {  
            return e.g;  
        }  
        for(int i=head[e.to]; i!=-1; i=edge[i].next)  
        {  
            ne.to=edge[i].to;  
            ne.g=e.g+edge[i].val;  
            ne.f=ne.g+dis[ne.to];  
            Q.push(ne);  
        }  
    }  
    return -1;  
}  
void Print(int ans){
    if(ans != -1 && ans <= T)
        printf("yareyaredawa\n");
    else
        printf("Whitesnake!\n");
}
int main()
{
#ifdef LOCAL
    freopen("e.in","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        scanf("%d%d%d%d",&s,&t,&k,&T);
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge1(b,a,c);
            //cout<<a<<' '<<b<<' '<<c<<endl;
        }
        inQ(t,n,head1,edge1,dis);
        ans=AA(s,t,n,k,head,edge,dis);
        Print(ans);
    }
    return 0;
} 
