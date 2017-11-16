#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		vector<int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
		}
		sort(vec.begin(),vec.end());
		int x=n-1;
		int ind=n-1;
		int y=n+k;
		y=y/2;
		printf("%d\n",vec[y]);
		int ans=vec[n-1];
	}
}