//
//  creditCalc.cpp
//  firstAttempt
//
//  Created by артем on 22.04.16.
//  Copyright © 2016 артем. All rights reserved.
//

#include <stdio.h>

#include "../include/creditCalc.h"

CreditPerson::CreditPerson() {
    creditTime =  0;
    procent = 0;
    cost = 0;
    yourEnter = 0;
    needToPay = 0;
}
void CreditPerson::setStartTime
    (const int dayImp, const int monthImp, const int yearImp) {
    startDay.setTime(dayImp, monthImp, yearImp);
}

void CreditPerson::setFinishDay
    (const int dayImp, const int monthImp, const int yearImp) {
    finishDay.setTime(dayImp, monthImp, yearImp);
}

void CreditPerson::setProcentByUser(const double procentImp) {
    try {
        if ( (procentImp >= 0) && (procentImp <= 100) )
             procent = procentImp / 100;  // 30%=0,3
        else
            throw std::invalid_argument("1");
    } catch (int err) {
        if (err == 1) {
            std::cout<< "Invalide procent(0<=procent<=100)"<< std::endl;
            throw 1;
        }
    }
}

double CreditPerson::newInstallment(const double installmentImp) {
        if (installmentImp >= 0) {
            paymentExecution(installmentImp);
            return needToPay;
        } else {
            throw std::invalid_argument("1");
            std::cout<< "Invalide installment(must be more than 0)"<< std::endl;
            throw std::invalid_argument("1");
        }
}

double CreditPerson::performTheCalculation() {
    if (creditTime >= 12) {
        needToPay = cost+cost*procent*
        (static_cast<double>(creditTime / 12));  // calc cost with
    } else {
        if ( creditTime ) {
            needToPay = cost+cost*procent*
            (static_cast<double>(creditTime/12));
        }
    }
    middlePay = needToPay/creditTime;  // calc everemonth pay
    return needToPay;
}

void CreditPerson::setCreditTime(const int timeImp) {
    creditTime = timeImp;
}

void CreditPerson::discoverCost(const double costImp) {
    try {
        if (costImp <= 0) {
            throw std::invalid_argument("1");} else {
            setCost(costImp);
        }
    }catch (int err) {
        if (err == 1) {
            std::cout<< "Invalide cost(cost must be more than 0)"<< std::endl;
            throw std::invalid_argument("1");;
        }
    }
}

void CreditPerson::paymentExecution(const double payImp) {
    try {
        if ( (payImp < 0) || (payImp > needToPay) ) {
            throw std::invalid_argument("1");} else {
           if (payImp != needToPay) {
               needToPay -= payImp;
               yourEnter += payImp;
           } else {
                needToPay -= payImp;
                yourEnter += payImp;
                creditTime = 0;
                setEarlyFinish();
            }
        }
    }catch (int err) {
        if (err == 1) {
            std::cout<< "Invalide payment"<< std::endl;
            throw std::invalid_argument("1");
        }
    }
}

void CreditPerson::setStartTimeByUser
    (const int dImp, const int mImp, const int yImp) {
    // Check
    checkDay(dImp);
    checkMonth(mImp);
    checkYear(yImp);
    // Set
    setStartTime(dImp, mImp, yImp);
}

void CreditPerson::setFinishTimeByUser
    (const int creditTimeImp) {
    setCreditTime(creditTimeImp);
    try {
        if (creditTime < 1) {
            throw std::invalid_argument("1");} else {
            setFinishDay(getStartDay(),
                         (startDay.getMonth() +creditTime)%12,
                          getStartYear()+creditTime/12);
            }
    }catch (int err) {
        std::cout<< "Invalide credit time (must be more than 0)"<< std::endl;
        throw std::invalid_argument("1");
    }
}

void CreditPerson::checkDay(int dayImp) {
    try {
        if ( (dayImp < 1) || (dayImp > 31) )
            throw std::invalid_argument("1");
    } catch (int err) {
        if (err == 1) {
            std::cout<< "Invalid day"<< std::endl;
            throw std::invalid_argument("1");
        }
    }
}

void CreditPerson::checkMonth(int monthImp) {
    try {
        if ( (monthImp < 1) || (monthImp > 12) )
            throw std::invalid_argument("1");
    } catch (int err) {
        if (err == 1) {
            std::cout<< "Invalid month"<< std::endl;
            throw std::invalid_argument("1");
        }
    }
}

void CreditPerson::checkYear(int yearImp) {
    try {
        if ( (yearImp < 1900) || (yearImp > 9999) )
            throw std::invalid_argument("1");
    } catch (int err) {
        if (err == 1) {
            std::cout<< "Invalid year(min-1900,max-9999)"<< std::endl;
            throw std::invalid_argument("1");
        }
    }
}

void CreditPerson::setEarlyFinish() {
    std::cout<< "You successfuly closed your credit"<< std::endl;
}
