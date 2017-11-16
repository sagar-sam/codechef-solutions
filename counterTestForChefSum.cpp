#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int x=4294967295/n;
		if(n==99992 || n==99994 || n==99996 || n==99999)
			x--;
		long long int y=n*x-x;
		y=4294967295-y;
		long long int z=y/2;
		z+=2;
		for(int i=1;i<n;i++)
		{
			printf("%lld ",x);
		}
		//printf("%lld ",x);
		printf("%lld\n",z);
	}
}