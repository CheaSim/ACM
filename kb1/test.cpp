#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define rep(i,f,t) for(int i = (f),_end = (t);  i <= _end; ++i)
#define MID int mid = (L+R)>>1;
#define CHD int lc = node<<1, rc = node<<1|1;

const int maxn = 100001<<2;

struct sgt{
    int maxlen[maxn];
    int left[maxn], middle[maxn], right[maxn];
    int setv[maxn];
    void init(){
        setv[1] = 1;
    }
    void maintain(int node,int L,int R){
        if(setv[node] >= 0){
            maxlen[node] = left[node] = right[node] = middle[node] = 
                (setv[node] ? (R-L+1) : 0);
        } else {
            CHD;MID;
            left[node] = left[lc];
            if(left[lc]==(mid-L+1)) left[node] += left[rc];
            middle[node] = right[lc]+left[rc];
            right[node] = right[rc];
            if(right[rc]==R-mid)    right[node] += right[lc];
            maxlen[node] = max(max(maxlen[lc],maxlen[rc]),middle[node]);
        }
    }
    void pushDown(int node){
        if(setv[node] >= 0){
            CHD;
            setv[lc] = setv[rc] = setv[node];
            setv[node] = -1;
        }
    }

    int query(int val,int node,int L,int R){
        maintain(node,L,R);
        if(val > maxlen[node])return 0; //不在此结点上
        if(left[node] >= val)return L;  //left
        MID;CHD;
        pushDown(node);
        maintain(rc,mid+1,R); //先维护好右结点信息，方便直接返回
        int tmp;
        if((tmp=query(val,lc,L,mid))) return tmp; //leftmax
        if(middle[node] >= val) return mid-right[lc]+1; //middle
        return query(val,rc,mid+1,R); //肯定在右结点上
    }

    void update(int from,int to,int val,int node,int L,int R){
        if(from <= L && R <= to){
            setv[node] = val;
        }else{
            pushDown(node);
            MID;CHD;
            if(from <= mid) update(from,to,val,lc,L,mid);
            else    maintain(lc,L,mid);
            if(to > mid) update(from,to,val,rc,mid+1,R);
            else    maintain(rc,mid+1,R);
        }
        maintain(node,L,R);
    }
}ns,all;

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    rep(cas,1,T){
        int n,m;
        scanf("%d%d",&n,&m);
        ns.init();all.init();
        printf("Case %d:\n",cas);
        while(m--){
            char s[10];int a,b;
            int ans;
            scanf("%s",s);
            switch(s[0]){
                case 'N':
                    scanf("%d",&a);
                    if((ans=all.query(a,1,1,n))||(ans=ns.query(a,1,1,n))){
                        all.update(ans,ans+a-1,0,1,1,n);
                        ns.update(ans,ans+a-1,0,1,1,n);
                        printf("%d,don\'t put my gezi\n",ans);
                    } else {
                        printf("wait for me\n");
                    }
                    break;
                case 'D':
                    scanf("%d",&a);
                    ans = all.query(a,1,1,n);
                    if(ans){
                        all.update(ans,ans+a-1,0,1,1,n);
                        printf("%d,let\'s fly\n",ans);
                    }else{
                        printf("fly with yourself\n");
                    }
                    break;
                case 'S':
                    scanf("%d%d",&a,&b);
                    all.update(a,b,1,1,1,n);
                    ns.update(a,b,1,1,1,n);
                    printf("I am the hope of chinese chengxuyuan!!\n");
                    break;
            }
        }
    }
    return 0;
}
