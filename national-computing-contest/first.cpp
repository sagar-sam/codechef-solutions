#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <math.h>
using namespace std;


vector<int> sieve(1000005);

void calculate_sieve()
{
	for(int i=0;i<1000005;i++)
	{
		sieve[i]=-1;
	}

	for(int i=4;i<1000005;i+=2)
	{
		sieve[i]=2;
	}

	for(int i=3;i*i<1000005;i+=2)
	{
		if(sieve[i]==-1)
		{
			for(int j=i*i;j<1000005;j+=i)
			{
				if(sieve[j]==-1)
				{
					sieve[j]=i;
				}
			}
		}
	}
}

int main()
{
	calculate_sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a;
		map<int,int> mp;
		int count=0;
		int count1=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
		//	printf("%d ",sieve[a]);
			if(a==1)
				count1++;
			else if(sieve[a]==-1)
			{
				mp[a]++;
			}
			else
			{
				int rt=sqrt(a);
				if(rt*rt==a)
					count++;
			}
		}
		int ans=min(count,count1);
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
		//	printf("%d %d \n",it->first,it->second);
			if(it->first!=1)
			{
				ans=ans+it->second/2;
			}
		}
		if(ans%2==1)
		printf("Sagar\n");
		else printf("Shivam\n");
	}
}