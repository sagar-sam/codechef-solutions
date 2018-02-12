#include <iostream>
#include <map>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		map<char,int> mp;
		vector<int> vec[26];
		for(int i=0;i<s.length();i++)
		{
			mp[s[i]]++;
			vec[s[i]-'a'].push_back(i);
		}
		int flag=0;
		for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->second%2!=0)
			{
				flag++;
			}
		}
		if(flag>1)
		{
			printf("-1\n");
			continue;
		}
		vector<int> ans(s.length());
		int ansi=0;
		int ansj=s.length()-1;
		for(int i=0;i<26;i++)
		{
			int j=0;
			int k=vec[i].size()-1;
			while(j<k)
			{
				ans[ansi]=vec[i][j];
				ans[ansj]=vec[i][k];
				ansi++;
				j++;
				ansj--;
				k--;
			}
			if(j==k)
			{
				ans[s.length()/2]=vec[i][j];
			}
		}
		for(int i=0;i<ans.size();i++)
		{
			printf("%d ",ans[i]+1);
		}
		printf("\n");
	}
}