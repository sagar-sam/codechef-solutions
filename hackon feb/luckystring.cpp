#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	long long int i=1;
	long long int tot=0;
	int x=0;
	while(tot<=1000000000000000000)
	{
		x++;
		i=i*2;
		tot=tot+i;
		vec.push_back(tot);
	}
//	printf("%d\n",x);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int q;
		scanf("%lld",&q);
		int i;
		for(i=0;i<59;i++)
		{
			if(q<=vec[i])
				break;
		}
		int number;
		if(i==0)
			number=q;
		else number=q-vec[i-1];
		number--;
		i++;
		string ans="";
		for(int j=0;j<i;j++)
		{
			int l=number%2;
			if(l==0)
				ans="5"+ans;
			else ans="8"+ans;
			number=number/2;
		}
		cout<<ans<<endl;
	}
}