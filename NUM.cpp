#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
	int i,N;
	vector <int> num;
	
	while(N!=0)
	{
		cout<<" ENTER ";
		cin>>N;
		num.push_back(N);
		cout<<endl;
	}
	
	ofstream file;
	file.open("NUMBER.txt");
	for(i=0;i<num.size()-1;i++)
	{
		file<<num[i];
	}
	file.close();
}
