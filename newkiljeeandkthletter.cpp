#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
	char s[200005];
	scanf("%s",s);
	int x=strlen(s);
	map<char,map<int,int>> mp;
	int y=x;
	for(int i=0;i<x;i++)
	{
		mp[s[i]][y]++;
		y--;
	}
	vector<long long int> total(26);
	for(int i=0;i<26;i++)
	{
		total[i]=-1;
	}
	vector<long long int> vec[26];
	char ch='a';
	for(int i=0;i<26;i++)
	{
		if(mp[ch].size()==0)
		{
			vec[i].resize(0);
			total[i]=0;
			continue;
		}
		map<int,int>::iterator it = mp[ch].end();
		it--;
		int si=it->first;
		vec[i].resize(it->first);
		for(map<int,int>::iterator it=mp[ch].start();it!=mp[ch].end();it++)
		{
			vec[i][it->first]=vec[i][it->first]+(long long int)(it->second);
		}
		total[i]=vec[vec[i].size()-1];
		for(int j=vec[i].size()-2;j>=0;j--)
		{
			vec[j]+=vec[j+1];
			total[i]+=vec[j];
		}
		for(int j=1;j<vec[i].size();j++)
		{
			vec[j]+=vec[j-1];
		}
		ch++;
	}
	for(int i=1;i<26;i++)
	{
		total[i]+=total[i-1];
	}
	int q;
	scanf("%d",&q);
	long long int g=0;
	while(q--)
	{
		long long int p,m;
		scanf("%lld%lld",&p,&m);
		long long int k=(p*g)%m;
		k++;
		for(int )
	}
}