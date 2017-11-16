#include <iostream>
#include <limits>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	while(t--)
	{
		string s;
		//fflush(stdin);
		getline(cin,s);
		int count=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='A' && s[i]<='Z')
				s[i]=s[i]+32;
			if(i==0)
			{
				if(s[i]>='a' && s[i]<='z')
				{
					s[i]=s[i]-32;
				}
			}
			if(s[i]==' ')
			{
				count++;
			}
		}
		if(count==0)
		{
			cout<<s;
		}
		else if(count==1)
		{
			int i=0;
			printf("%c. ",s[i]);
			while(s[i]!=' ')
				i++;
			i++;
			if(s[i]>='a' && s[i]<='z')
			{
				s[i]=s[i]-32;
			}
			while(i<s.length())
			{
				printf("%c",s[i++]);
			}
		}
		else if(count==2)
		{
			int i=0;
			printf("%c. ",s[i]);
			while(s[i]!=' ')
				i++;
			i++;
			if(s[i]>='a' && s[i]<='z')
			{
				s[i]=s[i]-32;
			}
			printf("%c. ",s[i]);
			i++;
			while(s[i]!=' ')
				i++;
			i++;
			if(s[i]>='a' && s[i]<='z')
			{
				s[i]=s[i]-32;
			}
			while(i<s.length())
			{
				printf("%c",s[i]);
				i++;
			}
		}
		printf(" \n");
	}
}