#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<long long int> vec[n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				long long int a;
				scanf("%lld",&a);
				vec[i].push_back(a);
			}
		}
		long long int ans=0;
		long long int max=-1;
		long long int prev;
		for(int i=0;i<n;i++)
		{
			if(vec[n-1][i]>max)
				max=vec[n-1][i];
		}
		ans=max;
		prev=max;
		int flag=0;
		for(int i=n-2;i>=0;i--)
		{
			prev=max;
			max=-1;
			flag=0;
			for(int j=0;j<n;j++)
			{
				if(vec[i][j]>max && vec[i][j]<prev)
				{
					max=vec[i][j];
				}
			}
			if(max==-1)
			{
				flag=1;
				break;
			}
			ans+=max;
		}
		if(flag==1)
		{
			printf("-1\n");
		}
		else
		{
			printf("%lld\n",ans);
		}
	}
}