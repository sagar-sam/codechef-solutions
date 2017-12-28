#include <iostream>
#include <map>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		string s1,s2;
		if(n!=0)
			cin>>s1;
		map<string,int> mp;
		mp[s1]++;
		for(int i=1;i<n;i++)
		{
			string temp;
			cin>>temp;
			if(temp!=s1)
				s2=temp;
			mp[temp]++;
		}
		if(mp[s1]==mp[s2])
			printf("Draw\n");
		else if(mp[s1]>mp[s2])
			cout<<s1<<"\n";
		else cout<<s2<<"\n";
	}
}