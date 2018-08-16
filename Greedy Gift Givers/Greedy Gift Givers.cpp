/*
ID:hesirig1
LANG:C++
TASK:gift1
*/
#include<iostream>
#include<map>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ifstream cin("gift1.in");
	ofstream cout("gift1.out");
	int n;
	cin>>n;
	string name[10]; 
	map<string,int> amount;
	typedef map<string,int>::iterator index;
	for(int i=0;i<n;++i)
	{
		cin>>name[i];
	    amount.insert(make_pair(name[i],0));
	}
	string giver;
	int total;
	int n_to;
	while(cin>>giver>>total>>n_to)
	{
	  if(n_to) 
	  {
		int average=total/n_to;
		int left=total%n_to;
		for(int j=0;j<n_to;++j)
		{
			string reciver;
			cin>>reciver;
			index it=amount.find(reciver);
			it->second+=average;
		}
		index self=amount.find(giver);
		self->second-=total;
		self->second+=left;
	  }
	}
	for(int i=0;i<n;++i)
	{
		index it=amount.find(name[i]);
	    cout<<it->first<<' '<<it->second<<endl;
	}
	return 0;
 } 
