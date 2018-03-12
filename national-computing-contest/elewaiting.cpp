#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

int main()
{
	vector<long long int> vec(10005);
	vec[1]=1;
	vec[2]=3;
	for(int i=3;i<10005;i++)
	{
		vec[i]=vec[i-1]*i;
		vec[i]=vec[i]%1000000007;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		map<int,int> mp;
		char ch[10];
		for(int i=0;i<n;i++)
		{
			int cur=0;
			scanf("%s",ch);
			if(ch[1]==':')
			{
				cur=(ch[0]-'0')*60;
				int temp=ch[2]-'0';
				temp=temp*10+(ch[3]-'0');
				cur=cur+temp;
			}
			else{
				cur=(ch[0]-'0');
				cur=cur*10+(ch[1]-'0');
				cur=cur*60;
				int temp=ch[3]-'0';
				temp=temp*10+(ch[4]-'0');
				cur=cur+temp;
			}
			mp[cur]++;
		}
		long long int ans=1;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			ans=ans*vec[it->second];
			ans=ans%1000000007;
		}
		printf("%lld\n",ans);
	}
}