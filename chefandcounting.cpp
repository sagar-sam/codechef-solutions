#include <iostream>
#include <map>
#include <vector>

using namespace std;
/*
int solve(string s, int start, int end)
{
	if(start==end)
		return 0;
	int mid=(start+end)/2;
	int ans=solve(s, start, mid) + solve(s, mid+1, end);
	map<char,int> mpl,mpr,to;
	int leftcount=0;
	int rightcount=0;
	int leftind=mid;
	int rightind=mid+1;
	int totalchar;
	//int ans=0;
	while(true)
	{
		if(leftind<start && rightind>end)
			break;
		if(leftind>=start)
		{
		if(mpl[s[leftind]]==0)
		{
			if(mpr[s[leftind]]==0)
			totalchar++;
			leftcount++;
			if(leftcount<=2)
			{
				mpl[s[leftind]]++;
				if(totalchar<=2)
				ans+=mpr[s[leftind]];
			}
		}
		else
		{
			if(leftcount<=2)
			{
				mpl[s[leftind]]++;
				ans+=mpr[s[leftind]];
			}
		}
		leftind--;
		}
		if(rightind<=end)
		{
		if(mpr[s[rightind]]==0)
		{
			if(mpl[s[rightind]]==0)
				totalchar++;
			rightcount++;
			if(rightcount<=2)
			{
				mpr[s[rightind]]++;
				if(totalchar<=2)
				ans+=mpl[s[rightind]];
			}
		}
		else
		{
			if(rightcount<=2)
			{
				mpr[s[rightind]]++;
				ans+=mpl[s[rightind]];
			}
		}
		rightind++;
		}
		if(totalchar>2)
			break;
	}
	return ans;
}

int solvea(string s, int start, int end){
	if(start<=end)
		return 0;
	int mid=(start+end)/2;
	int ans=solvea(s, start, mid) + solvea(s, mid+1, end);
	int leftind=mid,rightind=mid+1;
	int leftcount=0;
	int rightcount=0;
	char lefta,leftb;
	int leftcounta=0;
	int leftcountb=0;
	char righta,rightb;
	int rightcounta=0;
	int rightcountb=0;
	lefta=s[mid];
	leftcount=1;
	righta=s[mid+1];
	rightcount=1;
	while(leftind>=start)
	{
		if(leftcount==1)
		{
			if(s[leftind]==lefta)
			{
				leftcounta++;
			}
			else 
			{
				leftcount++;
				leftb=s[leftind];
				leftcountb++;
			}
		}
		else if(leftcount==2)
		{
			if(s[leftind]==letfa)
			{
				leftcounta++;
			}
			else if(s[leftind]==leftb)
			{
				leftcountb++;
			}
			else{
				break;
			}
		}
	}
	while(rightind<=end)
	{
		if(rightcount==1)
		{
			if(s[rightind]==righta)
			{
				rightcounta++;
			}
			else 
			{
				rightcount++;
				rightb=s[rightind];
				rightcountb++;
			}
		}
		else if(rightcount==2)
		{
			if(s[rightind]==righta)
			{
				rightcounta++;
			}
			else if(s[rightind]==rightb)
			{
				rightcountb++;
			}
			else{
				break;
			}
		}
	}
}
*/
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a;
		cin>>a;
		int ans=0;
		vector<int> vec(26);
		for(int i=0;i<26;i++)
			vec[i]=1000000;
		for(int i=0;i<a.length();i++)
		{
			if(vec[a[i]-'a']==0 || vec[a[i]-'a']==1)
			{
				ans++;
			}
			for(int i=0;i<26;i++)
			{
				vec[i]++;
			}
			vec[a[i]-'a']=0;
		}
		//int ans=solve(a, 0, a.length()-1);
		printf("%d\n",ans);
	}
}