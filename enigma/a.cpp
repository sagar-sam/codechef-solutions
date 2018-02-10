#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> vec(m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&vec[i]);
	}
	long long int numbers=n-m;
	long long int places=m+1;
	long long int ans=1;
	for(int i=0;i<numbers;i++)
	{
		ans=ans*places;
		ans=ans%1000000007;
		places++;
	}
//	long long int ans=binaryExponentiation(places,numbers);
	printf("%lld\n",ans);
}