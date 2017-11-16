#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<int> vec(1000000);
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			vec[a]++;
		}
		for(int i=0;i<1000000;i++)
		{
			if(vec[i]==0)
			{
				if(k)
					k--;
				else 
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
}