#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<long long int> a0(n);
		vector<long long int> a1(n);
		vector<long long int> a2(n);
		vector<long long int> a3(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld%lld%lld",&a0[i],&a1[i],&a2[i],&a3[i]);
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			long long int x;
			scanf("%lld",&x);
			long long int min=LLONG_MAX;
			for(int i=0;i<n;i++)
			{
				long long int cur=a0[i];
				cur=cur+((long long int)(a1[i])*(long long int)(x));
				cur=cur+((long long int)(a2[i])*(long long int)(x)*(long long int)(x));
				cur=cur+((long long int)(a3[i])*(long long int)(x)*(long long int)(x)*(long long int)(x));
				if(cur<min)
					min=cur;
			}
			printf("%lld\n",min);
		}
	}
}