#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		vector<int> minSalary(n);
		for(int i=0;i<n;i++)
		{
			//printf("!1");
			scanf("%d",&minSalary[i]);
		}
		vector < pair<int,int> > com;
		int a,b;
		for(int i=0;i<m;i++)
		{
			//printf("2");
			scanf("%d%d",&a,&b);
			com.push_back(pair<int,int>(a,b));
		}
		vector<string> qual(n);
		for(int i=0;i<n;i++)
		{
			//printf("3");
			cin>>qual[i];
		}
		int count=0;
		//sort(com.begin(),com.end());
		vector<int> offer[n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(qual[i][j]=='1')
				{
					offer[i].push_back(j);
				}
			}
		}
		vector<int> co(m);
		long long int total=0;
		for(int i=0;i<n;i++)
		{
			int maxsalary=0;
			int index=-1;
			for(int j=0;j<offer[i].size();j++)
			{
				//printf("a");
				if(com[offer[i][j]].second!=0)
				{
				//	printf("b");
					if(com[offer[i][j]].first>maxsalary)
					{
				//		printf("c");
						maxsalary=com[offer[i][j]].first;
						index=offer[i][j];
					}
				}
			}
			if(maxsalary>=minSalary[i])
			{
				total=total+(long long int)(maxsalary);
				count++;
				co[index]++;
				com[index].second=com[index].second-1;
			}
		}
		int x=0;
		for(int i=0;i<m;i++)
		{
			if(co[i]==0)
				x++;
		}
		printf("%d %lld %d\n",count,total,x);
	}
}