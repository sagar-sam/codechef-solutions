#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		vector<long long int> w(n);
		vector<long long int> c(n);
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&c[i]);
		}
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&w[i]);
		}
		vector<long long int> s(n);
		for(long long int i=0;i<n;i++)
		{
			if(i==0)
				s[i]=w[i];
			else s[i]=s[i-1]+w[i];
		}
		vector<long long int> o;
		long long int x=0;
		long long int sum=0;
		map<long long int,long long int> mp;
		int flag=0;
		vector<long long int> b(n+1);
		for(long long int i=0;i<n;i++)
		{
			if(find(o.begin()+x,o.end(),c[i])==o.end())
			{
				//printf("if%lld\n",c[i]);
				flag=0;
				o.push_back(c[i]);
				b[c[i]]=i;
				//mp.insert(pair<long long int,long long int>(c[i],i));
			}
			else
			{
				//printf("el%lld\n",c[i]);
				flag=1;
				long long int sumpos=0;
				if(x==0)
					sumpos=s[i-1];
				else 
					sumpos=s[i-1]-s[x-1];
				if(sumpos>sum)
				{
					//printf("%lld %lld",x,i);
					sum=sumpos;
				}
				x=b[c[i]]+1;
				o.push_back(c[i]);
				b[c[i]]=i;
			}
		}
		if(flag==0)
		{
			long long int sumpos=0;
			if(x==0)
			{
				sumpos=s[n-1];
			}
			else
			{
				sumpos=s[n-1]-s[x-1];
			}
			if(sumpos>sum)
			{
				//printf("%lld %lld\n",n,x);
				sum=sumpos;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
