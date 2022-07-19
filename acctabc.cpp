//
// Created by »ªË¶ on 19/7/2022.
//
#include <iostream>
#include "acctabc.h"

using namespace std;

AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if(amt < 0)
        cout<<"Negative deposit not allowed; deposit is cancelled."<<endl;
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

AcctABC::format AcctABC::setFormat() const
{
    format f;
    f.flag = cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::restore(format &f) const
{
    cout.setf(f.flag,ios_base::floatfield);
    cout.precision(f.pr);
}

void Brass::Withdraw(double amt)
{
    if(amt < 0)
        cout<<"Withdrawal amount must be positive; withdraw cancelled."<<endl;
    else if(amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout<<"Withdrawal amount of $"<<amt<<" exceeds your balance.\n"<<"Withdrawal cancelled."<<endl;
}

void Brass::Viewacct() const
{
    format f = setFormat();
    cout<<"Client: "<<FullName()<<endl;
    cout<<"Account Number: "<<AcctNum()<<endl;
    cout<<"Balance: $"<<Balance()<<endl;
    restore(f);
}

BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r) : AcctABC(s,an,bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::Viewacct() const
{
    format f =setFormat();

    cout<<"BrassPlus Client: "<<FullName()<<endl;
    cout<<"Account Number: "<<AcctNum()<<endl;
    cout<<"Balance: $"<<Balance()<<endl;
    cout<<"Maximum loan: $"<<maxLoan<<endl;
    cout<<"Owed to bank: $"<<owesBank<<endl;
    cout.precision(3);
    cout<<"Loan Rate: "<<100 * rate<<"%\n";
    restore(f);
}

void BrassPlus::Withdraw(double amt)
{
    format f =setFormat();
    double bal = Balance();
    if(amt <= bal)
        AcctABC::Withdraw(amt);
    else if(amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout<<"Bank advance: $"<<advance<<endl;
        cout<<"Finance charge: $"<<advance * rate<<endl;
        Deposit(advance);
        AcctABC::Withdraw(amt);
    }
    else
        cout<<"Credit limit exceeded. Transaction cancelled.\n";
    restore(f);
}



