//
//  moment.hpp
//  firstAttempt
//
//  Created by артем on 21.04.16.
//  Copyright © 2016 артем. All rights reserved.
//

#ifndef moment_hpp
#define moment_hpp

#include <stdio.h>




#include <iostream>
#include <stdio.h>
using namespace std;

class Moment
{
private:
    int day,month,year;
public:
    Moment()
    {
        day=0;
        month=0;
        year=0;
    }
    //get
    int getDay(){return day;}
    int getMonth(){return month;}
    int getYear(){return year;}
    //set
    void setTime(int day,int month,int year);
    //show info
    void printInfo() ;
    
};

#endif /* moment_hpp */

