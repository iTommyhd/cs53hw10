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

  class business
  {
    private:
	    string business_name ; // name of business 
	    float total_cash; //amount of cash in register 
	    short int num_items;
		short int num_customers;
		string items[10]; // array containing items the business offers 
		customer customers[10]; // customers in bussiness currently

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
			string stock [7] = { "item 1","item2","item3","item4","item5",
		                   "item6","item7"};
	        get_item(items,stock,num_items);	
		}
		
		void print();

		int get_numcust(){return num_customers;};
	    void enter_customer(customer name_of_cust);
		void make_a_sale();
		customer leave_store(int index){return customers[index];}
		void get_item(string item[],string stock[],short num_items);
		

  };

 
#endif