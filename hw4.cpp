// Joseph Michael Rice   // class cs1570 section c
// File hw4.cpp  // id 12541608 
// Program a menu with 5 options input a 5 or less digit number
// enter the base of the number then converts to decimal


#include <iostream>
#include <cmath>
using namespace std;

int fill_array(int array[],int size_array, int x); 
// this function fills the array 
// each index will have a bit (number)

bool check_n(int array[],int size_array,int n);
// This function checks if the base of the 
// number is correct // 1 true and 2 false



int main()
{
  const int maxval = 5;  // maximum value that the array can hold
  int array[maxval]; // array that will hold bits 
  int x; // the 5 or less digit number
  int n; // the base that the number will be set to 
  char end_loop; // entered by the user to end program
  int option; // enter 1,2,3,4,5 for the user to select
  int start = 1; // keeps track of the option sequence 
  bool fast_end; // kills loop if option = 5;
  cout <<"Hello Welcome ready to learn math !"<<endl;
  do
  {
      
    cout << "_____Options_____"<<endl;
    cout << "1. Enter a none-negative integer"<<endl;
    cout << "2. Enter an integer base n 2 <= n <10 "<<endl;
    cout << "3 Verify x is a valid base n number "<<endl;
    cout << "4 convert to decimal base ten"<<endl;
    cout << "5 Quit "<<endl;
    cin >> option;
      if (start == option)  // checks to make sure user is in sequence
      {
          switch(option)
          {
              
              case 1:   // case 1 makes sure that the entry is valid 
              { 
                int count_bad = 0;
                while(count_bad < 3)  // user gets 3 trys 
                {
                  cout<<"Enter a none negative number less than 5 digets"<<endl;
                  cin >> x;
                  if ((x > 99999) || (x < 0))
                  {
                    cout << "Error less than or equal to 5 digits"<<endl;
                    count_bad++;
                      //continue; // bring back to while (just to be safe)
                  }
                  
                  else
                  {
                    start++;
                    break;
                      
                  }
                
                }
                fast_end = 0; 
                break;
              }      
              case 2:
              { 
                int count_bad = 0;
                while(count_bad < 3)
                {
                  cout << "Enter the number system of your intiger"<<endl;
                  cin >> n;
                    if ((n >=2) && (n < 10))
                    {
                        start++;
                        count_bad = 3;
                        
                        
                    }
                    else
                    {
                        cout <<"Base is not valid "<<endl;
                        count_bad++;
                        
                    }
                    
                }
                
               } 
                fast_end = 0;               
                break;
                
              case 3:
              {
                int count = fill_array(array,maxval,x);
                cout << n << endl;
                bool Right_base = check_n(array,count,n);
                //cout << Right_base <<endl;
                if (Right_base)
                {
                  start++;
                  cout << " The base number is good"<<endl;
                    
                }
                else
                {
                  cout << "Go back to option 2"<<endl;
                  start--;
                }
                fast_end =0;
                break;
                
                
              } 
              case 4:
              { 
                  
                int size = fill_array(array,maxval,x);
                cout << "__The conversion to decimal is__"<<endl;
                int sum = 0;
                // calculates the converstion in series format 
                while(size > 0)
                {
                  sum += array[size-1]*pow(n,size-1);
                  
                  size--;
        
        
                }
    
                cout << sum << endl;
                start++;
                fast_end = 0;
                break;
                
              }
              case 5:
              {
                  
                fast_end = 1;
                break;
                  
              }
              
          }
          
      }
      else
      { 
        if (option != 5)
        {
          
          cout << "Error must be in sequence"<<endl;
          
          start--;
          if (start == 0) // start can not equal 0
          {
            start = 1;
          }            
        } 
      }
      cout << fast_end;
      if (fast_end || option == 5)
      {    
        end_loop = 'y';
          
      }
      
      //else
      //{
        //cout<<"Would you like to exit (y/n) "<<endl;
        //cin >>end_loop;
      //}
      
  }while(!(end_loop == 'y') && !(end_loop == 'Y'));
  
    
}


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
        
        if(array[i] > array[i-1])  // nested loop finds the max intiger
        { 
        
          if (max < array[i])
          { 
        
            max = array[i];
          
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
