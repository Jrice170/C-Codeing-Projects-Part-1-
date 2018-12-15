// Programer: Joseph Rice  
// 9/6/2018
// File name project_2.cpp
// Section CS1570  1C 
// // Instructor: San Young  
// calculate the risk of a heart attack at the Krusty Korperation


#include <iostream>
#include <string>
using namespace std;

const double AQF = 5.6; // Air quality factor
const double KBMF = 19.7; // Krusty Burger Mitigation Factor 

//_______ FUNCTION DECLORATION_______

int convert_miles(double miles);
// This function converts the miles to marathons
// And then outputs the remander in miles as a float


double heart_attack_risk(double burgers=0,double fries=0,\
double milkshakes= 0,double num_in_line=0,double Air_const=0);  
//  returns the Risk factor for a heart attack useing the following inputs 
//  using the items inputed into the program 
//


int main()
{
 /* ______________ Declorations____________________*/

 // tells the consumer to place the order for that item
  string o_statement = " Enter the number of "; // genaeral orderstatement //  
  string order_end = " That you would like to order: "; // orderstatement
 

  short burgers,fries, milkshakes, people_in_line;  // possible food items
// burgers, fries, milkshakes, people in line that are in front of the costomer.

  double risk_factor; // stores the value of heart attack risk

 /*___ Inputs___ and___ greetings */

  cout << "Welcome to krusty Burger !" << endl;

  cout << o_statement <<" " << "Burgers" <<" " <<order_end << endl;
  cin >> burgers;
  cout << o_statement << " "<< "Fries" <<" " << order_end <<endl;
  cin >>fries;
  cout << o_statement << " "<< " Milkshakes " <<"" << order_end <<endl;
  cin >> milkshakes;
  cout << o_statement << " "<< "people in line" <<endl;
  cin >> people_in_line;
 


 /*__ computaion__ and___ output */ 
  
 // If one of the food items is zero Air quilty factor will defualt to zero

  risk_factor = heart_attack_risk(burgers,fries,milkshakes,people_in_line,AQF); 
      
  cout << burgers << " "<<"Burgers"<<endl;
  cout << fries << " " << "fries" <<endl;
  cout << milkshakes << " " << "milkshakes" <<endl;
  cout << people_in_line << " "<<"People in line"<<endl; 

  cout << "Heart attack risk factor is " <<" " << risk_factor\
  << " % "<<endl;
 
  double miles = risk_factor* KBMF;  // miles to lower their risk factor
 
  cout << convert_miles(miles)<< endl;  // function convert_miles
 
 

}
/// ___ function ___
double heart_attack_risk(double burgers,double fries,double milkshakes,\
double num_in_line,double Air_const){
///^^^ ___ function __^^^ 

  double risk; // stores the risk factor
  bool Zero_or_not;
  Zero_or_not = (burgers)&&(fries)&&(milkshakes); // 0 or 1
 /// risk factor equation
  risk = (burgers + fries)*(((milkshakes))/((num_in_line+1)))\
  +(Air_const)*(Zero_or_not);
  
  return risk;

}

int convert_miles(double miles)
{ 
  int marathon = static_cast<int>(miles)/(26); // converts miles to marathons 

  cout << " You need to run " <<" "<< marathon << " " << "marathons"<<endl;
 /// remainder in miles 
  cout << " And " << ((miles/26.0)-(marathon))*(26.0)  <<" "<<"miles" <<endl; 
  cout << " To save your life !!!  " <<endl;
  return 0;

}





























