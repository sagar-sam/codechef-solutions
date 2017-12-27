#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <climits>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d",&k);
		vector<int> speed(k);
		vector<int> sal(k);
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&speed[i],&sal[i]);
		}
		int n;
		scanf("%d",&n);
		vector<int> dish(n);
		vector<int> time(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&dish[i],&time[i]);
		}
		int cost=INT_MAX;
		if(n==1)
		{
			int flag=0;
			for(int i=0;i<k;i++)
			{
				if((speed[i]*time[0])>=dish[0] && sal[i]<cost)
				{
					flag=1;
					cost=sal[i];
				}
			}
			if(flag==1)
			{
				printf("%d\n",cost);
			}
			else printf("-1\n");
		}
		else
		{
			map<int,int> mp;
			for(int i=0;i<n;i++)
			{
				mp[time[i]]+=dish[i];
			}
			int x=1;
			for(int i=0;i<k;i++)
			{
				x=x*2;
			}
			vector<int> combspeed;
			vector<int> combsalary;
			vector<int> mask;
			for(int i=1;i<x;i++)
			{
				int j=i;
				int cspeed=0;
				int csal=0;
				int ind=0;
				while(j!=0)
				{
					int l=j%2;
					if(l)
					{
						cspeed+=speed[ind];
						csal+=sal[ind];
					}
					j=j/2;
					ind++;
				}
				combspeed.push_back(cspeed);
				combsalary.push_back(csal);
				mask.push_back(1);
			}
			for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
			{
				for(int i=0;i<mask.size();i++)
				{
					if(combspeed[i]*(it->first)<it->second)
					{
						mask[i]=0;
					}
				}
			}
			int flag=0;
			for(int i=0;i<mask.size();i++)
			{
				if(mask[i]==1)
				{
					flag=1;
					if(combsalary[i]<cost)
					{
						cost=combsalary[i];
					}
				}
			}
			if(flag==0)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n",cost);
			}
		}
	}
}