#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(1000005);

void calculate_sieve()
{
	for(int i=0;i<1000005;i++)
	{
		sieve[i]=-1;
	}

	for(int i=4;i<1000005;i+=2)
	{
		sieve[i]=2;
	}

	for(int i=3;i*i<1000005;i+=2)
	{
		if(sieve[i]==-1)
		{
			for(int j=i*i;j<1000005;j+=i)
			{
				if(sieve[j]==-1)
				{
					sieve[j]=i;
				}
			}
		}
	}
}

int main()
{
	calculate_sieve();
	int t;
	scanf("%d",&t);
	vector<int> ans(1000005);
	for(int i=2;i<1000005;i++)
	{
		if(sieve[i]==-1)
		{
			ans[i]=ans[i-1]+1;
		}
		else ans[i]=ans[i-1];
	}
	while(t--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int cur=ans[r]-ans[l-1];
		float val=(float)(cur)/(float)(r-l+1);
		printf("%lf\n",val);
	}
}