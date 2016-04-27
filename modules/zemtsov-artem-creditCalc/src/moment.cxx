//
//  moment.cpp
//  firstAttempt
//
//  Created by артем on 21.04.16.
//  Copyright © 2016 артем. All rights reserved.
//
#include "../include/moments.h"

void Moment::setTime(int dayImp, int monthImp, int yearImp)
{
    day=dayImp;
    month=monthImp;
    year=yearImp;
}

void Moment::printInfo()
{
    cout<<"Day - "<<day<<endl
        <<"Month - "<<month<<endl
        <<"Year - "<<year<<endl;
}

