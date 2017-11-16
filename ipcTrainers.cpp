#include <iostream>
#include <stdio.h>
#include <map>
#include <iterator>
 
using namespace std;
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,d;
		scanf("%d %d",&n,&d);
		int *occ=new int[d+1];
		occ[0]=1;
		for(int i=1;i<=d;i++)
			occ[i]=0;
		int *af=new int[d+1];
		for(int i=d;i>0;i--)
		{
			af[i]=d-i+1;
		}
		multimap < int,pair<int,int> > mp;
		int sd,da,l;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",&da,&l,&sd);
			mp.insert(pair<int,pair<int,int>>(sd,pair<int,int>(da,l)));
		}
		int tocount=0;
		long long int ans = 0;
		multimap<int, pair<int,int> > :: iterator it=mp.end();
		int flag=0;
		while(true)
		{
			if(flag==1)
				break;
			if(it==mp.begin())
				break;
			else it--;
			int count=0;
			int x=it->second.first;
			int y=it->second.second;
			int z=it->first;
			if(af[x]>0)
			{
				for(int i=x;i<=d;i++)
				{
					if(af[i]==0)
						break;
					if(tocount==d)
					{
						flag=1;
						break;
					}
					if(count==y)
						break;
					if(af[i]>=y-count)
						af[i]=af[i]-y+count;
					else af[i]=0;
					if(occ[i]==0)
					{
						tocount++;
						count++;
						occ[i]=1;
					}
				}
				if(count!=y)
				{
					ans=ans+(long long int)(y-count)*(long long int)(z);
				}
			}
			else
			{
				ans=ans+(long long int)(y)*(long long int)(z);
			}
		}
		if(flag==1)
		{
			while(true)
			{
				if(it==mp.begin())
					break;
				else 
					it--;
				ans=ans+(long long int)(it->second.second)*(long long int)(it->first);
			}
		}
		printf("%lld\n",ans);
	}
}
