#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int count=0;
	for(int i=0;i<5;i++)
	{
		int a;
		scanf("%d",&a);
		if(a)
			count++;
	}
	if(count==0)
		printf("Beginner\n");
	else if(count==1)
		printf("Junior Developer\n");
	else if(count==2)
		printf("Middle Developer\n");
	else if(count==3)
		printf("Senior Developer\n");
	else if(count==4)
		printf("Hacker\n");
	else printf("Jeff Dean\n");
}
}