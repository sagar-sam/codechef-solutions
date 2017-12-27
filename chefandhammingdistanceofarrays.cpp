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
		int n;
		scanf("%d",&n);
		vector<int> vec(n);
		vector<int> sorted(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&vec[i]);
			sorted[i]=vec[i];
		}
		sort(sorted.begin(),sorted.end());
		int i=0;
		int j=n-1;
		vector<int> b(n);
		int ans=0;
		for(int k=0;k<n;k++)
		{
			if(sorted[i]!=vec[k])
			{
				b[k]=sorted[i];
				i++;
				ans++;
			}
			else if(sorted[j]!=vec[k])
			{
				b[k]=sorted[j];
				j--;
				ans++;
			}
			else
			{
				if(i<j)
				{
					b[k]=sorted[i];
					i++;
				}
				else
				{
					b[k]=sorted[j];
					j--;
				}
			}
		}
		if(ans<n)
		{
			for(int i=n-1;i>=0;i--)
			{
				if(b[i]==vec[i])
				{
					if(b[0]!=vec[i] && b[i]!=vec[0])
					{
						swap(b[0],b[i]);
						ans++;
					}
					else if(n>1 && b[1]!=vec[i] && b[i]!=vec[1])
					{
						swap(b[1],b[i]);
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
		for(int i=0;i<n;i++)
		{
			printf("%d ",b[i]);
		}
		printf("\n");
	}
}