#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,a,b;
		scanf("%d%d%d",&k,&a,&b);
		int m=k-2;
		int l=(a>b)?(a-b):(b-a);
		l--;
		int n=m-l;
		if(n>l)
			printf("%d\n",l);
		else if(l>n)
			printf("%d\n",n);
		else
			printf("0\n");
	}
}