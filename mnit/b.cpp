#include <bits/stdc++.h>
using namespace std;
 
// Driver code
int main ()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        priority_queue <int, vector<int>, greater<int> > pq;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            pq.push(a);
        }
    // Creates a max heap
    long long int ans=0;
    while(pq.size()!=1)
    {
        int x,y;
        x=pq.top();
        pq.pop();
        y=pq.top();
        pq.pop();
        ans=ans+(long long int)(x)+(long long int)(y);
        ans=ans%1000000007;
        long long int z=(long long int)(x)+(long long int)(y);
        z=z%1000000007;
        int l=(int)(z);
        pq.push(l);
    }    
    printf("%lld\n",ans); 
}
return 0;
}