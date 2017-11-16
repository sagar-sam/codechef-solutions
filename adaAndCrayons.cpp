#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int countu=0;
		int countd=0;
		for(int i=0;i<s.length();i++)
		{
			char ch=s[i];
			i++;
			while(s[i]==ch)
			{
				i++;
			}
			i--;
			if(ch=='U')
				countu=countu+1;
			else if(ch=='D')
				countd=countd+1;
		}
		if(countu<countd)
			printf("%d\n",countu);
		else
			printf("%d\n",countd);
	}
	return 0;
}
