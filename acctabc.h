//
// Created by »ªË¶ on 19/7/2022.
//

#ifndef CHAPTER13_ACCTABC_H
#define CHAPTER13_ACCTABC_H
#include <iostream>
#include <string>

class AcctABC {
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct format
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName() const
    {
        return fullName;
    }
    long AcctNum() const
    {
        return acctNum;
    }
    format setFormat() const;
    void restore(format & f) const;
public:
    AcctABC(const std::string & s = "Nullbody",long an = -1,double bal = 0.0);
    void Deposit(double amt);
    double Balance() const
    {
        return balance;
    }
    virtual void Withdraw(double amt) = 0;
    virtual void Viewacct() const = 0;
    virtual ~AcctABC() = default;
};

class Brass : public AcctABC{
public:
    Brass(const std::string & s = "Nullbody",long an = -1,double bal = 0.0) : AcctABC(s,an,bal) {}
    virtual void Withdraw(double amt);
    virtual void Viewacct() const;
    virtual ~Brass() {}
};

class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string & s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r = 0.10);
    BrassPlus(const Brass & ba,double ml = 500,double r = 0.1);
    virtual void Viewacct() const;
    virtual void Withdraw(double amt);
    void ReSetMax(double m)
    {
        maxLoan = m;
    }
    void ReSetRate(double r)
    {
        rate = r;
    }
    void ReSetOwes()
    {
        owesBank = 0;
    }
};

#endif //CHAPTER13_ACCTABC_H
