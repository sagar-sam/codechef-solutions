#include <iostream>
#include <vector>

using namespace std;

long long int calculate(long long int nu)
{
	long long int j=nu;
	long long int oddsum=0;
	long long int evsum=0;
	while(j>0)
	{
		long long int x=j%10;
		j=j/10;
		if(x%2==0)
		{
			evsum+=x;
		}
		else oddsum+=x;
	}
	long long int ans=abs(evsum-oddsum);
	return ans;
}
int main()
{
	vector<long long int> temp(1000005);
	vector<long long int> ans(1000005);
	temp[0]=0;
	ans[0]=0;
	temp[1]=2;
	ans[1]=2;
	for(long long int i=2;i<1000005;i++)
	{
		long long int lol=temp[i-1];
		long long int current=calculate(i);
		lol=lol-current;
		long long int j=2*i;
		long long int twice=calculate(j);
		j--;
		current=calculate(j);
		lol=lol+current;
		ans[i]=2*lol+twice+ans[i-1];
		temp[i]=lol+twice;
	}
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int q;
		scanf("%lld",&q);
		printf("%lld\n",ans[q]);
	}
}
