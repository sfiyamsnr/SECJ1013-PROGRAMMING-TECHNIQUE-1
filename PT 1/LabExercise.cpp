#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
void dispStatus (int activeCases);
void getInput(int &totalCases, int &newCases, int &totalDeath, int &totalRecovered);
void dispOutput (int &activeCases);
double calcAverage (int numOfStates, int totalActiveCases);

int main ()
{
	string stateName, highestStateName;
	int totalCases, newCases, totalDeath, totalRecovered, activeCases;
	int numOfStates = 0;
	int totalActiveCases = 0;
	int highestActiveCases = -9999; 
	char press;
	double average;
	
	do
	{
		cout << "\n<<<<<<<<<<<<<  DATA  >>>>>>>>>>>>>" << endl;
		cout << "Please enter name of state: ";
		getline(cin,stateName);
		
		getInput(totalCases, newCases, totalDeath, totalRecovered);
		activeCases = totalCases + newCases - totalDeath - totalRecovered;
		
		cout << "\n<<<<<<<<<<<<<  SUMMARY  >>>>>>>>>>>>>" << endl;
		cout << "Active cases: " << activeCases << endl;
		dispOutput (activeCases);
		
		
		cout << "\n\nPress <ENTER> to continue...";
		cin.ignore();
		cin.get(press);
		
		numOfStates++;
		
		if (activeCases > highestActiveCases)
		{
		  highestActiveCases = activeCases;
		  highestStateName = stateName;
	    }
		totalActiveCases = totalActiveCases + activeCases;
	}
	while (isspace(press));
	
	average = calcAverage (numOfStates, totalActiveCases);
	
	cout << "\n<<<<<<<<<<<<<  ACTIVE CASES  >>>>>>>>>>>>>" << endl;
	cout << "Total : " << totalActiveCases << endl;
	cout << "Highest : " << highestActiveCases << " (" << (highestStateName)<< ")"<< endl;
	cout << "Average for " << numOfStates <<" states: " <<average << endl;

}

void dispStatus (int activeCases)
{
	if (activeCases == 0)
	  cout << "Status : Green Zone";
	else if (activeCases >=1 && activeCases <=20)
	  cout << "Status : Yellow Zone";
	else if (activeCases >=21 && activeCases <=40)
	  cout << "Status : Orange Zone";
	else 
	  cout << "Status : Red Zone";
}

void getInput(int &totalCases, int &newCases, int &totalDeath, int &totalRecovered)
{
	cout << "Please enter total cases: ";
	cin >> totalCases;
	
	cout << "Please enter new cases: ";
	cin >> newCases;
	
	cout << "Please enter total death: ";
	cin >> totalDeath;
	
	cout << "Please enter total recovered: ";
	cin >> totalRecovered;
}

void dispOutput (int &activeCases)
{
	dispStatus(activeCases);
	
}

double calcAverage (int numOfStates, int totalActiveCases)
{
	double average = totalActiveCases/numOfStates;
	return average;
}

