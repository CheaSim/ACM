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

const int maxn = 1e3+10;
int idx[maxn][maxn];
int col_idx[maxn][maxn];
int mx[maxn][maxn];
int n,m;
int cnt_row[maxn];
int cnt_col[maxn];
int ans[maxn][maxn];
int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    rep(i,0,n) rep(j,0,m){
        scanf("%d",mx[i] + j);
    }
    rep(i,0,n){
        vector<int> ve;
        rep(j,0,m) ve.push_back(mx[i][j]);
        sort(ve.begin(),ve.end());
        rep(j,0,m-1){
            if(ve[j] == ve[j+1]) cnt_row[i]++;
        }
    }
    rep(j,0,m){
        vector<int> ve;
        rep(i,0,n) ve.push_back(mx[i][j]);
        sort(ve.begin(),ve.end());
        rep(i,0,n-1){
            if(ve[i] == ve[i+1]) cnt_col[j]++;
        }
    }
    rep(i,0,n){
        vector<int> ve;
        rep(j,0,m) ve.push_back(mx[i][j]);
        sort(ve.begin(),ve.end());
        auto iter = unique(ve.begin(),ve.end());
        ve.erase(iter,ve.end());
        rep(j,0,m) idx[i][j] = lower_bound(ve.begin(),ve.end(),mx[i][j]) - ve.begin();
    }
    rep(j,0,m){
        vector<int> ve;
        rep(i,0,n) ve.push_back(mx[i][j]);
        sort(ve.begin(),ve.end());
        auto iter = unique(ve.begin(),ve.end());
        ve.erase(iter,ve.end());
        rep(i,0,n) col_idx[i][j] = lower_bound(ve.begin(),ve.end(),mx[i][j]) - ve.begin();
    }
    rep(i,0,n) rep(j,0,m){
        int x = idx[i][j];
        int y = col_idx[i][j];
        int temp = 0;
        if(x>y){
            temp = max(m - cnt_row[i], n + abs(x-y) - cnt_col[j]);
        }else{
            temp = max(n - cnt_col[j], m + abs(x-y) - cnt_row[i]);
        }
        ans[i][j] = temp;
    }
    rep(i,0,n) rep(j,0,m) {
        printf("%d%c",ans[i][j],j==m-1?'\n':' ');
    }

    return 0;
}
