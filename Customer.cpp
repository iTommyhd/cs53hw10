// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Customer Class Functions

#include "Customer.h"
#include <iostream>
using namespace std;

bool customer::buy_something (Product items[])
    {
	 int purchase = (rand() % 2 + 1 ); // 50/50 chance for purchase   
	 bool willPurchase;  
	 int index = get_purchases(); //current purchases total to start in the array
	 int item_purchase = (rand() % 10 ); // randomly chooses item from 0 to 10 
	 int happiness; // happiness increase or decrease switch case 
	 Product temp_item;

	 happiness = 3;
	 willPurchase = false;
	 
	 switch (purchase) 
	 {
	 case 1: 
		 temp_item =  ( items[item_purchase] ); 
		 if (wallet>temp_item.m_price)
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
				 willPurchase = false; // purchase not successful due to you got "got too many items"
				 happiness = 2; //decrease happiness
				 break;
			 }
		 }
		 else 
		 {
			 willPurchase = false; // purchase not successful due to you "you broke"
			 happiness = 2; // decrease happiness  
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

  ostream & operator <<(ostream& out, customer c1)
  {
	Product temp_product;
	int max_index = c1.get_purchases();  
	out << c1.customer_name <<"  has $"<<c1.wallet <<" and Purchased: ";
	if (c1.get_purchases() !=0)
	{ 
	  for (int i=0;i<=max_index;i++)
	  {
	    temp_product = c1.purchases[i];
		out << temp_product.m_name << "," ;
	  }
	}else
	{
	  out << "nothing";
	}
	cout<<endl;
	return out;
  }

  void customer :: rob(customer& victum)
  {
	Product temp;
	if (total_purchases < MAX_NUMBER_PURCHASES && victum.total_purchases >0)
	{
	  victum.total_purchases--;
	  temp = victum.purchases[victum.total_purchases];
	  purchases[total_purchases]=temp;
	  total_purchases++;
	  happiness_level += ROB_SUCCESS_PERP;
	  victum.happiness_level+= ROB_SUCCESS_VICTUM;
	  if(rand()%11 ==1)
	  {
	    happiness_level=0;
		cout << customer_name <<" has been caught by the cops and sent to the "
		<< "Shelbyville prison!";
	  }
	}
	else
	{
	  happiness_level+=ROB_FAIL_PERP;
	}
    return;
  }
  void customer:: ThrowItem(customer& victum)
  {
	if (total_purchases > 0)
	{
	  total_purchases--;
	  happiness_level += THROW_SUCCESS_PERP;
	  victum.ChangeHappiness(THROW_VUCTUM);
	}
	else
	{
	  happiness_level+=THROW_FAIL_PERP;
	}
    return;
  }

  void customer :: ChangeHappiness(const int ChangeAmmount)
  {
    happiness_level+=ChangeAmmount;
    return;
  }