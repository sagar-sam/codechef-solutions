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
		vector<int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				int x=vec[i] | vec[j];
				int y=max(vec[i],vec[j]);
				if(x<=y)
					count++;
			}
		}
		printf("%d\n",count);
	}
}