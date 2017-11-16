#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<long long int> size(65);
	size[0]=1;
	for(int i=1;i<65;i++)
	{
		size[i]=size[i-1]*2;
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long long int n,k;
		scanf("%lld%lld",&n,&k);
		long long int l=k+1;
		long long int s=size[n];
		//printf("%lld\n",s);
		long long int ans=0;
		while(s!=1)
		{
			if(k%2==0)
			{
				s=s/2;
				k=k/2;
				//ans+=k;
			}
			else
			{
				s=s/2;
				k=k/2;
				ans+=s;
			}
		}
		printf("%lld\n",ans);
	}
}