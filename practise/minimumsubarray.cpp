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
		vector<long long int> vec(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&vec[i]);
		}
		vector<long long int> prefix(n);
		prefix[0]=vec[0];
		for(int i=0;i<n;i++){
			prefix[i]=prefix[i-1]+vec[i];
		}
		int min=INT_MAX;
		for(int i=1;i<n;i++)
		{
			int high=i;
			int low=0;
			while(low<=high)
			{

			}
		}
	}
}