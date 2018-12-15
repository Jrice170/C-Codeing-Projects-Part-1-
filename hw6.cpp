// Joseph Michael Rice   // class cs1570 section c
// File hw6.cpp  // id 12541608 
// Program a menu with 5 options input a 5 or less digit number
// enter the base of the number then converts to decimal

#include "hw6.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int fill_array(int array[],int size_array,int x)
{
    
    int compund = 10;    
    int count = 0;  
    double num;  
    // this loops tells the other loop what size the number is 
    do 
    {
      
      num = static_cast<double>(x)/compund;
      compund *= 10;
      
      count++;
      
    }while(num > 1.0);
    int i = compund/100; // used as a divider 
    size_array = count; // size of array
    //array[size_array];
    int index  = size_array; // start index for the far side of array 
    // this loop will the move its way down filling from right to left
    while(i>=1)
    {
      int modulus = x%i;
      int move_number = (x-modulus)/i; 
      array[index-1] = move_number;
      index--;
      if (index < 0)
      {
          cout << "You cant enter more than 5 bits "<<endl;
          break;
        
      }
      x = x - (move_number*i);
      i /= 10;
      
    }
    return count;
    
} 


bool check_n(int array[],int size_array,int n)
{
    int max = 0;
    for (int i = size_array-1;i > 0; i--)
    {
        
        if(array[i] > array[i-1])  // nested loop finds the max number
        { 
          if (max < array[i])
          { 
        
            max = array[i];// stores max int
          
          }
          
        }
        
        
    }
    
    
    //cout << "Max "<<max<<endl;
    if (max < n)  // comparies this to base
    {
        return 1;
    }
    
    else
    {
        
        return 0;
    }
    
}

void menu_options()
{
    
    cout << "_____Options_____"<<endl;
    cout << "1. Enter a none-negative integer"<<endl;
    cout << "2. Enter an integer base n 2 <= n <10 "<<endl;
    cout << "3 Verify x is a valid base n number "<<endl;
    cout << "4 force validation with new (smallest) base assignment"<<endl;
    cout << "5 Force validation with new (random digits in) x "<<endl;
    cout << "6 convert to decimal base ten"<<endl;
    cout << "7 Quit "<<endl;
 
}


void switch_truth(bool & switch_1, bool & switch_2,\
      bool & switch_3, bool & switch_4,\
      bool & switch_5,bool & switch_6,\
      int value_1, int value_2, int value_3,\
      int value_4,int value_5, int value_6){
        
        
  switch_1 = value_1;
  switch_2 = value_2;
  switch_3 = value_3;
  switch_4 = value_4;
  switch_5 = value_5;
  switch_6 = value_6;  
        
}

void force_val(int array[], int size_array,int& n)
{
  int max = 0; 
  for (int i = size_array-1;i>0;i--)
  {
    
    if(array[i] > array[i-1])
    {
      
       if (max < array[i])
       { 
        
         max = array[i];
          
       }
     
    }
    
     
  }
  
  n = max + 1; // new value of n based of the max intiger
  
  
  
}

void force_new_random(int array[],int n, int array_size,int & x)
{
  int count = array_size-1;
  
  //cout <<"The first x" <<x <<endl;
  
  x = 0; // reset x so that values can be changed
  
  for(int i = array_size-1; i>=0; i--)
  {
    
    //cout<<"array elements"<<array[i]<<endl;
    if (array[i] >= n)
    {
       
       array[i] = rand()%n; // changes the value of bit
       
  
    }
    
    
    x = x + array[i]*pow(10,count); // new x value calcutated  
    
     
    count--;
    
  }
  
    cout <<"The new number is: "<<x<<endl; // shows user the new number
  
}





















