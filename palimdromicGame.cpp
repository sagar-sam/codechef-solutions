#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a,b;
		cin>>a;
		cin>>b;
		map<char,int> a1,b1;
		for(int i=0;i<a.length();i++)
		{
			a1[a[i]]++;
			b1[b[i]]++;
		}
		int flag=0;
		for(map<char,int> :: iterator it=a1.begin();it!=a1.end();it++)
		{
			if(b1[it->first]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("B\n");
			continue;
		}
		flag=0;
		for(map<char,int> :: iterator it=a1.begin();it!=a1.end();it++)
		{
			if(it->second>1 && b1[it->first]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("A\n");
			continue;
		}
		flag=0;
		for(map<char,int> :: iterator it=b1.begin();it!=b1.end();it++)
		{
			if(a1[it->first]==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("A\n");
		}
		else
		{
			printf("B\n");
		}
	}
}
