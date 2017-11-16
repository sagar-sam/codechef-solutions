#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,p,q;
		scanf("%lld%lld%lld",&n,&p,&q);
		vector<long long int> a(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		vector<long long int> prod(n);
		prod[0]=a[0];
		for(int i=1;i<n;i++)
		{
			prod[i]=prod[i-1]*a[i];
		}
	}
}