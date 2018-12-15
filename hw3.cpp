// Programer: Joseph Michael Rice   Date:9/8/2018
// File: hw3.cpp   // 12541608  section c
// This program is going to input a 3 digit number
// this program will find the type of burger
// and the price acociated with a 3 digt code  

#include <iostream>
#include <string>



using namespace std;
const double patty$ = 0.75; // patty cost 
const double bacon$ = 0.50; // bacon cost 
const double pickle$ = 0.25; // pickle cost 
const double bun$ = 0.50; // bun cost
long hundreds_place,tenths,ones_place; // number of each item                                                       
// hundreds_place = #patties
// tenths = #bacon
// ones_place = #pickles 

bool sum_value_6 = hundreds_place + tenths - 6;// checking if patties + bacon=6


int main()
{
  int entry; // The 3 digit code 
  bool run = 1; // runs the loop
  string patties,bacon,pickles; // strings that will print message at the end
  cout << " Hello Krusty! " << endl;
  
  
  while(run) 
  {
   double price = 0;

   cout<< " Enter the 3 digit code; "<<endl;
 
   cin >> entry; /// generate a rand number
   if (entry == 0)
     break;  // if entry all zeros kill loop

   if (entry > 999)
   {
    cout << "Not a 3 digit code! " << endl;
    continue; // repromptes the if the number over 3 digets long  
   }

   else if (entry >= 0)
   {
    hundreds_place = ((entry-entry%100)/100); //calcutaion for number of patties
    if(hundreds_place >0)
    {
 
      if (hundreds_place== 1)
      {
        patties = "Single";
        price += patty$; 
      }
      else if(hundreds_place ==0)
      {
        cout << " YOU NEED PATTIES !!! "<<endl;
        continue;
      }
      else if(hundreds_place == 2)
      {
        patties = "Double";
	price += 2*patty$;
      }
      else if (hundreds_place == 3)
      {
        patties = "Triumph";
	price += 3*patty$;
      }
      else 
      {
        cout << "ERROR No more than 4 patties !"<< endl;
        continue; // starts loop at begining 

      }

    }
 
    tenths =  ((entry%100-entry%10)/10); // calclculation for  bacon 
    if ((tenths >= 0))
    {

     if (tenths == 1)
     {
       bacon = "Bacon";
       price += bacon$;
     }
     else if (tenths == 2)
     {
       bacon = "Wilbur";
       price += bacon$*2;
     }
     else if (tenths ==3)
     { 
       bacon = "Klogger";
       price += bacon$*3;
     }
     else if (tenths == 0)
     {
       bacon = "Health-Master";       
       price += bacon$*0;
   
     }
     else
     {
      cout << "ERROR No more that 4 bacons ! "<<endl;
      continue; /// brings back to loop
     }
     
    }
    
    ones_place = (entry%10); // number of pickies
    if ((ones_place >= 0))
    {
     if (ones_place == 0)
     {
       pickles = "Tasteless";
       price += pickle$*0;
     }
     else if (ones_place == 1)
     {
      pickles = "Pickly";
      price += pickle$*1;    
     }
      
     else if (ones_place ==2)
     {
      pickles = "Garden Fresh";
      price += pickle$*2;
     }
     else if (ones_place == 3)
     {
      pickles = "Kermit";
      price += pickle$*3;

     }
     else
     {
      cout << " ERROR No more than 4 Pickles ! "<<endl;
      continue;
     }
    
     
    }

    
    if ((ones_place >= (hundreds_place + tenths))) // checks if veggie burger
    {
      if (hundreds_place == 0)
      {
        cout << " You need patties "<<endl;
        continue; 

      } 
      cout << "Krusty Veggie Burger! " <<endl;
      cout << "Price = "<<"$ " <<price+bun$ <<endl;   
      continue;

    }
    if(((ones_place = 0) || (ones_place = 1)) && (!sum_value_6))
     // checks if Koronary burger
    {

     cout << "Krusty Koronary Burger "<< endl; 
     cout << "Price = "<< "$ " <<price+bun$ <<endl;   
     continue;
     
    }    
    if(run) 
    {
     // general price and burger
      if (hundreds_place == 0)
      {  
        cout << " You need patties "<<endl;
        continue;
      }       

      cout << "Krusty" << " " <<patties<<" "<<bacon<<" "\
      <<pickles <<" "<<"Burger "<<endl;

      cout << "Price = "<< "$ "<<price+bun$ <<endl; 
    }
    
  
   }


 }  

}



 
