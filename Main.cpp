#include <iostream>
#include<fstream>
#include "Main.h"
#include "Business.h"
#include "Customer.h"

using namespace std;

int main()
{
  srand(time(NULL));
  business MoesBar, ComicBookStore;
  customer ArrayCustomers[NUMBER_CUSTOMERS];
  string TempName;
  string TempInclination;
  int IndexVictum;
  int NumberCustomers = NUMBER_CUSTOMERS;
  int Cycles = 0;

  ifstream fin;
  fin.open("customers.dat");
  // Defines the customers in the array
  for (int i = 0; i < NUMBER_CUSTOMERS;i++)
  {
	getline(fin,TempName,',');
	fin.ignore(30,' ');
	getline(fin,TempInclination);
	ArrayCustomers[i].change_name(TempName);
	if(TempInclination == "1")
	  ArrayCustomers[i].SetInclination("1");
	else if (TempInclination =="-1")
      ArrayCustomers[i].SetInclination("-1");
	
  }
  fin.close();

  MoesBar.get_items(MOES_SUPPLIER);
  ComicBookStore.get_items(COMIC_BOOOK_SUPPLIER);

  while(Cycles <= MAX_CYCLES && NumberCustomers > 1)
  {
    // Enters the customers into their appropriate stores
	// Should check to determine if people should leave in 
	cout << "The current state of the town is:" << endl;
	for(int i = 0; i < NumberCustomers;i++)
	{
	  cout << ArrayCustomers[i] << endl;
	}
	for(int i = 0; i < NumberCustomers;i++)
    {
	  if(ArrayCustomers[i].GetInclination() == "1" && 
        ArrayCustomers[i].GetHappiness() < MAX_HAPPINESS &&
        ArrayCustomers[i].GetHappiness() > MIN_HAPPINESS)
	  {
	    ComicBookStore.addCustomer(ArrayCustomers[i]);
		NumberCustomers--;
	  }
	  else if(ArrayCustomers[i].GetInclination() == "-1" && 
		ArrayCustomers[i].GetHappiness() < MAX_HAPPINESS && 
		ArrayCustomers[i].GetHappiness() > MIN_HAPPINESS)
	  {
        MoesBar.addCustomer(ArrayCustomers[i]);
		NumberCustomers--;
      }
	  else
	  {
	    cout << ArrayCustomers[i].get_name() << "Has made it to ShelbyVille"
        <<" on round " << Cycles << "."<< endl;
		NumberCustomers--;
	  }
	  
    }
	NumberCustomers = 1; // redundant, but effective
    // Sells items to customers
	MoesBar.make_a_sale();
	ComicBookStore.make_a_sale();

	// Customers leave bars and mingles in streets
    MoesBar.customers_leave(ArrayCustomers,NumberCustomers);
    ComicBookStore.customers_leave(ArrayCustomers,NumberCustomers);
    
	// Simulates the robbing and throwing 
	// all happiness modifications should be done in functions
	for(int i = 0;i<NUMBER_CUSTOMERS;i++)
    {
      IndexVictum = rand()%(NUMBER_CUSTOMERS);
	  if(ArrayCustomers[i].GetInclination() == ArrayCustomers[IndexVictum].GetInclination())
	  {
        ArrayCustomers[i].rob(ArrayCustomers[IndexVictum]); // possibly incomplete-check
	  }

	  else
	  {
	    ArrayCustomers[i].ThrowItem(ArrayCustomers[IndexVictum]); // possibly incomplete - check
	  }
    }
	Cycles++;
  }
  cout << "The winner(s) of living in springfield is(are)!!!!!!  " << endl
	  << "***LOTS OF DRUMROLLS AND FIREWORKS AND OTHER COOL STUFF***" << endl;
  for (int i = 0; i < NumberCustomers;i++)
  {
	  cout << ArrayCustomers[i]<< endl;
  }
  cin >> TempInclination;  //  This is just as a pause, delete before submition
  return(0); 
}