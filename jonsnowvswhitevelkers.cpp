#include <iostream>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int suma=0,sumb=0;
		int a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			suma+=a;
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);
			sumb+=a;
		}
		(suma<sumb)?printf("Death\n"):printf("Snow\n");
	}
}