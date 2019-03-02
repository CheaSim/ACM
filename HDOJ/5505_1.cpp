#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
typedef unsigned long long LL;
 
;
;
 
bool vis[PRI_NUM];
int prime[MAXN];
int factor_n[MAXN];
int factor_m[MAXN];
 
void Pre()
{
    ; i <= PRI_NUM; i++) {
        ) {
            for(int j = i+i; j <= PRI_NUM; j+=i) {
                vis[j] = ;
            }
        }
    }
    ;
    ; i <= PRI_NUM; i++) {
        ) {
            prime[cnt++] = i;
        }
    }
}
 
void Init()
{
    memset(prime_n, , sizeof(prime_n));
    memset(prime_m, , sizeof(prime_m));
}
 
int main()
{
    Pre();
 
    int t;
    int n;
    LL m;
 
    scanf("%d", &t);
    while(t--) {
        Init();
        scanf("%d %I64u", &n, &m);
        if(m == n) {
            printf("0\n");
            continue;
        }
        ) {
            printf("-1\n");
            continue;
        }
        ;
        ; i < MAXN; i++) {
            ) break;
            ) {
                factor_n[cnt] = prime[i];
                ) {
                    n /= prime[i];
                    prime_n[cnt]++;
                }
                cnt++;
            }
        }
        ) {
            factor_n[cnt] = n;
            prime_n[cnt] = ;
            cnt++;
        }
        ; i < cnt; i++) {
            ) {
                m /= factor_n[i];
                prime_m[i]++;
            }
        }
        ) {
            printf("-1\n");
            continue;
        }
        ;
        ; i < cnt; i++) {
            ;
            while(prime_n[i] < prime_m[i]) {
                prime_n[i] <<= ;
                k++;
            }
            if(k > ans) ans = k;
        }
        printf("%d\n", ans);
    }
 
    ;
}
