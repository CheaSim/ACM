#include <stdio.h>
#include <string.h>
#include <algorithm>
#define uL unsigned long
#define LL long long
#define uLL unsigned long long
#define uC unsigned char
/*
#include <BasicIntegerArithmetic.h>
#include <CPU.h>
#include <MemoryManagement.h>*/
#define NODES 100007
#define NNNN 100007
#define MemoryStackTotal 1000000
#define error 1e-8
#define min63(a,b) (((a)<(b))?(a):(b))
static unsigned char BakaMemoryStack[MemoryStackTotal];
static unsigned char *MemoryStackTop=BakaMemoryStack;
//static unsigned long MemoryStackUsed=0;
//#ifdef MemoryStackMode
#define Allocates(size) ({MemoryStackTop+=(size);(MemoryStackTop-(size));})
#define Releases(size) ({MemoryStackTop-=(size);})
FILE *fin,*fout;
long op=0;
void print(long *a,long size)
{
	long i;
	for (i=0;i<=size;i++)
	{
		printf("%ld ",a[i]);
	}
	printf("\n");
}


long lower,upper;

//long gap[NODES],gav[NODES],gnext[NODES];

long barrel[NODES],backet[NODES],bnext[NODES],bartop;

long visited[NODES];
long head[NODES],edge[NODES],next[NODES],vsize,esize;
long label[NODES],capacity[NODES],flow[NODES];
long augpath[NODES],lpoi[NODES];

// FPC=free pointer collection:D ,,,, not freepascal -.-
long FPC[100],*FPCnext[100];
void DynamicAllocation(long poi,long *next,long size)
{
	long i;
	FPC[poi]=1;FPCnext[poi]=next;
	for (i=1;i<size;i++){next[i]=i+1;}
}
inline long Allocate(long poi)
{
	long k;
	k=FPC[poi];FPC[poi]=FPCnext[poi][k];
	//maintain

	//////////
	return k;
}
void Release(long poi,long p)
{
	FPCnext[poi][p]=FPC[poi];FPC[poi]=p;
}
////////////////////////////////////////////

void DicnicBFS(long s)
{
	long i,j,v;
	long *que=(long*)Allocates(sizeof(*que)*(vsize+1));
	memset(label,0,sizeof(*label)*(vsize+1));
	*que=1;que[1]=s;label[s]=1;
	for (i=1;i<=*que;i++)
	{
		s=que[i];
		for (j=head[s];j>0;j=next[j])
		{
			v=edge[j];
			if ((capacity[j]>flow[j])&&(label[v]==0))
			{
				label[v]=label[s]+1;
				que[++(*que)]=v;
			}
		}
	}
	Releases(sizeof(long)*(vsize+1));
}
long Dicnic(long ori,long fin)
{
	long i,j,k,ans;
	memset(flow,0,sizeof(*flow)*(*edge+1));
	augpath[ori]=0;
	for (DicnicBFS(ori);label[fin]>0;DicnicBFS(ori))
	{
//		printf("begin\n");
		for (i=1;i<=vsize;i++) {lpoi[i]=head[i];}
		i=ori;ans=0x7FFFFFFF;
		while (i>0)
		{
//			printf("%ld %ld\n",i,augpath[i]);
			for (j=lpoi[i];j>0;j=next[j])
			{
				k=edge[j];
				if ((label[k]==label[i]+1)&&(capacity[j]>flow[j]))
				{
					ans=min63(ans,capacity[j]-flow[j]);
					lpoi[i]=j;augpath[k]=i;
					i=k;goto AUGMENT;
				}
			}
			label[i]=0;i=augpath[i];continue;
AUGMENT:	if (i==fin)
			{
				for (i=augpath[i];i>0;i=augpath[i])
				{
					flow[lpoi[i]]+=ans;
					flow[lpoi[i]^1]-=ans;
				}
				i=ori;ans=0x7FFFFFFF;
			}
		}
	}
	ans=0;
	for (i=head[ori];i>0;i=next[i])
	{
		ans+=flow[i];
	}
	return ans;
}


long L[NODES],R[NODES];
long ee[10000][3],pp[10000];
bool cmp(const long &a,const long &b)
{
	if (ee[a][0]==ee[b][0])
	{
		return ee[a][1]<ee[b][1];
	}
	else
	{
		return ee[a][0]<ee[b][0];
	}
}
bool cmp2(const long &a,const long &b)
{
	if ((ee[a][0]==ee[b][0])&&(ee[a][1]==ee[b][1]))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{
//	freopen("in.in","r",stdin);
	long i,j,k,a,b,c,n,m,ans,ori,fin,ori2,fin2,iq,ans1,ans2;
	iq=0;
	while (scanf("%ld%ld%ld",L,R,&esize)!=EOF)
	{
		vsize=*L+*R;iq+=1;
		scanf("%ld%ld",&lower,&upper);
		ori=vsize+1;fin=vsize+2;
		ori2=vsize+3;fin2=vsize+4;
		vsize+=4;
		memset(head,0,sizeof(long)*(vsize+1));*edge=1;edge[1]=0;
		for (i=1;i<=*L;i++) {L[i]=i;}
		for (j=1;j<=*R;j++) {R[j]=*L+j;}
		///////////////////////////
		for (i=1;i<=esize;i++)
		{
			scanf("%ld%ld",&a,&b);
			a=L[a];b=R[b];
			ee[i][0]=a;
			ee[i][1]=b;
			ee[i][2]=1;
			pp[i]=i;
		}
		std::sort(pp+1,pp+esize+1,cmp);
		for (i=2,j=1;i<=esize;i++)
		{
		//	printf("%d\n",pp[i]);
			if (cmp2(pp[j],pp[i]))
			{
				ee[pp[j]][2]+=ee[pp[i]][2];
			}
			else
			{
				pp[++j]=pp[i];
			}
		}
		esize=j;
		////////////////////////////////
		for (i=1;i<=esize;i++)
		{
			a=ee[pp[i]][0];b=ee[pp[i]][1];c=ee[pp[i]][2];
			//printf("%d %d %d\n",a,b,c);
			edge[++(*edge)]=b;next[*edge]=head[a];head[a]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=a;next[*edge]=head[b];head[b]=*edge;
			capacity[*edge]=0;
		}
		for (i=1;i<=*L;i++)
		{
			a=ori;b=L[i];c=upper;
			edge[++(*edge)]=b;next[*edge]=head[a];head[a]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=a;next[*edge]=head[b];head[b]=*edge;
			capacity[*edge]=0;
			/////////////////////////////////////////////////
			c=lower;
			edge[++(*edge)]=b;next[*edge]=head[ori2];head[ori2]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=ori2;next[*edge]=head[b];head[b]=*edge;
			capacity[*edge]=0;
			/////////////////////////////////////////////////
			edge[++(*edge)]=fin2;next[*edge]=head[a];head[a]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=a;next[*edge]=head[fin2];head[fin2]=*edge;
			capacity[*edge]=0;
		}
		for (i=1;i<=*R;i++)
		{
			a=R[i];b=fin;c=upper;
			edge[++(*edge)]=b;next[*edge]=head[a];head[a]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=a;next[*edge]=head[b];head[b]=*edge;
			capacity[*edge]=0;
			/////////////////////////////////////////////////
			c=lower;
			edge[++(*edge)]=b;next[*edge]=head[ori2];head[ori2]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=ori2;next[*edge]=head[b];head[b]=*edge;
			capacity[*edge]=0;
			/////////////////////////////////////////////////
			edge[++(*edge)]=fin2;next[*edge]=head[a];head[a]=*edge;
			capacity[*edge]=c;
			edge[++(*edge)]=a;next[*edge]=head[fin2];head[fin2]=*edge;
			capacity[*edge]=0;
		}
		a=fin;b=ori;c=100000;
		edge[++(*edge)]=b;next[*edge]=head[a];head[a]=*edge;
		capacity[*edge]=c;
		edge[++(*edge)]=a;next[*edge]=head[b];head[b]=*edge;
		capacity[*edge]=0;
		/////////////////
		ans=Dicnic(ori2,fin2);
		ans1=1;
		for (i=head[ori2];i>0;i=next[i])
		{
			if (flow[i]!=capacity[i]) {ans1=0;}
			//printf("%d=%d\n",flow[i],capacity[i]);
		}
		ans2=1;
		for (i=head[fin2];i>0;i=next[i])
		{
			j=i^1;
			if (flow[j]!=capacity[j]) {ans2=0;}
			//printf("%d=%d\n",flow[j],capacity[j]);
		}

//		printf("%d %d\n",ans1,ans2);
		if (ans1|ans2)
		{
			printf("Case %d: Yes\n",iq);
		}
		else
		{
			printf("Case %d: No\n",iq);
		}
//		printf("max flow=%ld is max flow? %ld\n",ans,check(ori2,fin2,vsize));
	}
	return 0;
}




