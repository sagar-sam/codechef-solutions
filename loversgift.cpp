#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		vector<int> vec[n];
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			b--;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		vector<int> bank(n);
		while(q--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			y--;
			if(x==1)
			{
				bank[y] = 1;
			}
			else
			{
				vector<int> temp;
				int z=y;
				if(bank[z]==1)
				{
					temp.push_back(z+1);
				}
				queue<pair<int,pair<int,int>>> q;
				q.push(make_pair(z,make_pair(0,bank[z])));
				vector<int> visited(n);
				visited[z]=1;
				while(!q.empty())
				{
					pair<int,pair<int,int>> p;
					p=q.front();
					q.pop();
					int a=p.first;
					int b=p.second.first;
					int c=p.second.second;
					//if(b==2)
					//	break;
					for(int i=0;i<vec[a].size();i++)
					{
						if(visited[vec[a][i]]==0)
						{
							int l=b+1;
							int sa=c+bank[vec[a][i]];
							if(sa!=0)
								temp.push_back(vec[a][i]+1);
							visited[vec[a][i]]=1;
							q.push(make_pair(vec[a][i],make_pair(l,sa)));
						}
					}
				}
				if(temp.size()<2)
				{
					printf("-1\n");
				}
				else
				{
					sort(temp.begin(),temp.end());
					/*for(int i=0;i<temp.size();i++)
					{
						printf("%d ",temp[i]);
					}*/
					printf("%d\n",temp[temp.size()-2]);
				}
			}
		}
	}
}
