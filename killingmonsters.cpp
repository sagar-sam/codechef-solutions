#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> vec(n);
	vector<int> visited(n);
	int allh=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&vec[i]);
		if(vec[i]!=1)
			allh=1;
	}
	int count=n;
	int q;
	scanf("%d",&q);
	vector<pair<int,int>> query;
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		query.push_back(make_pair(x,y));
		if(y!=1)
			allh=1;
	}
	if(allh==0)
	{
		queue<int> s;
		for(int i=0;i<n;i++)
		{
			s.push(i);
		}
		for(int i=0;i<query.size();i++)
		{
			int x=query[i].first;
			int si=s.size();
			for(int j=0;j<si;j++)
			{
				int z=s.front();
				s.pop();
				int lo=x&z;
				if(lo!=z)
				{
					s.push(z);
				}
			}
			int ans=s.size();
			printf("%d\n",ans);
		}
	}
	else if(allh==1)
	{
		for(int j=0;j<query.size();j++)
		{
			int x=query[j].first;
			int y=query[j].second;
			for(int i=0;i<n;i++)
			{
				int sa=i&x;
				if(sa==i)
				{
					vec[i]=vec[i]-y;
					//printf(" %d ",vec[i]);
					if(vec[i]<=0 && visited[i]==0)
					{
						visited[i]=1;
						count--;
					}
				}
			}
			printf("%d\n",count);
		}
	}
}
