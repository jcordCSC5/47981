/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 12, 2012, 11:22 AM
 * Distance as a function of gravity
 * y(g)
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

//Only utilize this area for constant
//variables.  No other variables belong
//in this area or an F for the assignment
//will be given
const float GRAVITY=32.17;//FT/SEC^2

int main(int argc, char** argv) {
    //Declare the time variable
    float time;
    //Ask for a time value
    cout<<"How long did the object drop in seconds?"<<endl;
    cin>>time;
    //Calculate the distance dropped
    //float y=GRAVITY*pow(time,2)/2;
    float y=GRAVITY*time*time/2;//preferred
    //Output the results
    cout<<"The distance dropped = "<<y<<"ft"<<endl;
    //Exit
    return 0;
}

