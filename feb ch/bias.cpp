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
		vector<int> ans(m);
		vector<pair<int,int>> bound(m);
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			bound[i]=make_pair(a,b);
		}
		vector<pair<int,int>> score[n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				int a;
				scanf("%d",&a);
				score[i].push_back(make_pair(a,j));
			}
		}
		sort(score[0].begin(),score[0].end());
		for(int i=m-1;i>=0;i--)
		{
			pair<int,int> p=score[0][i];
			if(i==m-1)
			{
				ans[p.second]=bound[p.second].second;
			}
			else
			{
				int dif = score[0][i+1].first-score[0][i].first;
				int prev = score[0][i+1].second;
				int cur = score[0][i].second;
				int prevans = ans[prev];
				int curans = prevans-dif;
				if(curans>bound[cur].first && curans<bound[cur].second)
					ans[cur]=curans;
				else if(curans>bound[cur].second)
					ans[cur]=bound[cur].second;
				else
					ans[cur]=bound[cur].first;
			}
		}
		for(int i=0;i<m;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}
