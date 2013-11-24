// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Business Class Functions

#include "Business.h"
#include "Customer.h"
#include <iostream>
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
		   cout << items [i] << " ,";
	   };
	   cout <<endl;
	   cout<<"Cash in Register: $"<<total_cash<<endl;
	   cout<<"---------------------------------------------------------"<<endl;
   }
  void business::enter_customer(customer name_of_cust)
   {
	   
	   customers[num_customers]=name_of_cust; 
	   num_customers = (num_customers+1);
   }
  
  void business::make_a_sale()
  {
	  string item; //item name 
	  float customer_wallet; //customer wallet amount 
	  
	  int index = (rand()% num_items); // random item being sold
	  
	  item = items[index]; // set to that item 
	  for (int i=0; i< num_customers;i++) //selling item to every customer
	  {
		  
		  customer_wallet = customers[i].getmoney(); // get cust. balance 
		  if (customer_wallet >= SINGLE_PURCHASE_COST) 	  
		  {
			  customers[i].purchase(item);
			  customers[i].subtract_money(SINGLE_PURCHASE_COST);
			  total_cash = (total_cash + SINGLE_PURCHASE_COST);
		  }
  
	  }
	}
  void business::get_item(string item[],string stock[],short num_items)
  {
	  for (int i=0;i<num_items;i++)
			{item[i]= stock[i];}
	  return;
  }
   