#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <math.h>

using namespace std;

vector<int> sieve(1000005);

void calculate_sieve()
{
	for(int i=0;i<1000005;i++)
	{
		sieve[i]=-1;
	}

	for(int i=4;i<1000005;i+=2)
	{
		sieve[i]=2;
	}

	for(int i=3;i*i<1000005;i+=2)
	{
		if(sieve[i]==-1)
		{
			for(int j=i*i;j<1000005;j+=i)
			{
				if(sieve[j]==-1)
				{
					sieve[j]=i;
				}
			}
		}
	}
}

int main()
{
	calculate_sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int m=n;
		map<int,int> mp;
		while(sieve[m]!=-1)
		{
			mp[sieve[m]]++;
			m=m/sieve[m];
		}
		mp[m]++;
//		int ans=0;
		int count1=0;
		int count2=0;
		int chance=0;
		map<int,int>::iterator it1=mp.begin();
		it1++;
		vector<int> vec;
		int count=mp.size();
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			vec.push_back(it->second);
		}
		
	}
}