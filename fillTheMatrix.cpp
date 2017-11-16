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
		vector< pair<int,int> > vec;
		map<int,int> zero;
		int flag=0;
		for(int k=0;k<qu;k++)
		{
			scanf("%d%d%d",&i,&j,&val);
			if(val==0)
			{
				//zero[i]=1;
				//zero[j]=1;
				a[i]=5;
				a[j]=5;
			}
			else
			{
				if(i!=j)
					vec.push_back(pair<int,int>(i,j));
				else flag=1;
			}
		}
		if(flag==1)
		{
			printf("no\n");
			continue;
		}
		for(int k=0;k<vec.size();k++)
		{
			if(a[vec[k].first]==5 && a[vec[k].second]==5)
			{
				zero[k]=1;
				flag=1;
				break;
			}
			else if(a[vec[k].first]==5)
			{
				zero[k]=1;
				a[vec[k].second]=6;
			}
			else if(a[vec[k].second]==5)
			{
				zero[k]=1;
				a[vec[k].first]=6;
			}
		}
		if(flag==1)
		{
			printf("no\n");
			continue;
		}
		vector<int> another[n+1];
		queue<int> q;
		for(int k=0;k<vec.size();k++)
		{
			if(zero[k]==0)
			{
				if(a[vec[k].first]==6 && a[vec[k].second]==6)
				{
					flag=1;
					break;
				}
				else if(a[vec[k].first]==6)
				{
					a[vec[k].second]=7;
					q.push(vec[k].second);
				}
				else if(a[vec[k].second==6])
				{
					a[vec[k].first]=7;
					q.push(vec[k].first);
				}
				else
				{
					another[vec[k].first].push_back(vec[k].second);
					another[vec[k].second].push_back(vec[k].first);
				}
			}
		}
		if(flag==1)
		{
			printf("no\n");
			continue;
		}
		vector<int> acc(n+1);
		while(!q.empty())
		{
			int x=q.front();
			acc[x]=1;
			q.pop();
			for(int k=0;k<another[x].size();k++)
			{
				if(a[another[x][k]]==a[x])
				{
					flag=1;
					break;
				}
				else if(a[another[x][k]]!=0 && a[another[x][k]]!=(a[x]+1) && a[another[x][k]]!=(a[x]-1))
				{
					flag=1;
					break;
				//	a[another[x][k]]=a[x]+1;
				//	q.push(another[x][k]);
				}
				else if(a[another[x][k]]==0)
				{
					a[another[x][k]]=a[x]+1;
					q.push(another[x][k]);
				}
			}
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			printf("no\n");
			continue;
		}
		for(int k=1;k<=n;k++)
		{
			if(acc[k]==0)
			{
				a[k]=9;
				for(int l=0;l<another[k].size();l++)
				{
					a[another[k][l]]=a[k]+1;
					q.push(another[k][l]);
				}
				while(!q.empty())
				{
					int x=q.front();
					acc[x]=1;
					q.pop();
					for(int k=0;k<another[x].size();k++)
					{
						if(a[another[x][k]]==a[x])
						{
							flag=1;
							break;
						}
						else if(a[another[x][k]]!=0 && a[another[x][k]]!=(a[x]+1) && a[another[x][k]]!=(a[x]-1))
						{
							flag=1;
							break;
						}
						else if(a[another[x][k]]==0)
						{
							a[another[x][k]]=a[x]+1;
							q.push(another[x][k]);
						}
					}
					if(flag==1)
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