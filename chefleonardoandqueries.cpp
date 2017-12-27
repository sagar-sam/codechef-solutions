#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,q;
		scanf("%lld%lld",&n,&q);
		vector<long long int> vec[n+1];
		vector<long long int> value(n+1);
		for(long long int i=0;i<n-1;i++)
		{
			long long int a,b;
			scanf("%lld%lld",&a,&b);
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		while(q--)
		{
			long long int x;
			scanf("%lld",&x);
			if(x==1)
			{
				vector<long long int> ans;
				long long int v,k,a,b;
				scanf("%lld%lld%lld%lld",&v,&k,&a,&b);
				ans.push_back(a);
				ans.push_back(b);
				long long int cal=(a+b)%1000000007;
				ans.push_back(cal);
				long long int ind=3;
				queue<pair<long long int,long long int>> q;
				q.push(make_pair(v,0));
				vector<long long int> visited(n+1);
				visited[v]=1;
				while(!q.empty())
				{
					long long int ca=ans[ind-1]+ans[ind-2];
					ca=ca%1000000007;
					ans.push_back(ca);
					ind++;
					pair<long long int,long long int> p=q.front();
					q.pop();
					long long int d=p.second;
					if(d>k)
						break;
					long long int lol=p.first;
					value[lol]+=ans[d];
					value[lol]=value[lol]%1000000007;
					for(long long int i=0;i<vec[lol].size();i++)
					{
						if(visited[vec[lol][i]]==0)
						{
							q.push(make_pair(vec[lol][i],d+1));
							visited[vec[lol][i]]=1;
						}
					}
				}
			}
			else if(x==2)
			{
				long long int v;
				scanf("%lld",&v);
				printf("%lld\n",value[v]);
			}
		}
	}
}