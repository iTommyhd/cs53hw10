// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Business Class Functions

#include "Business.h"
#include "Customer.h"

#include <iostream>
#include <fstream>
using namespace std;

  void business::print()
   {
	   cout <<"--------------------------------------------------------"<<endl;
	   cout<<"Business Name: " <<business_name<<endl;
	   cout<<"Current Customers: ";
	   if (num_customers!=0)
	   {
		   for (int i =0 ;i <= num_customers;i++)
		   {
			   cout <<customers[i].get_name()<<", ";
		   }
	   }else 
	   {
		   cout<< "no current customers";
	   }
	   cout <<endl;
	   cout<<"Current items instock: ";
	   
	   for (int i =0 ;i<num_items;i++)
	   {
		   cout << items [i].m_name << " ,";
	   };
	   cout <<endl;
	   cout<<"Cash in Register: $"<<total_cash<<endl;
	   cout<<"---------------------------------------------------------"<<endl;
   }
  void business::addCustomer(customer name_of_cust)
   {
	   
	   customers[num_customers]=name_of_cust; 
	   num_customers += 1;
   }
  
  void business::make_a_sale()
  {
    for (int i=0; i< num_customers;i++) //selling item to every customer
	{
      customers[i].buy_something(items);
	}
  }
  void business::get_items(string FileName)
  {
	ifstream fin;
	fin.open(FileName.c_str());
    for (int i=0;i<num_items;i++)
	{
	  fin >> items[i].m_price;
	  getline(fin,items[i].m_name);
	}
    return;
  }
   
  void business :: customers_leave(customer StreetCustomers[], int & NumberCustomers)
  {
	customer temp1, temp2;
	int n = 0;
	int RandomSite;
    for (int i = NumberCustomers-1; i < NumberCustomers + num_customers; i++)
	{
	  StreetCustomers[i]= customers[n];
	  n++;
	}
	NumberCustomers += num_customers;
	for (int i = 0; i < NumberCustomers; i++)
	{
	  temp1 = StreetCustomers[i];
	  RandomSite= rand()%(NumberCustomers);
	  temp2 = StreetCustomers[RandomSite];
	  StreetCustomers[i]= temp2;
	  StreetCustomers[RandomSite]=temp1;
	}
	num_customers = 0;
  }