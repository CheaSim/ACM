#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)
#define per(i,a,n) for(int i=(n-1);i>=(a);i--)
#define fi first
#define se second
typedef pair <int,int> pII;
typedef long long ll;
const int INF = 0x3f3f3f3f;
//head

const int maxn = 5e5+10;
int sum[maxn];
vector<int> findMax(vector<ll>num)
{
    vector<int>res(num.size());
    int i=0;
    stack<int>s;
    while(i<num.size())
    {
        if(s.empty()||num[s.top()]<=num[i])
        {
            s.push(i++);
        }
        else
        {
            res[s.top()]=num[i];
            s.pop();
        }
    }
    while(!s.empty())
    {
        res[s.top()]=INT_MAX;
        s.pop();
    }
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<endl;
    return res;
}
int n;
ll num[maxn];
ll ans = -INF;
void solve(vector<ll> a,int st){
    for(auto x:a) cout<<x<<' ';
    cout<<endl;
    vector<int> right = findMax(a);
    reverse(a.begin(),a.end());
    vector<int> left = findMax(a);
    reverse(left.begin(),left.end());
    int len  = a.size();

    rep(i,0,len){
        ans = max(ans,(sum[right[i]+st] - sum[left[i]-1+st])*a[i]);
    }
}
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%lld",num+i);
    rep(i,1,n+1) sum[i] += sum[i-1] + num[i];
    vector<ll> ve;
    int st = 1;
    rep(i,1,n+1){
        if(num[i] > 0){
            ve.push_back(num[i]);
        }else{
            solve(ve,st);
            ve.clear();
            st = i+1;
        }
    }
    if(num[n] > 0) solve(ve,st);
    printf("%d\n",ans);

    return 0;
}
