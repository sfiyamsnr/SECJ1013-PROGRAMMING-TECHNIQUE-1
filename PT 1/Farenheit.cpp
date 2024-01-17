#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void readFile(const string &temperatureFileName, double farenheit[], int &data);
void computeC(double farenheit[], double celcius[], int data);
double average(double celcius[], int &data);
char description(double celcius[], int &data, char desc[]);
void writeFile(double farenheit[], double celcius[], int data, char desc[]);

int main()
{
	const int i = 100;
	double farenheit[i],celcius[i], avg;
	int data, high=0, medium=0, low=0;
	char desc[i];
	
	readFile("temperatureFile.txt", farenheit, data);
	computeC(farenheit, celcius, data);	
	avg=average(celcius, data);
	description(celcius,data,desc);
	
	for (int i=0; i<data; i++)
	{
	
		if (desc[i]=='H')
		++high;
		else if (desc[i]=='M')
		++medium;
		else if (desc[i]=='L')
		++low;
	} 
	
	writeFile(farenheit, celcius, data, desc);
	
	cout << "Average of the temperature in Celcius:" << fixed << setprecision(3) << avg << endl;
	cout << "Number of high temperature:" << high << endl;
	cout << "Number of medium temperature:" << medium << endl;
	cout << "Number of low temperature:" << low << endl;
}

void readFile(const string &temperatureFile, double farenheit[], int &data)
{
	int i=0;
	
	ifstream inputFile;
	inputFile.open("temperatureFile.txt");
	
	if (!inputFile)
	{
		cout << "Input file could not be opened! Terminating!\n";
	}
	else 
	cout << "File is successfully opened" << endl;
	
	data=0;
	while (inputFile >> farenheit[i])
	{
		data++;	
		i++;
	}
	inputFile.close();
}

void computeC(double farenheit[], double celcius[], int data)
{
	for (int i = 0; i < data; i++)
	{
        celcius[i] =  (5.0/9.0)*(farenheit[i] - 32) ;
    }
}

double average(double celcius[], int &data)
{
	double sum = 0;
	for (int i = 0; i < data; i++) 
	{
        sum = sum + celcius[i];   
    }
	double avg = sum/static_cast<double>(data);
    return avg;
}

char description(double celcius[], int &data, char desc[])
{
	int high=0,medium=0,low=0;
	for(int i=0; i<data; i++)
	{
	if (celcius[i]>=35)
	desc[i]='H';
	else if (celcius[i]<35 && celcius[i]>=20)
	desc[i]='M';
	else if (celcius[i]<20)
	desc[i]='L'; 
	return desc[i];
    }
   
}

void writeFile(double farenheit[], double celcius[], int data, char desc[])
{
	ofstream outputFile;
	outputFile.open("output.txt");
	
	outputFile << setw(15) << "C(Celcius)" << setw(15) << "F(Farenheit)" << setw(15) << "Description" << endl;
	outputFile << setw(15) << "==========" << setw(15) << "============" << setw(15) << "===========" << endl;
	
	for(int i=0; i<data; i++)
	{
		outputFile << setw(15) << fixed << setprecision(2) << celcius[i] 
		           << setw(15) << fixed << setprecision(2) << farenheit[i] 
		           << setw(15) << fixed << desc[i] << endl;
	}
	
	outputFile.close();
}
