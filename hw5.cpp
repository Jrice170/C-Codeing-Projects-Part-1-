// Joseph Michael Rice   // class cs1570 section c
// File hw5.cpp  // Id 12541608 
// This program uses multiple functions
// the functions are used to calculate the inputs 
// The first set and second set of inputs are entered in order.

#include<iostream>
using namespace std;
#include<cmath>

// takes number of different animal parts 
// takes the number of different animal types 
// computes the mathmatical operation returns an double
// x lower bound and y upper bound 
// x range :{ lower_bound to upper_bound}
// y range :{ lower_boumd to upper_bound}
double profit_maximizer(const int x,const int y);

// generates a range from the two inputs 
// must be intiger values 
// returns the range of values for (x or y)
int generate_range(const int y_L,const int y_U);

// This function processis the input data so that is can be minipulated
// negative numbers can not be used
// returns a filled array 
void process_data(const int lower_bound,const int upper_bound,\
const int lower_bound_y,\
const int upper_bound_y,double array[][10]);


// outputs the entered data in a range x by range y matrix 
// the output will resize to different numbers that are put in.
// returns the values of the minputaed data 
void out_put_data(int size,int size_x,double array[][10]);

// function greets the user
void greet_user();

// gets the keybord input of the user 
// returns the values to other functions 
void get_key(int& x, int& x_2, int& y, int& y_2);


int main()
{
  greet_user();
  char stop;  // stops the loop
  int range_x,range_y;  // range of each in put 
  do
  {
    int x, y, x_2, y_2;   
    
    get_key(x,x_2,y,y_2); 
    
    range_x = generate_range(x,x_2); // range of x
    range_y = generate_range(y,y_2); // range of y
    double array[10][10]; // set size of the array
    
    process_data(x,x_2,y,y_2,array); // takes array fills it up 
    out_put_data(range_x,range_y,array); // outputs array based off dementions
    
    
    cout << "Would you like to keep going (y/n)"<<endl;
    cin >>stop;
  }while(stop=='y');  
  
}



double profit_maxmizer(int x,int y)
{
  
  double number = x*exp((-1*pow(static_cast<double>(y),2))/x);  // calculation
  return number; 
  
}


int generate_range(int y_L,int y_U)
{
  int range = abs(y_L - y_U); // finds the difference
  
  return range+1;  

 
}  
 


void process_data(int lower_bound, int upper_bound,int lower_bound_y,\
int upper_bound_y,\
double array[][10]){

  
   // loop is looking for values in array 
  for(int i = lower_bound;i <= upper_bound;i++)  
  { 
    for(int n = lower_bound_y;n <= upper_bound_y;n++)
    { 
      
      array[i-lower_bound][n-lower_bound_y] = profit_maxmizer(i,n);
      
    } 
    
  }
  
  
}
 
void greet_user()
{
  
  cout <<"Hello Welcome to the program "<<endl;
  
}

void get_key(int& x, int& x_2, int& y, int& y_2)
{
   cout <<"Enter the lower bound and the upper bound for number animal parts"\
   <<endl;
   cin >>x;
   cin >>x_2;
  
    
   cout<<"Enter the lower and upper bound for number animals"<<endl;
   cin >>y;
   cin>>y_2;
  
  
}

void out_put_data(const int size,const int size_x,double array[][10])
{
  
  double col_1,col_2,col_3,col_4,col_5,col_6;
  for(int i = 0;i < size;i++)
  {
    
    
    if (size_x == 6)
    { 
      
      col_1 = array[i][0];
      col_2 = array[i][1];
      col_3 = array[i][2];
      col_4 = array[i][3];
      col_5 = array[i][4];
      col_6 = array[i][5];
      cout.setf(ios::fixed); 
      cout.setf(ios::showpoint); 
      cout.precision(2); 
      cout<<"\t "<<col_1 <<"  "<<col_2\
      <<"  "<<col_3<<" "<<col_4<<" "<<col_5<<" "<<\
      col_6<<endl;
    }      
    if(size_x == 5)
    {
      col_1 = array[i][0];
      col_2 = array[i][1];
      col_3 = array[i][2];
      col_4 = array[i][3];
      col_5 = array[i][4];
      cout.setf(ios::fixed); 
      cout.setf(ios::showpoint); 
      cout.precision(2); 
      cout<<"\t "<<col_1 <<"  "<<col_2\
      <<"  "<<col_3<<" "<<col_4<<" "<<col_5<<endl;
      
    }  
    if(size_x ==4)
    {
      col_1 = array[i][0];
      col_2 = array[i][1];
      col_3 = array[i][2];
      col_4 = array[i][3];
      cout.setf(ios::fixed); 
      cout.setf(ios::showpoint); 
      cout.precision(2); 
      cout<<"\t "<<col_1 <<"  "<<col_2\
      <<"  "<<col_3<<" "<<col_4<<endl;
      
    } 
    if(size_x ==3)
    {
       
      col_1 = array[i][0];
      col_2 = array[i][1];
      col_3 = array[i][2];
      cout.setf(ios::fixed); 
      cout.setf(ios::showpoint); 
      cout.precision(2); 
      cout<<"\t "<<col_1 <<"  "<<col_2\
      <<"  "<<col_3<<endl;
     
    }  
    
    if (size_x ==2)
    {
      col_1 = array[i][0];
      col_2 = array[i][1];
      cout.setf(ios::fixed); 
      cout.setf(ios::showpoint); 
      cout.precision(2); 
      cout<<"\t "<<col_1 <<"  "<<col_2<<endl;
      
    }
    if(size_x ==1)
     {
       
       col_1 = array[i][0];
       cout.setf(ios::fixed); 
       cout.setf(ios::showpoint); 
       cout.precision(2); 
       cout<<"\t"<<col_1<<endl;
       
     }
       
    
    
  }

}
  




