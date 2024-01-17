#include <iostream>
using namespace std;

int main() 
{
   int num;
   cout << "Enter an integer number : ";
   cin >> num;
   int product=1, x=num, remainder ;
   
    do
  {
   	remainder = x % 10;
   	cout << remainder;
    if (x >=10)
     cout << "*";
   else
     cout << "=";
     product = product * remainder;
     x = x / 10;
  }
   while (x>0);
  

   cout << "" << product << endl;
    if (product % 2 == 0)
    {
      cout << product << " is even number." << endl;
    }
    else
    {
        cout << product << " is odd number." << endl;
    }
     if (product%3==0 && product%5==0) 
    {
	  cout<<""<<product<<" is multiples of 3 and 5" << endl;
	}
      
     else if (product % 3 == 0) 
    {
      cout << product << " is multiples of 3." << endl;
    }
     else if (product % 5 == 0) 
    {
      cout << product << " is multiples of 5." << endl;
    }
    else
        cout<<"error";
    return 0;
}
