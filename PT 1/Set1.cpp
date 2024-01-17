#include <iostream>
using namespace std;

int main() 
{
   int num;
   cout << "Enter an integer number : ";
   cin >> num;
   int sum = 0, x=num, remainder;
   
   do
  {
   	remainder = x % 10;
   	 cout << remainder;
   if (x >=10)
     cout << "+";
   else
     cout << "=";
     sum = sum + remainder;
     x = x / 10;
  }
   while (x>0);
   
   cout << "" << sum << endl;
   	if (sum%3==0 && sum%4==0 && sum%5==0)
   	{
	  cout<<""<<sum<<" is multiples of 3, 4 and 5" << endl;
	}
    else if (sum%3==0 && sum%4==0)
    {
	  cout<<""<<sum<<" is multiples of 3 and 4" << endl;
	}
      
    else if (sum%3==0 && sum%5==0) 
    {
	  cout<<""<<sum<<" is multiples of 3 and 5" << endl;
	}
     
    else if (sum%4==0 && sum%5==0)
    {
	  cout<<""<<sum<<" is multiples of 4 and 5" << endl;
	}
      
    else if (sum % 3 == 0)
    {
      cout << "" << sum << " is multiples of 3." << endl;
    }
    else if (sum % 4 == 0) 
    {
      cout <<  "" <<sum << " is multiples of 4." << endl;
    }
    else if (sum % 5 == 0)
    {
      cout <<  "" <<sum << " is multiples of 5." << endl;
    }
    else
        cout<<"error";

    return 0;
}
