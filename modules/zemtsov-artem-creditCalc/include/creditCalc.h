//
//  creditCalc.h
//  firstAttempt
//
//  Created by артем on 22.04.16.
//  Copyright © 2016 артем. All rights reserved.
//

#ifndef creditCalc_h
#define creditCalc_h


#include "moments.h"

class CreditPerson
{
private:
    // variables
    Moment startDay,finishDay;
    int creditTime;// credit period
    double procent;
    double cost;// start price
    double yourEnter;// start enter
    double needToPay;// price with procent
    double middlePay;// everymonth pay
    // methods
    
    // set
    void setStartTime(const int dayImp,const int monthImp,const int yearImp) ;
    void setCreditTime(const int timeImp);
    void setFinishDay(const int dayImp,const int monthImp,const int yearImp);
    void setEarlyFinish();
    void setCost(const double costImp){cost=costImp;needToPay=costImp;}
    
    // get
    int getStartDay() {return startDay.getDay();}
    int getStartMonth() {return startDay.getMonth() ;}
    int getStartYear() {return startDay.getYear() ;}
    
    // math methods
    void paymentExecution(const double payImp);
    
    // check
    void checkDay(int dayImp);
    void checkMonth(int monthImp);
    void checkYear(int yearImp);
    
    // show info
    void printInfoAboutFinish();
    void printInfo();// print day month and year
    
public:
    // constructors
    CreditPerson() {
        creditTime=0;
        procent=0;
        cost=0;
        yourEnter=0;
        needToPay=0;
    }
    // set
    void setProcentByUser(const double procentImp) ;
    void setStartTimeByUser(const int dayImp,const int monthImp,const int yearImp);
    void setFinishTimeByUser(const int creditTimeImp);
    
    // get
    double getBalanceOfTheDebt(){return needToPay;}

    // math methods
    double newInstallment(const double installmentImp);// new installment by person
    double performTheCalculation();// calculating price with procent
    void discoverCost(const double costImp);// setCost
};
#endif /* creditCalc_h */
