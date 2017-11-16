#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	long long int count=0;
	for(long long int i=1;i<=a;i++)
	{
		long long int x=i*i;
		int y=(i+1)*(i+1)-x;
		long long int j=i+1;
		while(y<=b)
		{
			count++;
			j++;
			y=j*j-x;
		}
	}
	printf("%lld\n",count);
}
