#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<pair<int,int> > vec;
		int n;
		scanf("%d",&n);
		int a,b;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			vec.push_back(pair<int,int>(a,b));
		}
		int ans=INT_MAX;
		for(int i=0;i<n;i++)
		{
			int max=0;
			for(int j=0;j<n;j++)
			{
				if(abs(vec[i].first-vec[j].first)+abs(vec[i].second-vec[j].second)>max)
					max=abs(vec[i].first-vec[j].first)+abs(vec[i].second-vec[j].second);
			}
			if(max<ans)
				ans=max;
		}
		printf("%d\n",ans);
	}
}
