// function file make sure to know the name 
// Joseph Michael Rice   // class cs1570 section c
// File for homework 7 // id 12541608 date started 10/12/2018
// Program a menu with 7 options input a 5 or less digit number
// enter the base of the number then converts to decimal
// this program also changes numbers randomly

#include "hw7.h"
#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;


//pre none 
//post none
// returns a message to the user to help them navigate
void greet_user()
{
  cout<<" Option 1: generate a new burger "<<endl;
  cout<<" Option 2: print list of burgers alphabetialy "<<endl;
  cout<<" Option 3: remove name from list "<<endl;
  cout<<" Option 4: Quit "<<endl;
  
  
}

ostream & operator << (ostream & os, const burger & B)
{
  os<<B.m_burger_name<<endl;
  os<<"Patties "<<B.m_patties<<" Bacon "<<B.m_bacons <<" Pickies "<<\
  B.m_pickles<<endl;
  return os;
}

//pre Takes pass by referance paramiters 
//post the pass my referace paramiters will have value ranges
// pattys [1,3] bacon & pickle [2,3]
// returns a number that is randomly generated 
int gen_number(int& patty,int& bacon,int& pickle)
{
  
  int number;
     // range [1,3]
  patty = 1 + rand()%3;
  // range [0,3]
  bacon = rand()%4;    // tens 
  // range [0,3]
  pickle = rand()%4;  //ones
  
  number = patty*pow(10,2) + bacon*pow(10,1)+pickle;
  
  return number;
  
 
}

//pre number must be no biger than 3 digits 
//post checks if the number is in the burger array[] 
// return a 1 or 0 
bool check_number(int number, burger array[],const int size_array)
{
  int end_value = 0; // will only change if number in array
  for (int i = 0;i < size_array;i++)
  {
    
    if (array[i].m_burger_code == number)
    {
      
      end_value++;
      
    }  

  }

  return end_value;
      
}  


void generate_name(int pattys, int bacon, int pickies,\
burger array[],int index)
{
  bool sum = pattys + bacon - 6;
  string Patty;
  string Bacon; 
  string Pickies;
  if (pattys == 1)
  {
    Patty = "Single";
  }
  if (pattys == 2)
  {
    Patty = "Double";
  }
  if (pattys == 3)
  {
    Patty = "Triumph"; 
  }
  if (bacon == 1)
  {
    Bacon = "Bacon";
  }
  if (bacon == 2)
  {
    Bacon = "Wilbur";
  } 
  if (bacon ==3)
  {
    Bacon = "Klogger"; 
  }
  if (bacon == 0)
  {
    Bacon = "Health Master"; 
  }
  if( pickies== 0)
  {
    Pickies = "Tasteless"; 
  }  
  if(pickies == 2)
  {
    Pickies = "Garden Fresh"; 
  }
  if(pickies == 1)
  {
    Pickies = "Pickly"; 
  }
  if (pickies == 3)
  {
    Pickies = "Kermit";  
  }
  if((pickies >= (pattys + bacon)))
  {
    
    array[index].m_burger_name = "Krusty Veggie Burger"; 
    
  }
  else if(((pickies ==0) || (pickies ==1)) && (!sum))
  {
    
    array[index].m_burger_name = "Krusty Koroary Burger";
    
  }
  else
  {
    
    array[index].m_burger_name = Patty+ " " +Bacon+ " " +Pickies + "  Burger";
   
   
  }
  
}


void short_list(burger array[], const int size)
{
  
    
  
  for (int i = size-1; i > 0; i--)
    for(int j =0; j < i; j++)
    {  
      if(array[j].m_burger_name > array[j+1].m_burger_name)
      {
        
        
        burger temp = array[j+1];
        array[j+1] = array[j];
        array[j] = temp;
      }
      
    }  
 
  
}

void print_array(burger array[],int size)
{
  for(int i =0;i <size;i++)
  {
    
    if(array[i].m_burger_code != 0)
    {
     
      cout<<array[i]<<endl;
    
    
    }
    else
    {  
  
  
      cout<<"No burger !"<<endl;
    
    }
    
  }
  return;
}



bool compare(burger array[],int number,int size,int& index)
{
  bool return_s;
  for(int i =0;i<size;i++)
  {
    
    if(array[i].m_burger_code == number)
    {
       
       return_s = 1;
       index = i;
       break;
       
    }
    else
    {
      
      return_s = 0;
      
    }
    
     
  }
  
  return return_s;
  
}


void switch_truth(bool& switch_1,bool& switch_2,bool& switch_3,\
int value,int value_2,int value_3)
{
   
   
  switch_1 = value;
  switch_2 = value_2;
  switch_3 = value_3;  
  
  
}

















