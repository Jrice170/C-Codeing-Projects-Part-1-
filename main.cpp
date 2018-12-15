// Joseph Michael Rice   // class cs1570 section c
// File main.cpp  // id 12541608 
// Program a menu with 7 options input a 5 or less digit number
// enter the base of the number then converts to decimal
// this program also changes numbers randomly

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include "hw6.h"

using namespace std;


int main()
{
  const int maxval = 5;  // maximum value that the array can hold
  int array[maxval]; // array that will hold bits 
  int x; // the 5 or less digit number
  int n; // the base that the number will be set to 
  char end_loop; // entered by the user to end program
  int option; // enter 1,2,3,4,5 for the user to select
  //bool fast_end; // kills loop if option = 5;
  bool switch_change[] = {1,1,0,0,0,0,1}; //activates and deactivates options 
  srand(7); //seed
  
  do
  {
    menu_options();
    cin>>option;
    
    if (switch_change[option-1])
    {
      switch(option)
      {    
          case 1:
          {
            
           int count_bad = 0;
           while(count_bad < 3)
           {
             cout<<"Enter a none negative number less than 5 digets"<<endl;
             cin >>x;
             if((x > 99999) || (x < 0))
             {
               cout << "Error less than or equal to 5 digets "<<endl;
               count_bad++;

             }           
             else
             {
               
               break;
               
             }

           }             
            
         
           
           if(!(switch_change[1]))
           {
             
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],\
                          switch_change[4],switch_change[5],\
                          0,0,1,1,1,1);
         
             
           }
           else
           {
             
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],
                          switch_change[4],switch_change[5],
                          0,1,0,0,0,0);
         
             
           }         
         
           break;
           
          }
          case 2:
          {
           
            int count_bad = 0;
            while(count_bad < 3)
            {
              cout<< "Enter the number system of your intiger"<<endl;
              cin >>n; 
              if ((n>=2) && (n < 10))
              {  
            
                count_bad = 3;
                cout<< " The Base you entered was good "<<endl;
                
              }               
              
              else
              {
                
                 cout <<"Base not valid "<<endl;    
                 count_bad++;
               
              }  

              
            }
           
           //cout << "Case 2"<<endl;
           
           
           
           if (!(switch_change[0]))
           {
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],
                          switch_change[4],switch_change[5],
                          0,0,1,1,1,1);
                          

            
           }
           else
             
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],
                          switch_change[4],switch_change[5],
                          1,0,0,0,0,0);
                          
           break;
          }          
          case 3:
          {

            int count = fill_array(array,maxval,x);
            //cout << n <<endl;
            bool Right_base = check_n(array,count,n);
            if (Right_base)
            {
              cout<<" The base of the number is good "<<endl;
              switch_truth(switch_change[0],switch_change[1],\
                           switch_change[2],switch_change[3],\
                           switch_change[4],switch_change[5],\
                           0,0,0,0,0,1); 
             
            }  
            else
            {
              
              cout<<" invalid base! "<<endl;
              cout<<"Go back and reenter or go to option 5 or 4! "<<endl; 
              switch_truth(switch_change[0],switch_change[1],\
                           switch_change[2],switch_change[3],\
                           switch_change[4],switch_change[5],\
                           1,1,0,1,1,0);
             
            }
           
           
           break;
          }
          case 4:
          {
           int var = check_n(array,fill_array(array,maxval,x),n);
           if (!var)
           {
             
             force_val(array,fill_array(array,maxval,x),n);
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],\
                          switch_change[4],switch_change[5],\
                          1,1,0,0,1,1);  
                          
               
           }
           
           else
           {
             
             cout<<" The base is valid no need for option 4"<<endl;
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],\
                          switch_change[4],switch_change[5],\
                          1,1,1,0,1,1);
             
             
           }  
           
           break;
          }
          case 5:
          {
            
           int var = check_n(array,fill_array(array,maxval,x),n); 
           if(!var)
           {
             
             
             force_new_random(array,n,fill_array(array,maxval,x),x);
             
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],\
                          switch_change[4],switch_change[5],\
                          1,1,0,1,0,1);
             
             cout << "You have random numbers now "<<endl;
             
           }
           else 
           {
             
             
             cout<<" The base is vaild option so option 5 can not run. "<<endl;
             cout<<"please try something else. "<<endl;
             switch_truth(switch_change[0],switch_change[1],\
                          switch_change[2],switch_change[3],\
                          switch_change[4],switch_change[5],\
                          1,1,0,0,0,1);
             
             
             
           }           
           
           break;
          }
          case 6:
          {
            
            
            
            if(check_n(array,fill_array(array,maxval,x),n))
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
              switch_truth(switch_change[0],switch_change[1],\
                           switch_change[2],switch_change[3],\
                           switch_change[4],switch_change[5],\
                           1,1,0,1,1,0);
              
              
            }
            else
            {
              
              cout<< "must have a valid pair to compute the conversion!"<<endl;         
              switch_truth(switch_change[0],switch_change[1],\
                           switch_change[2],switch_change[3],\
                           switch_change[4],switch_change[5],\
                           1,1,0,1,1,0);
              
              
            }
            break; 
           
           
          }            
          case 7:
          {
          
           
           cout << "Have a good day! "<<endl;
           
           break;
          }
          
                   
      }   
    }
    else
    {
      
      cout <<"You are out of squence try another option. "<<endl;
      
      end_loop = 'N';
  
    }  
    
    if(option == 7)
    {
      
      end_loop = 'y';
     
    }  
  
 }while(!(end_loop == 'y'));

  
}

  