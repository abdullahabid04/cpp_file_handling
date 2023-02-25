#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int mark;
	int row,column;
	int marks[4][4];
	int numbers[4][4];
	char option;
	ifstream file;
	file.open("marks.txt");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			file>>marks[i][j];
			numbers[i][j] = marks[i][j];
		}
	}
	file.close();
	while(1)
	{
		cout<<"Enter option : ";
		cin>>option;
	
		switch(option)
		{
			case 'O':
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
					{
						cout<<numbers[i][j]<<"\t";
					}
					cout<<"\n\n";
				}
				system("pause");
				system("cls");
				break;
			case 'C':
				cout<<"Enter row<1-4> and column<1-4> for change marks"<<endl;
				cout<<"Row : ";
				cin>>row;
				cout<<"Column : ";
				cin>>column;
				if((row>0 && row<5) && (column>0 && column <5))
				{
					cout<<numbers[row-1][column-1]<<"\n";
					cout<<"Enter new marks : ";
					cin>>mark;
					numbers[row-1][column-1] = mark;					
				}
				else
				{
					cerr<<"out of range\n";
				}
				break;
			case 'D':
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
					{
						numbers[i][j] = 0;
					}
				}			
				break;
			case 'N':
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
					{
						cout<<"Enter marks for row "<<i+1<<" and column "<<j+1<<" : ";
						cin>>numbers[i][j];
					}
				}
				system("cls");			
				break;
			case 'S':
				ofstream file;
				file.open("marks.txt");
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
					{
						file<<numbers[i][j]<<"\t";
					}
					file<<"\n\n";
				}							
				file.close();
				cout<<"Data has been saved successfully";
				exit(1);
				break;
		}
	}
}
