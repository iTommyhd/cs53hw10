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

  struct Product
  {
	  string m_name;
	  float m_price;
  };
  class customer
  {
   public:
   
	 customer():wallet(0),customer_name(),happiness_level(0)  //default constructor 
   {
	 wallet = (rand() % 250 + 4); //generates wallet amount between 4-250
	 total_purchases = 0;
	 happiness_level = (rand() % 100 );
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
   bool buy_something(Product items[] );
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
   //Desc: Set inclination 
   //Pre:none 
   //Post: Return nothing  
   void SetInclination(string location){inclination = location;}
   //Desc: gets the customer inclination
   //Pre:none 
   //returns: inclination (a string) 
   string GetInclination() {return inclination;}
   //Desc: Gets the customers happiness
   //Pre:none
   //Post:returns an int happiness
   int GetHappiness() {return happiness_level;}
   //Desc:Prints a customer
   //Pre :NONE
   //POST: Returns an ostream
   friend ostream & operator <<(ostream& out, customer c1);

   private:
	 Product purchases [20]; // array for customer purchases 
	 short total_purchases;  // total number of purchases 
	 float wallet;           // balance 
	 string customer_name;   // name 
	 int happiness_level;    // level of happiness
	 string inclination;     // location 
   };
#endif