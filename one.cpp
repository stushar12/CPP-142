#include<bits/stdc++.h>
using namespace std;

int shortest(string str)
{
	unordered_map<char,int> m;
	set<char>st;
	for(int i=0;i<str.length();i++)
	{
		st.insert(str[i]);
	}

	int n=st.size();
	int i=0;
	int j=1;
	int count=0;

	m[str[i]]++;
	count++;

	int minimum=INT_MAX;

	while(i<=j && j<str.length())
	{
		if(count<n)
		{
			if(m[str[j]]==0)
				count++;
			j++;
			m[str[j]]++;
		}
		else if(count==n)
		{
			minimum=min(minimum,j-i);
			if(m[str[i]]==1)
				count--;
			m[str[i]]--;
			i++;
		}
	}

	while(count==n)
	{
		minimum=min(minimum,j-i);
		if(m[str[i]]==1)
			count--;
		m[str[i]]--;
		i++;

	}


cout<<minimum<<endl;
}