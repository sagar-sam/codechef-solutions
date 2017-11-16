#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<int> w(26);
		for(int i=0;i<26;i++)
		{
			scanf("%d",&w[i]);
		}
		vector<int> occ(26);
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			occ[s[i]-'a']++;
		}
		int ans=0;
		for(int i=0;i<26;i++)
		{
			if(occ[i]==0)
				ans+=w[i];
		}
		printf("%d\n",ans);
	}
}