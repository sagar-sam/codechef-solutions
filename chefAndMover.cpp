#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,d;
		scanf("%lld%lld",&n,&d);
		vector<long long int> vec(n);
		long long int sum=0;
		for(long long int i=0;i<n;i++)
		{
			scanf("%lld",&vec[i]);
			sum+=vec[i];
		}
		vector<long long int> su(d);
		vector<long long int> co(d);
		int flag=0;
		if(sum%n!=0)
		{
			printf("-1\n");
			continue;
		}
		long long int x=sum/n;
		for(int i=0;i<n;i++)
		{
			su[i%d]+=vec[i];
			co[i%d]++;
		}
		for(int i=0;i<d;i++)
		{
			if(co[i]*x!=su[i])
			{
				printf("-1\n");
				flag=1;
				break;
			}
		}
		if(flag==1)
			continue;
		long long int ans=0;
		for(int i=0;i<d;i++)
		{
			long long int rem=0;
			for(int j=i;j<n;j+=d)
			{
				vec[j]=vec[j]+rem;
				rem=0;
				if(vec[j]!=x)
				{
					rem=vec[j]-x;
					ans+=abs(rem);
				}
			}
		}
		printf("%lld\n",ans);
	}
}