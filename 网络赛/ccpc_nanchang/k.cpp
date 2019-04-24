#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],c[N],d[N],d2[N],t,n,q,L,R;
const int InputBufferSize = 6710886;//输入缓冲区大小
const int OutputBufferSize = 6710886;//输出缓冲区大小
 
namespace input
{
    char buffer[InputBufferSize],*s,*eof;
    inline void init()
    {
        assert(stdin!=NULL);
        s=buffer;
        eof=s+fread(buffer,1,InputBufferSize,stdin);
    }
    inline bool read(int &x)
    {
        x=0;
        int flag=1;
        while(!isdigit(*s)&&*s!='-')s++;
        if(eof<=s)return false;
        if(*s=='-')flag=-1,s++;
        while(isdigit(*s))x=x*10+*s++-'0';
        x*=flag;
        return true;
    }
    inline bool read(char* str)
    {
        *str=0;
        while(isspace(*s))s++;
        if(eof<s)return false;
        while(!isspace(*s))*str=0,*str=*s,str++,s++;
        *str=0;
        return true;
    }
}
 
namespace output
{
    char buffer[OutputBufferSize];
    char *s=buffer;
    inline void flush()
    {
        assert(stdout!=NULL);
        fwrite(buffer,1,s-buffer,stdout);
        s=buffer;
        fflush(stdout);
    }
    inline void print(const char ch)
    {
        if(s-buffer>OutputBufferSize-2)flush();
        *s++=ch;
    }
    inline void print(char* str)
    {
        while(*str!=0)print(char(*str++));
    }
    inline void print(int x)
    {
        char buf[25]= {0},*p=buf;
        if(x<0)print('-'),x=-x;
        if(x==0)print('0');
        while(x)*(++p)=x%10,x/=10;
        while(p!=buf)print(char(*(p--)+'0'));
    }
}
 
using namespace input;
using namespace output;
 
int w(int l,int r){
    int ans = 0;
    int flag = (r - l + 2)%4;
/*    ans ^= d[r];
    if(flag == 0 && l>=1){
        ans ^= d[l-1];
    }else if(flag == 1 && l>=2){
        ans ^= d[l-2];
    }else if(l >= 3){
        ans ^= d[l-3];
    }
    for(int i=l-2;i<=r-2;i++){
        if(((r-i)/2)%2 == 1 && i >= 0)ans ^= c[i];
    }
    for(int i=r;i>=l;i--){
        if(((i-l+2)/2)%2 == 1) ans ^= c[i];
    }*/
    if(flag == 0){
        //for(int i=l-1;i<=r-1;i+=2)ans ^= c[i];
        ans ^= d2[r-1];
        if(l >= 3) ans^=d2[l-3];
    }else if(flag == 1){
        return 0;
    }else if(flag == 2){
        //for(int i=l-2;i<=r;i+=2)if(i>=0)ans ^= c[i];

        ans ^= d2[r];
        if(l >= 4)ans ^=d2[l-4];
    }else if(flag == 3){
        ans ^= d[r];
        if(l-3 >= 0)ans ^= d[l-3];
    }

    return ans;
}


int main(){
#ifdef LOCAL
    freopen("3.in","r",stdin);
#endif
    init();
    read(t);
    while(t--){
        read(n);
        for(int i=1;i<=n;i++){
            read(a[i]);
            b[i] = b[i-1]^a[i];
            c[i] = c[i-1]^b[i];
            d[i] = d[i-1]^c[i];
            if(i >= 2) d2[i] = d2[i-2]^c[i];
            else d2[i] = c[i];
        }
        read(q);
        while(q--){
            read(L); read(R);
            printf("%d\n",w(L,R));
        }
    }
    return 0;
}
