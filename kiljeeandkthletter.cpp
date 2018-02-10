#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	cin>>s;
	vector<string> se;
	for(int i=0;i<s.length();i++)
	{
		string temp="";
		for(int j=i;j<s.length();j++)
		{
			temp=temp+s[j];
			se.push_back(temp);
		}
	}
	sort(se.begin(),se.end());
	string ans="";
	for(vector<string>::iterator it=se.begin();it!=se.end();it++)
	{
		ans=ans+(*it);
	}
//	cout<<ans<<endl;
	//printf("ready");
	int q;
	scanf("%d",&q);
	long long int g=0;
	while(q--)
	{
		long long int p,m;
		scanf("%lld%lld",&p,&m);
		long long int ind=(p*g)%m+1;
		char ch=ans[ind-1];
		printf("%c\n",ans[ind-1]);
		g=g+(long long int)(ch);
	}
}