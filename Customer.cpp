// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Customer Class Functions

#include "Customer.h"
#include <iostream>
using namespace std;

bool customer::buy_something (product items[])
    {
	 int purchase = (rand() % 2 + 1 ); // 50/50 chance for purchase   
	 bool willPurchase;  
	 int index = get_purchases(); //current purchases total to start in the array
	 int item_purchase = (rand() % 10 ); // randomly chooses item from 0 to 10 
	 int happiness; // happiness increase or decrease switch case 
	 product temp_item;
	 
	 switch (purchase) 
	 {
	 case 1: 
		 temp_item =  ( items[item_purchase] ); 
		 if (wallet>temp_item.price)
		 {
			 if (total_purchases<20)
			 {
			 purchases[index] = temp_item ;  //add item to array 
			 total_purchases = (total_purchases +1); // update total purchases 
			 willPurchase = true; // purchase successful 
			 happiness = 1; // increase happiness 
			 break;
			 }
			 else
			 {
				 willPurchase = false; // purchase not successful
				 happiness = 2; //decrease happiness
				 break;
			 }
		 }else 
		 {
			 willPurchase = false; // purchase not successful
			 happiness = 2; // decrease happiness  //TOMMY,CHECK THIS, it doesn't make much sense to me, not sure if it's correct or not! I just don't understand same thing is done above!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			 break;
		 }
	 }
	 switch (happiness) // determine happiness 
	 {
		 case 1:
			 happiness_level = (happiness_level + 15);
			 break;
		 case 2:
			 happiness_level = (happiness_level - 10);
			 break;
	 }
	 return willPurchase; //return check 
    }

  void customer::print ()
    {
		product temp_product;
		int max_index = get_purchases();  
		cout << customer_name <<" has $ "<<wallet <<" and Purchased: ";
		if (get_purchases()!=0)
		{ 
		for (int i=0;i<=max_index;i++)
		  {
		   temp_product = purchases[i];
		   temp_product.print();
		  }
		}else
		{
			cout << "nothing";
		}
		cout<<endl;
    }