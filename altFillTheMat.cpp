#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,qu;
		scanf("%d%d",&n,&qu);
		int i,j,val;
		vector<int> a(n+1);
		vector< pair<int,int> > vec[n+1];
		int flag=0;
		for(int k=0;k<qu;k++)
		{
			scanf("%d%d%d",&i,&j,&val);
			if(i!=j)
			{
				vec[i].push_back(pair<int,int>(j,val));
				vec[j].push_back(pair<int,int>(i,val));
			}
			else if(val==1)flag=1;
		}
		if(flag==1)
		{
			printf("no\n");
			continue;
		}
		queue<int> q0,q1;
		vector<int> acc(n+1);
		for(int k=1;k<=n;k++)
		{
			if(acc[k]==0)
			{
				acc[k]=1;
				a[k]=9;
				for(int l=0;l<vec[k].size();l++)
				{
					a[vec[k][l].first]=a[k]+vec[k][l].second;
					if(vec[k][l].second==0)
						q0.push(vec[k][l].first);
					else q1.push(vec[k][l].first);
				}
				while(true)
				{
					while(!q0.empty())
					{
						int x=q0.front();
						acc[x]=1;
						q0.pop();
						for(int l=0;l<vec[x].size();l++)
						{
							if(a[vec[x][l].first]!=0 && a[vec[x][l].first]!=(a[x]+vec[x][l].second) && a[vec[x][l].first]!=(a[x]-vec[x][l].second))
							{
								flag=1;
								break;
							}
							else if(a[vec[x][l].first]==0)
							{
								a[vec[x][l].first]=a[x]+vec[x][l].second;
								if(vec[x][l].first==0)
									q0.push(vec[x][l].first);
								else q1.push(vec[x][l].first);
							}
						}
						if(flag==1)
							break;
					}
					while(!q1.empty())
					{
						int x=q1.front();
						acc[x]=1;
						q1.pop();
						for(int l=0;l<vec[x].size();l++)
						{
							if(a[vec[x][l].first]!=0 && a[vec[x][l].first]!=(a[x]+vec[x][l].second) && a[vec[x][l].first]!=(a[x]-vec[x][l].second))
							{
								flag=1;
								break;
							}
							else if(a[vec[x][l].first]==0)
							{
								a[vec[x][l].first]=a[x]+vec[x][l].second;
								if(vec[x][l].first==0)
									q0.push(vec[x][l].first);
								else q1.push(vec[x][l].first);
							}
						}
						if(flag==1)
							break;
					}
					if(flag==1)
						break;
					if(q0.empty() && q1.empty())
						break;
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			printf("no\n");
		}
		else printf("yes\n");
	}
}