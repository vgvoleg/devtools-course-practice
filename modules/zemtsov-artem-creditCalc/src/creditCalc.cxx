//
//  creditCalc.cpp
//  firstAttempt
//
//  Created by артем on 22.04.16.
//  Copyright © 2016 артем. All rights reserved.
//

#include <stdio.h>

#include "../include/creditCalc.h"

void CreditPerson::setStartTime(const int dayImp, const int monthImp, const int yearImp)
{
    startDay.setTime(dayImp, monthImp, yearImp);
}

void CreditPerson::setFinishDay(const int dayImp, const int monthImp, const int yearImp)
{
    finishDay.setTime(dayImp, monthImp, yearImp);
}

void CreditPerson::printInfo()
{
    cout<<"Info about your credit"<<endl
    <<"Your get credit at:"<<endl;
    startDay.printInfo();
    cout<<"Your procent = "<<procent<<endl
    <<"Your enter = "<<yourEnter<<endl
    <<"You need to pay = "<<needToPay<<endl
    <<"";
    

}

void CreditPerson::printInfoAboutFinish()
{
    cout<<"Info about finish"<<endl
        <<"You need to pay = "<<needToPay<<endl
        <<"Final day is "<<endl;
    finishDay.printInfo();
}

void CreditPerson::setProcentByUser(const double procentImp)
{
    try {
        if ( (procentImp>=0)&&(procentImp<=100) )
             procent=procentImp/100;// 30%=0,3
        else
            throw 1;
    } catch (int err) {
        if (err==1)
        {
            cout<<"Invalide procent(0<=procent<=100)"<<endl;
            throw 1;
        }
    }
   
}

double CreditPerson::newInstallment(const double installmentImp)
{

    try {
        if (installmentImp>=0)
        {
            paymentExecution(installmentImp);
            return needToPay;
        }
        else
        {
            throw 1;
            return -1;
        }
    } catch (int err) {
        if (err==1)
        {
            cout<<"Invalide installment(must be more than 0)"<<endl;
            throw 1;
        }
    }
    return NULL;
}

double CreditPerson::performTheCalculation()
{
    if (creditTime>=12)
        needToPay=cost+cost*procent*( (double)creditTime/12);// calc cost with
    else
        if (creditTime){
            needToPay=cost+cost*procent*((double)creditTime/12);
        }
    middlePay=needToPay/creditTime;// calc everemonth pay
    return needToPay;
}

void CreditPerson::setCreditTime(const int timeImp)
{
    creditTime=timeImp;
}

void CreditPerson::discoverCost(const double costImp)
{
    try {
        if (costImp<=0)
            throw 1;
        else
        {
            setCost(costImp);
        }
    }
    catch (int err) {
        if (err==1)
        {
            cout<<"Invalide cost(cost must be more than 0)"<<endl;
            throw 1;
        }
    }
    
}

void CreditPerson::paymentExecution(const double payImp)
{
    try
    {
        if ( (payImp<0)||(payImp>needToPay) )throw 1;// throw if payment less than zero
        else
        {
           if(payImp!=needToPay)// middle pay
           {
               needToPay-=payImp;
               yourEnter+=payImp;
           }
            else// full pay
            {
                needToPay-=payImp;
                yourEnter+=payImp;
                creditTime=0;
                setEarlyFinish();
            }
        }
    }
    
    catch (int err)
    {
        if (err==1)
        {
            cout<<"Invalide payment"<<endl;
            throw 1;
        }
        
    }
}

void CreditPerson::setStartTimeByUser(const int dayImp,const int monthImp,const int yearImp)
{
    // Check
    checkDay(dayImp);
    checkMonth(monthImp);
    checkYear(yearImp);
    // Set
    setStartTime(dayImp,monthImp,yearImp);
}

void CreditPerson::setFinishTimeByUser(const int creditTimeImp)
{
    creditTime=creditTimeImp;
    try
    {
        if (creditTime<1)
            throw 1;
        else
            setFinishDay(getStartDay(), (startDay.getMonth() +creditTime)%12, getStartYear()+creditTime/12);
    }
    catch (int err) {
        cout<<"Invalide credit time (must be more than 0)"<<endl;
        throw 1;
    }
}

void CreditPerson::checkDay(int dayImp)
{
    try
    {
        if ( (dayImp<1)||(dayImp>31) )
            throw 1;
    }
    
    catch (int err)
    {
        if (err==1)
        {
            cout<<"Invalid day"<<endl;
            throw 1;
        }
    }
}

void CreditPerson::checkMonth(int monthImp)
{
    try
    {
        if ( (monthImp<1)||(monthImp>12) )
            throw 1;
    }
    
    catch (int err)
    {
        if (err==1)
        {
            cout<<"Invalid month"<<endl;
            throw 1;
        }
    }
}

void CreditPerson::checkYear(int yearImp)
{
    try
    {
        if ( (yearImp<1900)||(yearImp>9999) )
            throw 1;
    }
    
    catch (int err)
    {
        if (err==1)
        {
            cout<<"Invalid year(min-1900,max-9999)"<<endl;
            throw 1;
        }
    }
}

void CreditPerson::setEarlyFinish()
{
    cout<<"You successfuly closed your credit"<<endl;
}
