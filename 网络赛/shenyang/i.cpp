#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define bits (1<<12)
char map[bits];
char ans[1000000];
char str[1000000];
int asize;
char temp[100];
int getnum(char *str)
{
	int i,j,a;
	for (a=1,i=0;str[i]!='\0';i++)
	{
		a=(a<<1)|(str[i]-'0');
	}
	return a;
}

char hex2[1000];
char hex[][4]={
			{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},
			{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},
			{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},
			{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
void debug(char *str)
{
	int i;
	for (i=0;i<=8;i++)
	{
		printf("%d ",str[i]);
	}
	printf("\n");
}
int main()
{
	//freopen("in.in","r",stdin);
	int i,j,k,a,b,c,d,qq,iq,l,n,m;
	for (i='0';i<='9';i++)
	{
		hex2[i]=i-'0';
	}
	for (i='A';i<='F';i++)
	{
		hex2[i]=i-'A'+10;
	}
	for (i='a';i<='f';i++)
	{
		hex2[i]=i-'a'+10;
	}
	scanf("%d",&qq);
	for (iq=1;iq<=qq;iq++)
	{
		//printf("%d\n",iq);
		for (i=0;i<bits;i++)
		{
			map[i]=127;
		}
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;i++)
		{
			scanf("%d",&a);
			RE:scanf("%s",str);
			if (isdigit(*str)==0) {goto RE;}
			//printf("<%s>\n",str);
			b=getnum(str);
			map[b]=a;
			//printf("%d %d\n",b,a);
		}
		RE2:scanf("%s",str);
		if ((isdigit(*str)==0)&&(isalpha(*str)==0)) {goto RE2;}
		//printf("-%s-\n",str);
		asize=0;c=1;l=0;
		for (i=0;str[i]!='\0';i++)
		{
			a=hex2[str[i]];
			for (j=0;j<4;j++)
			{
				b=hex[a][j];
				temp[l++]=b;
				if (l==9)
				{
					l=0;d=1;
					for (k=0;k<8;k++)
					{
						d=d^temp[k];
					}
					//printf("%d\n",d);
					//debug(temp);
					if (d==temp[8])
					{
						//debug(temp);
						for (k=0;k<8;k++)
						{
							c=(c<<1)|temp[k];
							if (map[c]!=127)
							{
								ans[asize++]=map[c];
								//printf("%d*%d\n",c,map[c]);
								c=1;
								if (asize>n) {goto PRINT;}
							}
						}
					}
				}
			}
		}
		PRINT:
		if (n<asize) {asize=n;}
		ans[asize]=0;
		printf("%s\n",ans);
	}
	return 0;
}
