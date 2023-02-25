#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int Row,Column;
	int number[3][3];
	ifstream file;
	file.open("IN.txt");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			file>>number[i][j];	
		}				
	}		
	cout<<"Enter Row No (between 1-3)"<<endl;
	cin>>Row;
	cout<<"Enter Column No(between 1-3)"<<endl;
	cin>>Column;
	cout<<"The number at Row "<<Row<<" and Column "<<Column<<" is ";
	cout<<number[Row - 1][Column - 1];
	file.close();
}
