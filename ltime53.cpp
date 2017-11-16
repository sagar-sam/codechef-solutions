#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		int ans=0;
		vector<int> vec;
		string s="";
		while(a!=0 || b!=0)
		{
			int x=a%10;
			int y=b%10;
			int z=x+y;
			//printf("%d ",z);
			//if(a>9 || b>9)
			z=z%10;
			vec.push_back(z);
			a=a/10;
			b=b/10;
			//char ch=z+'0';
			//s.prepend(ch);
		//	s=ch+s;
//			ans=ans*10+z;
		}
		//cout<<s<<endl;
		int i=vec.size()-1;
		while(i>=0 && vec[i]==0)
		{
			i--;
		}
		if(i==-1)
			printf("0");
		while(i>=0)
		{
			printf("%d",vec[i]);
			i--;
		}
		/*while(i<s.length() && s[i]=='0')
			i++;
		while(i<s.length())
		{
			printf("%c",s[i]);
			i++;
		}
/*		for(;i<s.length();i++)
		{
			printf("%c",s[i]);
		}
	/*	for(int i=vec.size()-1;i>=0;i--)
		{
			while(i>=0 && vec[i]==0)
				i--;
			i++;
			if(i==0)
				break;
			printf("%d",vec[i]);
		}*/
		printf("\n");
//		cout<<s<<"\n";
		//printf("%d\n",ans);
	}
}