// function file make sure to know the name 
// Joseph Michael Rice   // class cs1570 section c
// File hw7.cpp  // id 12541608 date started 10/12/2018
// Program a menu with 7 options input a 5 or less digit number
// enter the base of the number then converts to decimal
// this program also changes numbers randomly

#ifndef hw_7
#define hw_7
#include<iostream>
#include<string>
#include<cstring>
using namespace std;



struct burger
{
  
  // need more
  string m_burger_name;
  int m_patties;
  int m_bacons;
  int m_pickles;
  int m_burger_code; // use function to fill
  // my need more
  
};

//pre none 
//post none
// returns a message to the user to help them navigate
void greet_user();

//pre Takes pass by referance paramiters 
//post the pass my referace paramiters will have value ranges
// pattys [1,3] bacon & pickle [2,3]
// returns a number that is randomly generated 
int gen_number(int& patty,int& bacon,int& pickle);

//pre number must be no biger than 3 digits 
//post checks if the number is in the burger array[] 
// return a 1 or 0 
bool check_number(int number, burger array[],const int size_array);

// pre must have the specified paramiters
// post minipulated the paramiters
// return a string value that is stored in the burger array 
// with the miniputaled index parmiter
void generate_name(int pattys, int bacon, int pickies,\
burger array[],int index);

//pre must be an array and must have string atribute to to the array 
// post stores burger array with the name at sertant index paramiter
// returns a list sorted from A-Z; 
void short_list(burger array[], const int size);

//pre array must be full and size must be valid
// post prints out everything in the array
//returns nothing
void print_array(burger array[],int size);

// pre must have a declared pass by refernce
// post must be used in a desition tree 
// return turns 1 or 0
bool compare(burger array[],int number,int size,int& index);

// pre  will check if in ourder
// post will switch the values
// return nothing
void switch_truth(bool& switch_1,bool& switch_2,bool& switch_3,\
int value,int value_2,int value_3);

#endif









