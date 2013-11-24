// Name: Tommy Duong
// Date: Nov. 10 2013
// Class: CS53
// Section: C
// Description: Driver for HW9 

#include "Business.h"
#include "Customer.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

  int main ()
   {
	   srand(time(NULL));  
	   business gamestore = (business ("gameshed",100));  //Setup Business 
	   gamestore.print(); // print current business info
	   customer bob = (customer("bob",250)); // Customer #1 named bob
	   customer cindy = customer(); // Customer #2 w/ no name
	   cindy.print();               //print customer # 2 info
	   cindy.change_name("cindy"); //set name to Customer #2 
	   cindy.print();             // print customer # 2 info
	   bob.print();               // print customer #1 info
	   gamestore.enter_customer(bob);  //Customer #1 enter business 
	   gamestore.enter_customer(cindy); //customer #2 enter business 
	   gamestore.make_a_sale(); // sale made 
	   gamestore.make_a_sale(); //sale made
	   gamestore.make_a_sale(); //sale made
	   cindy = gamestore.leave_store(1); //customer #2 leaves store
	   bob = gamestore.leave_store(0);  //customer #1 leaves store 
	   cindy.print(); // print current customer #2 info 
	   bob.print(); // print current customer #1 info
	   gamestore.print(); // print current business info
	  return 0;
   }