#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

string name,city,gender;
int age;
int serial_no=1;
int male_count=0,female_count=0;
float height,weight;
vector <int> sr,ages;
vector <float> weights,heights;
vector <string> names,cities,genders;

void data_saving() 
{
	ofstream file;
	file.open("Data.txt");
	file<<"Number of people : "<<serial_no<<endl;
	file<<"Number of male people : "<<male_count<<endl;
	file<<"Number of female people : "<<female_count<<endl;
	file<<"Complete People Summary :"<<endl;
	file<<"-------------------------"<<endl;
	file<<setw(6)<<"Serial"<<setw(14)<<"Name"<<setw(15)<<"Age"<<setw(19)<<"Weight"<<setw(16)<<"Height"<<setw(16)<<"Gender"<<setw(14)<<"City"<<endl;
	for(int i=0;i<sr.size();i++)
	{
		file<<sr[i]<<setw(23);
		file<<names[i]<<setw(10);
		file<<ages[i]<<setw(16);
		file<<weights[i]<<setw(17);
		file<<heights[i]<<setw(14);
		file<<genders[i]<<setw(25);
		file<<cities[i]<<setw(32);
		file<<endl<<setw(0);		
	}
	file.close();
}
void data_clearing() 
{
	for(int i=0;i<sr.size();i++)
	{
		sr.pop_back();
		names.pop_back();
		cities.pop_back();
		genders.pop_back();
		ages.pop_back();
		weights.pop_back();
		heights.pop_back();
	}
}

int main()
{
	while(1)
	{
		cout<<"Serial no : "<<serial_no<<endl;
		sr.push_back(serial_no);
		cout<<"Enter Name : ";
		cin>>name;
		names.push_back(name);
		cout<<"Enter age : ";
		cin>>age;
		ages.push_back(age);
		cout<<"Enter weight : ";
		cin>>weight;
		weights.push_back(weight);
		cout<<"Enter height : ";
		cin>>height;
		heights.push_back(height);
		cout<<"Enter gender (M or F) : ";
		cin>>gender;
		while(1)
		{
			if(gender=="M")
			{
				male_count++;
				break;
			}		
			if(gender=="F")
			{
				female_count++;
				break;
			}		
			else
			{
				cout<<"Please enter a valid gender : ";
				cin>>gender;
			}
		}
		genders.push_back(gender);
		cout<<"Enter city : ";
		cin>>city;
		cities.push_back(city);
		cout<<"Data has been recorded"<<endl;
		serial_no++;
		system("pause");
		system("cls");
		data_saving();
	}
}
