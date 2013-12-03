// Name: Tommy Duong, Josey Stevens, Katherine Overend
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

const int THROW_SUCCESS_PERP = 5;
const int THROW_FAIL_PERP = -25;
const int THROW_VUCTUM = -20;
const int ROB_SUCCESS_PERP=25;
const int ROB_FAIL_PERP=-5;
const int ROB_SUCCESS_VICTUM=-20;
const int MAX_NUMBER_PURCHASES = 20;
  
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
  
    // Desc: Display information on screen about customer 
    // Pre:  None
    // Post: Display information on screen 
    void print();
   
    // Desc: Add item in to customer's purchased array 
    // Pre:  None
    // Post: Return true if sucessful and add item or false if not  
    bool buy_something(Product items[] );
   
    // Desc: Gets wallet balance from customer 
    // Pre:  None 
    // Post: Return float of blance in wallet 
    float getmoney(){return wallet;}
   
    // Desc: Gets total number of purchases from customer
    // Pre:  None 
    // Post: Return number of purchases 
    short int get_purchases(){return total_purchases;}

    // Desc: Changes the name of the customer 
    // Pre:  None
    // Post: Changes name of customer 
    void change_name(string name){customer_name = name ;}
   
    // Desc: Detuct amount from wallet
    // Pre:  None 
    // Post: Detuct amount from wallet 
    void subtract_money(float amount){wallet = (wallet - amount);}
  
    // Desc: Gets the name of customer 
    // Pre:  None 
    // Post: Returns a string with the name of customer 
    string get_name(){return customer_name;}
  
    // Desc: Set inclination 
    // Pre:  None 
    // Post: Return nothing  
    void SetInclination(string location){inclination = location;}
   
    // Desc: Gets the customer inclination
    // Pre:  None 
    // Post: Returns inclination (a string) 
    string GetInclination() {return inclination;}
   
    // Desc: Gets the customers happiness
    // Pre:  None
    // Post: Returns an int happiness
    int GetHappiness() {return happiness_level;}
   
    // Desc: Prints a customer
    // Pre:  None
    // Post: Returns an ostream
    friend ostream & operator <<(ostream& out, customer c1);
   
    // Desc: The calling customer robs anoother customer
    // Pre:  NONE
    // Post: Possibly modifies the purchases and happiness
	//       of both customers
    void rob(customer& victum);
 
    // Desc: The calling customer throws an item at another
    // Pre:  NONE
    // Post: Modifies the happiness of both customers and 
	//       the purchases of the calling customer
    void ThrowItem(customer& victum);
 
    // Desc: Mutator for the Happiness
    // Pre:  NONE
    // Post: Modifies the value of happiness
    void ChangeHappiness(const int ChangeAmmount);

  private:
    Product purchases [MAX_NUMBER_PURCHASES]; // array for customer purchases 
    short total_purchases;  // total number of purchases 
    float wallet;           // balance 
    string customer_name;   // name 
    int happiness_level;    // level of happiness
    string inclination;     // store preference 
};

#endif