#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<long long int> a(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		int max=a[0];
	   for (int i = 1; i < n; i++)
	   {
	   		if(a[i]>max)
	   			max=a[i];
	   }
	   printf("%d\n",max);
	}
}