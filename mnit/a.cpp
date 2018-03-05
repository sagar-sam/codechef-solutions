#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int w,s,p,q;
		scanf("%lld%lld%lld%lld",&w,&s,&p,&q);
		int dif=abs(w-s);
		w=w+p;
		s=s+q;
		int dif2=abs(w-s);
		if(dif2==dif)
			printf("NO\n");
		else printf("YES\n");
	}
}