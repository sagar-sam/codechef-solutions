#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<string> vec(n);
		int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
		for(int i=0;i<n;i++)
		{
			cin>>vec[i];
			if(vec[i]=="cakewalk")
				flag1=1;
			else if(vec[i]=="simple")
				flag2=1;
			else if(vec[i]=="easy")
				flag3=1;
			else if(vec[i]=="easy-medium" || vec[i]=="medium")
				flag4=1;
			else if(vec[i]=="medium-hard" || vec[i]=="hard")
				flag5=1;
		}
		if(flag1 && flag2 && flag3 && flag4 && flag5)
		{
			printf("Yes\n");
		}
		else printf("No\n");
	}
}