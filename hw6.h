// Joseph Michael Rice   // class cs1570 section c
// File hw6.H  // id 12541608 
// Program a menu with 5 options input a 5 or less digit number
// enter the base of the number then converts to decimal

#ifndef HW6_H
#define HW6_H


// this function fills the array 
// Pre: all paramiters must be of type int 
// returns the size of the array and also filling the array with intigers
int fill_array(int array[],int size_array, int x); 


// This function checks if the base of the entry  
// pre: all paramiters must be intigers
// Returns a 0 or 1 to determine right base
bool check_n(int array[],int size_array,int n);

// displays menu options
//preconditions TAKES zero paramsiters
//returns the menu options  for user
void menu_options();


// this function turns the values of and off depening on the option 
// switch values must be bool values 
// values must be intigers
// returns the new values of the bool values
void switch_truth(bool & switch_1, bool & switch_2,\
      bool & switch_3, bool & switch_4,\
      bool & switch_5,bool & switch_6,\
      int value_1, int value_2, int value_3,\
      int value_4,int value_5, int value_6);


      
// forces validation of the base
// one pas by referance par and the rest intigers
// returns the the new value if n
void force_val(int array[],int size_array, int& n);



// This function takes in the current value of n
// the preconditions of this function are that all the paramiters are int's
// minipulates the bits in the array that violate the current base 
// this function basicaly changes  bits with random intigers 
// This also changes the number x 
void force_new_random(int array[],int n,int array_size,int & x);




#endif 



