// Copyright 2020 - Simon Benzer
// CSCE 240 - Dr. Jeremy Lewis

//program to deconstruct a number into power series
#include <iostream>
#include <string>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::to_string;
using std::string;

int main(int argc, char* argv[]){
    
    //initialize variables
    int input = 0;
    const int kLengthOfArray = 20;
    int series[kLengthOfArray] = {};
    string powerSeries = "";
   
    
    //take int from command line using cin
    //cout << "Enter number to deconstruct:";
    cout << "Enter multi-digit number to decompose: ";
    cin >> input;
    
    //initialize loop variables
    int j = kLengthOfArray;
    int temp = abs(input);
    int startingPoint = 0;
    
    //calculate length of series and populate array
    for (int i=0;i<kLengthOfArray;i++) {
        if(temp % 10 == 0) {
            break;
        }
        if(temp<10){
            series[j] = temp % 10;
            //cout << "if statement runs";
            break;
        }
        series[j] = temp % 10;
        temp = temp/10;
        ++i;
        --j;
        startingPoint = j;
    }
    
    //create power series
    if (input<0) {
        powerSeries = "-(";
    }
    
    series[startingPoint] = series[startingPoint]*(pow(10,kLengthOfArray-startingPoint));
    powerSeries += to_string(series[startingPoint]);
    
    for(int g = startingPoint+1;g<=kLengthOfArray;g++) {
        series[g] = series[g]*(pow(10,kLengthOfArray-g));
        powerSeries += " + " +to_string(series[g]);
    }
    
    if (input<0) {
        powerSeries += ")";
    }
    //print
    cout << "Decomposition: " << powerSeries << endl;

}
