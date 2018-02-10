#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> sieve(30000001);

void calculate_sieve()
{
	for(int i=0;i<30000001;i++)
	{
		sieve[i]=-1;
	}

	for(int i=4;i<30000001;i+=2)
	{
		sieve[i]=2;
	}

	for(int i=3;i*i<30000001;i+=2)
	{
		if(sieve[i]==-1)
		{
			for(int j=i*i;j<30000001;j+=i)
			{
				if(sieve[j]==-1)
				{
					sieve[j]=i;
				}
			}
		}
	}
}

int maina()
{
	calculate_sieve();
	long long int n;
	scanf("%lld",&n);
	long long int m=3*n;
	long long int x=sqrt(m);
	map<long long int,int> mp;
	vector<long long int> vec;
	for(long long int i=4;i<=m;i=i+4)
	{
		vec.push_back(i);
		mp[i]++;
	}
	vector<int> consider;
	for(int i=3;i<=x;i=i+2)
	{
		if(sieve[i]==-1)
		{
			consider.push_back(i);
		}
	}
	for(int i=0;i<consider.size();i++)
	{
			long long int sa=consider[i]*consider[i];
			for(long long int j=sa;j<=m;j=j+sa)
			{
				if(mp[j]==0)
				{
					mp[j]++;
	//				s.insert(j);
					vec.push_back(j);
				//	printf(" %d ",j);
				}
		//		s.insert(j);
			}
	}
	sort(vec.begin(),vec.end());
	printf("%lld\n",vec[n-1]);
}


int main()
{
	calculate_sieve();
	long long int n;
	scanf("%lld",&n);
	long long int start=2*n;
	long long int end=4*n;
	long long int x=sqrt(end);
	while(start<=end)
	{
		long long int mid=start+(end-start)/2;
		long long int count=0;
		for(long long int i=2;i<=x;i++)
		{
			if(sieve[i]==-1)
			{
				long long int cal=mid/(i*i);
				count+=cal;
			}
			else
			{
				int flag=0;
				long long int j=i;
				map<long long int,int> mp;
				mp[sieve[j]]++;
				while(sieve[j]!=-1)
				{
					j=j/sieve[j];
					if(sieve[j]==-1)
					{
						mp[j]++;
//						if(mp[j]==1)
//						{
//							flag=1;
//						}
//						else mp[j]++;
					}
					else
					{
						mp[sieve[j]]++;
//						if(mp[sieve[j]]==1)
//						{
//							flag=1;
//						}
//						else mp[sieve[j]]++;
					}
				}
				for(map<long long int,int>::iterator it=mp.begin();it!=mp.end();it++)
				{
					if(it->second>1)
					{
						flag=1;
					}
				}
				if(flag==0)
				{
					long long int cal=mid/(i*i);
					long long int terms=mp.size();
				//	terms--;
				//	cal=cal*terms;
					if(terms%2==0)
					count=count-cal;
					else count=count+cal;
				}
			}
		}
		if(count==n)
		{
			long long int te=mid;
			int flag=0;
			for(long long int i=2;i*i<=te;i++)
			{
				long long int j=i*i;
				if(te%j==0)
				{
					flag=1;
					break;
				}
			}
//			map<long long int,int> ne;
//			ne[sieve[te]]++;
//			int flag=0;
//			while(sieve[te]!=-1)
//			{
//				te=te/sieve[te];
//				if(sieve[te]==-1)
//				{
//					if(ne[te]==1)
//					{
//						flag=1;
//						break;
//					}
//				}
//				else
//				{
//					if(ne[sieve[te]]==1)
//					{
//						flag=1;
//						break;
//					}
//					else ne[sieve[te]]++;
//				}
//			}
			if(flag==1)
			{
				printf("%lld\n",mid);
				break;
			}
			else
			{
				end=mid-1;
			}
		}
		else if(count>n)
		{
			end=mid-1;
		}
		else start=mid+1;
	}
}

