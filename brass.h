//
// Created by »ªË¶ on 19/7/2022.
//

#ifndef CHAPTER13_BRASS_H
#define CHAPTER13_BRASS_H

#include <string>
class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;
public:
    explicit Brass(const std::string & s = "Nullbody",long an = -1,double bal = 0.0);
    void Deposit(double amt);
    double Balance() const;
    virtual void Withdraw(double amt);
    virtual void Viewacct() const;
    virtual ~Brass() = default;
};

class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    explicit BrassPlus(const std::string & s = "Nullbody",long an = -1,double bal = 0.0,double ml = 500,double r = 0.11125);
    explicit BrassPlus(const Brass & ba,double ml = 500,double r = 0.11125);
    void Viewacct() const override;
    void Withdraw(double amt) override;
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

#endif //CHAPTER13_BRASS_H
