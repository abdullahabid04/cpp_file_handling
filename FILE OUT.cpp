#include<iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	int N=1,i=0,x=0;
	vector <int> num;
	
	while(N!=0)
	{
		cout<<"ENTER NUMBER "<<++x<<" : ";
		cin>>N;
		num.push_back(N);
	}
	
	ofstream file;
	file.open("OUT.txt");
	
	for(i=0;i<num.size()-1;i++)
	{
		file<<num[i]<<" ";	
	}
	file.close();
}
