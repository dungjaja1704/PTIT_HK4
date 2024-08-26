#include<bits/stdc++.h>
using namespace std;

int check(string s)
{
	stack<char> a = stack<char>();
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='{' || s[i]=='[' || s[i]=='(') a.push(s[i]);
		else 
		{
			if(a.empty()) return 0;
			else if(s[i]==')' && a.top()=='(') a.pop();
			else if(s[i]==']' && a.top()=='[') a.pop();
			else if(s[i]=='}' && a.top()=='{') a.pop();
			else return 0;
			
		}
	}
	if(a.size()==0) return 1;
	else return 0;
	
}

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string s;
		cin>>s;
		if(check(s)==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
return 0;
}


