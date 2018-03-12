#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long int n,q;
	scanf("%lld%lld",&n,&q);
	vector<long long int> vec(n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&vec[i]);
	}
	while(q--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==1)
		{
			vec[b-1]=c;
		}
		else if(a==2)
		{
			b--;
			c--;
			vector<long long int> temp;
			for(int i=b;i<=c;i++)
			{
				temp.push_back(vec[i]);
			}
			sort(temp.begin(),temp.end());
			int si=temp.size();
			long long int ans=0;
			for(int i=si-3;i>=0;i--)
			{
				if(temp[i]+temp[i+1]>temp[i+2])
				{
					ans=temp[i]+temp[i+1]+temp[i+2];
					break;
				}
			}
			printf("%lld\n",ans);
		}
	}
}