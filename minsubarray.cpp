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
		int n,d;
		scanf("%d%d",&n,&d);
		vector<int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
		}
		int sum=0;
		int start=0;
		int ans=INT_MAX;
		for(int i=0;i<n;i++)
		{
			sum=sum+vec[i];
			if(sum>=d)
			{
				int res=(i-start+1);
				if(res<ans)
				{
				//	printf("1  %d   ",i);
					ans=res;
				}
				while(start<i && (sum-vec[start])>=d)
				{
					sum=sum-vec[start];
					start++;
					res--;
					if(res<ans)
					{
				//		printf("2   %d    ",i);
						ans=res;
					}
				}
			}
		}
		start=n-1;
		sum=0;
		for(int i=n-1;i>=0;i--)
		{
			sum=sum+vec[i];
			if(sum>=d)
			{
				int res=(start-i+1);
				if(res<ans)
				{
				//	printf("1  %d   ",i);
					ans=res;
				}
				while(i<start && (sum-vec[start])>=d)
				{
					sum=sum-vec[start];
					start--;
					res--;
					if(res<ans)
					{
				//		printf("2   %d    ",i);
						ans=res;
					}
				}
			}
		}
		if(ans==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",ans);

//		int res=smallestSubWithSum(vec, n, d);
//		if(res==n+1)
//			printf("-1\n");
//		else printf("%d\n",res);
	}
}