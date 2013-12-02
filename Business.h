// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Business Class

#ifndef	BUSINESS_H
#define BUSINESS_H
#include "Customer.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

const int NUMBER_ITEMS_IN_STORE = 10;
const int NUMBER_CUSTOMERS_IN_STORE=10;




class business
{
  private:
    string business_name ; // name of business 
    float total_cash; //amount of cash in register 
    short int num_items;
    short int num_customers;
	Product items[NUMBER_ITEMS_IN_STORE]; // array containing items in business
	customer customers[NUMBER_CUSTOMERS_IN_STORE]; // customers in bussiness

  public:
    business():business_name(),total_cash(0),num_items(0),num_customers(0) 
	{
	  num_items = 0;
	  num_customers = 0;
	  total_cash = 0;
	}
	business (string name,float money_in_reg)
	{
	  business_name = name;
	  total_cash = money_in_reg;
	  num_customers = 0;
	  num_items = 7;
	  
	}
		
	void print();
	int get_numcust(){return num_customers;};
	void addCustomer(customer name_of_cust);
	void make_a_sale();
	customer leave_store(int index){return customers[index];}
	void get_items(string FileName);
	void customers_leave(customer StreetCustomers[], int & NumberCustomers);

  };

 
#endif
