// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Customer Class Functions

#include "Customer.h"
#include <iostream>
using namespace std;

  bool customer::purchase (string item)
    {
	  bool willPurchase = false;
		int index = get_purchases(); //current purchases total to start in the array 
		if (wallet>SINGLE_PURCHASE_COST)
	    {
	     purchases[index] = item ;  //add item to array 
	     total_purchases = (total_purchases +1); // update total purchases 
	     willPurchase = true; // pass the check 
	    }
	 return willPurchase; //return check 
    }

  void customer::print ()
    {
		int max_index = get_purchases();  
		cout << customer_name <<" has $ "<<wallet <<" and Purchased: ";
		if (get_purchases()!=0)
		{ 
			for (int i=0;i<=max_index;i++)
		  { cout << purchases[i] <<", ";}
		}else
		{
			cout << "nothing";
		}
		cout<<endl;
    }