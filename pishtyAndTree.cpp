#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		vector<vector<pair<long long int,long long int> > > ma(n+1);
		/*long long int **ma=new long long int*[n+1];
		for(long long int i=0;i<n+1;i++)
		{
			ma[i]=new long long int[n+1];
			for(long long int j=1;j<=n;j++)
				ma[i][j]=0;
		}*/
		long long int a,b,c;
		for(long long int i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			//ma[a][b]=ma[b][a]=c;
			ma[a].push_back(pair<long long int,long long int>(b,c));
			ma[b].push_back(pair<long long int,long long int>(a,c));
		}
		long long int m;
		scanf("%lld",&m);
		while(m--)
		{
			long long int *vis=new long long int[n+1];
			for(long long int i=1;i<=n;i++)
				vis[i]=0;
			long long int ans=0;
			queue< pair<long long int,long long int> > q;
			long long int x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			vis[x]=1;
			for(long long int i=0;i<ma[x].size();i++)
			{
				if(ma[x][i].second<=z)
				{
					q.push(pair<long long int,long long int>(ma[x][i].first,ma[x][i].second));
				}
				else
				{
					q.push(pair<long long int,long long int>(ma[x][i].first,0));
				}
			}
			while(!q.empty())
			{
				pair<long long int,long long int> p=q.front();
				q.pop();
				long long int s=p.first;
				long long int r=p.second;
				if(s==y)
				{
					ans=r;
					break;
				}
				vis[s]=1;
				for(long long int i=0;i<ma[s].size();i++)
				{			
					if(ma[s][i].second<=z)
					{
						if(vis[ma[s][i].first]==0)
						{
							vis[ma[s][i].first]=1;
							q.push(pair<long long int,long long int>(ma[s][i].first,r^ma[s][i].second));
						}
					}
					else
					{
						if(vis[ma[s][i].first]==0)
						{
							vis[ma[s][i].first]=1;
							q.push(pair<long long int,long long int>(ma[s][i].first,r));
						}
					}
				}
			}
			printf("%lld\n",ans);
		}
	}
}
