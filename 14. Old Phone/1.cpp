#include <bits/stdc++.h>
using namespace std;
bool vis[10000];
int main()
{
	int t;   cin>>t;
	while(t--)
	{
		int n,m,lim;   cin>>n>>m>>lim;
		vector<int> v,o;
		queue<pair<int,int> > q;
		for(int i=0;i<n;++i)
		{
			int x;  cin>>x;
			v.push_back(x);
			q.push(make_pair(x,1));
		}
		for(int i=0;i<m;++i)
		{
			int x;   cin>>x;
			o.push_back(x);
		}
		int y;   cin>>y;
		pair<int,int> re;
		while(!q.empty())
		{
			int x = q.front().first;
			int l = q.front().second;
			
			if(x==y)
			{
				re.first = y;
				re.second = l;
				break;
			}
			q.pop();
			
			if(!vis[x])
			{
			
			for(int i=0;i<n;++i)
			{
				q.push(make_pair(x*10 + v[i],l+1));
			}
			
			for(int i=0;i<m;++i)
			{
				for(int j=0;j<n;++j)
				{
					if(o[i]==1)
					{
						q.push(make_pair(x+v[j],l+3));
					}
					else if(o[i]==2)
					{
						q.push(make_pair(x-v[j],l+3));						
					}
					else if(o[i]==3)
					{
						q.push(make_pair(x*v[j],l+3));						
					}
					else if(o[i]==4)
					{
						q.push(make_pair(x/v[j],l+3));						
					}					
				}
			}
			
			vis[x] = true;			
		    }
		}		
		cout<<re.second<<endl;		
	}
}