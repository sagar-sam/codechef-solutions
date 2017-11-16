#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,m;
		scanf("%lld%lld",&n,&m);
		vector<pair<long long int,pair<long long int,long long int>>> vec(m+1);
		vector<long long int> arr(n+1);
		long long int a,b,c;
		for(long long int i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&a,&b,&c);
			vec[i]=make_pair(a,make_pair(b,c));
		}
		vector<long long int> op(m+1);
		for(long long int i=m;i>=1;i--)
		{
			long long int x=op[i];
			x++;
			if(vec[i].first==1)
			{
				op[i]=x;
				op[i]%=1000000007;
			}
			else if(vec[i].first==2)
			{
				for(long long int j=vec[i].second.first;j<=vec[i].second.second;j++)
				{
					op[j]+=x;
					op[j]%=1000000007;
				}
			}
		}
		for(long long int i=1;i<=m;i++)
		{
			if(vec[i].first==1)
			{
				for(long long int j=vec[i].second.first;j<=vec[i].second.second;j++)
				{
					arr[j]+=op[i];
					arr[j]%=1000000007;
				}
			}
		}
				/*arr[vec[i].second.first]+=op[i];
				arr[vec[i].second.first]%=1000000007;
				if(vec[i].second.second+1<=n)
				{
					arr[vec[i].second.second+1]-=op[i];
					arr[vec[i].second.second+1]%=1000000007;
				}
			}
		}
		for(long long int i=1;i<=n;i++)
		{
			arr[i]+=arr[i-1];
			arr[i]%=1000000007;
		}*/
		for(int i=1;i<=n;i++)
		{
			printf("%lld ",arr[i]);
		}
		printf("\n");
	}
}
