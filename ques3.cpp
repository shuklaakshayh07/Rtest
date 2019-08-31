#include <bits/stdc++.h>

#define ll long long int
using namespace std;
vector <pair<int,int>> ans;
int digit(int n)
{
	ll count=0;
	while(n>0)
	{
		count++;
		n=n/10;
	}
	return count;
}
void check(int i,int n)
{
	map<int,int> ma;
	ll count1=0;
	vector<int> v1,v2;
	ll p=i;
	ll count=0;
	while(i>0)
	{
		v1.push_back(i%10);
		i=i/10;
		count++;
	}
	reverse(v1.begin(),v1.end());
	ll j;
	for(i=0;i<v1.size();i++)
	{
		ll anss=0;
		count1=count-2;
		for(j=0;j<v1.size();j++)
		{
			if(i!=j)
			{
				anss=anss+v1[j]*pow(10,count1);
				count1--;
			}
		}
		if(anss+p==n && ma[p]==0)
		{
			ma[p]++;
			ans.push_back(make_pair(p,anss));
		}
	}


}
int main()
{
	ll n;
	cin>>n;
	ll i;
	for(i=0;i<=n;i++)
	{
		check(i,n);
	}
	cout<<ans.size()<<" pairs found:"<<endl;
	for(i=0;i<ans.size();i++)
	{
		ll x1=digit(ans[i].first);
		ll x2=digit(ans[i].second);
		if(x1-x2!=1)
		{
			ll z1=x1-x2-1;
			cout<<ans[i].first<<"+";
			ll j;
			for(j=0;j<z1;j++)
			{
				cout<<0;
			}
			cout<<ans[i].second<<"="<<n<<endl;
		}
		else
		{
			cout<<ans[i].first<<"+"<<ans[i].second<<"="<<n<<endl;
		}

	}
}
