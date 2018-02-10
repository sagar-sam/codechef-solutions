#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int r,n,s,e,w;
		scanf("%lld%lld%lld%lld%lld",&r,&n,&s,&e,&w);
		if(r==n || r==s || r==e || r==w)
			printf("YES\n");
		else printf("NO\n");
	}
}