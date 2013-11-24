#include <iostream>
#include<fstream>
#include "Main.h"
#include "Business.h"

using namespace std;

int main()
{
  business MoesBar, ComicBookStore;
  customer ArrayCustomers[NUMBER_CUSTOMERS];
  string TempName;
  string TempInclination;

  ifstream fin;
  fin.open("customers.dat");
  // Defines the customers in the array
  for (int i = 0; i < NUMBER_CUSTOMERS;i++)
  {
    //fin >> TempName;
	getline(fin,TempName,',');
	fin.ignore(30,' ');
	getline(fin,TempInclination);
	ArrayCustomers[i].change_name(TempName);
	if(TempInclination == "1")
	  ArrayCustomers[i].SetInclination(1);
	else if (TempInclination =="-1")
      ArrayCustomers[i].SetInclination(-1);
	
  }
  fin.close();
  
  // Enters the customers into their appropriate stores 
  for(int i = 0; i < NUMBER_CUSTOMERS;i++)
  {
    if(ArrayCustomers[i].GetInclination() == 1)
	{
	  ComicBookStore.enter_customer(ArrayCustomers[i]);
	}
	if(ArrayCustomers[i].GetInclination() == -1)
	{
		MoesBar.enter_customer(ArrayCustomers[i]);
	}
  }
  cin >> TempInclination;
  return(0);
}