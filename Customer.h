// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Customer Class


#ifndef	CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

    
    
   const int  SINGLE_PURCHASE_COST = 40; //fix amount for transaction cost
  
   class customer
  {

   public:
	 customer():wallet(0),customer_name()  //default constructor 
	 {
		 
		 wallet = (rand() % 250 + 4); //generates wallet amount between 4-250
		 total_purchases = 0; 
	 }
	 customer(string name,float money):total_purchases(0) //secondary construct
	 {
		 total_purchases = 0; 
		 customer_name = name;
		 wallet = money;
	 }
	 //Desc: display information on screen about customer 
	 //Pre: none
	 //Post: display information on screen 
	 void print();
	 // Desc: add item in to customer's purchased array 
	 // Pre:  none
	 // Post: return true if sucessful and add item or false if not  
	 bool purchase(string item);
	 //Desc: gets wallet balance from customer 
	 //Pre: none 
	 //Post: return float of blance in wallet 
	 float getmoney(){return wallet;}
	 //Desc: gets total number of purchases from customer
	 //Pre: none 
	 //Post: return number of purchases 
	 short int get_purchases(){return total_purchases;}
	 //Desc: changes the name of the customer 
	 //Pre:none
	 //Post:changes name of customer 
	 void change_name(string name){customer_name = name ;}
	 //Desc: detuct amount from wallet
	 //Pre:none 
	 //Post: detuct amount from wallet 
	 void subtract_money(float amount){wallet = (wallet - amount);}
	 //Desc: Gets the name of customer 
	 //Pre:none 
	 //returns a string with the name of customer 
	 string get_name(){return customer_name;}

   private:
	 string purchases [20];  // array for customer purchases 
	 short total_purchases;  // total number of purchases 
	 float wallet;           // balance 
	 string customer_name;   // name 

  };

#endif