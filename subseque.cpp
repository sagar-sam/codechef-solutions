#include <iostream>
#include <map>

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
		for(int i=0;i<s.length();i++)
		{
			mp[s[i]]++;
		}
		int flag=0;
		for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++)
		{
			if(it->second>=2)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			printf("no\n");
		else printf("yes\n");
	}
}