#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

int h,i,j,k,s,t;
int sum_of_temprature = 0;		
int sum_of_humidity = 0;
int sum_of_soil_moisture = 0;
int PTavg,PHavg,PSavg,NTavg,NHavg,NSavg;
int data[4][10];
int mango[4][10];
int new_array[4][12];
int array[4][12];
int average[4][10];
float Tavg,Havg,Savg;
const float x = 0.25;
vector <int> temp,hum;
vector <int> same_parameters;

void get_data()
{
	for(j=0;j<10;j++)
	{
		if(Tavg < mango[1][j])
		{
			temp.push_back(mango[0][j]);
		}
	}
	for(j=0;j<10;j++)
	{
		if(Havg > mango[2][j])
		{
			hum.push_back(mango[0][j]);
		}
	}
	cout<<"\n";
	cout<<"Days with temprature greater than tepmrature average\n";
	for(t=0;t<temp.size();t++)
	{
		cout<<temp[t]<<"\t";
	}
	cout<<"\n\n";
	cout<<"Days with humidity smaller than humidity average\n";	
	for(h=0;h<hum.size();h++)
	{
		cout<<hum[h]<<"\t";
	}
	cout<<"\n";
}
void averages()
{
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		{
			cout<<mango[i][j]<<"\t";
		}
		cout<<"\n\n";
	}
	for(j=0;j<10;j++)
	{
		sum_of_temprature = sum_of_temprature + mango[1][j];	
		
		sum_of_humidity = sum_of_humidity + mango[2][j];	

		sum_of_soil_moisture = sum_of_soil_moisture + mango[3][j];	
	}
	Tavg = sum_of_temprature/10;
	Havg = sum_of_humidity/10;
	Savg = sum_of_soil_moisture/10;
	cout<<"\n\n";
	cout<<"Average of temprature : "<<Tavg<<"\nAverage of humidity : "<<Havg<<"\nAverage of soil moisture : "<<Savg;
	cout<<"\n";
}
void parameters()
{
	PTavg = Tavg + ((x) * (Tavg));
	NTavg = Tavg - ((x) * (Tavg));
	PHavg = Havg + ((x) * (Havg));
	NHavg = Havg - ((x) * (Havg));
	PSavg = Savg + ((x) * (Savg));
	NSavg = Savg - ((x) * (Savg));
	for(j=0;j<10;j++)
	{
		if((mango[1][j]<PTavg && mango[1][j]>NTavg) && (mango[2][j]<PHavg && mango[2][j]>NHavg) && (mango[3][j]<PSavg && mango[3][j]>NSavg))
		{
			same_parameters.push_back(mango[0][j]);
		}
	}
	cout<<"\n";
	cout<<"Days in which three parameters are in range(-25% -to- +25%)\n";
	for(s=0;s<same_parameters.size();s++)
	{
		cout<<same_parameters[s]<<"\t";
	}	
}
void three_day()
{
	cout<<"\n\n";
	for(k=0,j=0;k<10,j<12;k++,j++)
	{
		average[1][k] = (array[1][j] + array[1][j+1] + array[1][j+2])/3;
		average[2][k] = (array[2][j] + array[2][j+1] + array[2][j+2])/3;
		average[3][k] = (array[3][j] + array[3][j+1] + array[3][j+2])/3;
	}
	cout<<"3-day moving average\n\n";
	for(j=0;j<10;j++)
	{
		cout<<average[1][j]<<"\t";
	}
	cout<<"\n\n";
	for(j=0;j<10;j++)
	{
		cout<<average[2][j]<<"\t";
	}
	cout<<"\n\n";
	for(j=0;j<10;j++)
	{
		cout<<average[3][j]<<"\t";
	}	
}

int main()
{
	ifstream file;
	file.open("mango.txt");
	for(i=0;i<4;i++)
	{
		for(j=0;j<10;j++)
		{
			file>>data[i][j];
			mango[i][j] = data[i][j];
		}
	}
	file.close();
	
	averages();
	get_data();
	parameters();
	
	ifstream new_file;
	new_file.open("farm.txt");
	for(i=0;i<4;i++)
	{
		for(j=0;j<12;j++)
		{
			new_file>>new_array[i][j];
			array[i][j] = new_array[i][j];
		}
	}
	file.close();
	
	three_day();
}
