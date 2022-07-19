//
// Created by »ªË¶ on 19/7/2022.
//
#include "acctabc.h"
#include <iostream>
using namespace std;
const int CLIENTS = 4;

void test01()
{
    Brass piggy("Porcelot pigg",381299,4000.00);
    BrassPlus hoggy("Polly Duck",382288,3000.00);
    piggy.Viewacct();
    cout<<endl;
    hoggy.Viewacct();
    cout<<endl;
    cout<<"Depositing $1000 into hoggy account: \n";
    hoggy.Deposit(1000.00);
    cout<<"New balance: $"<<hoggy.Balance()<<endl;
    cout<<"Withdrawing $4200 from the piggy account: \n";
    piggy.Withdraw(4200.00);
    cout<<"piggy account balance: $"<<piggy.Balance()<<endl;
    cout<<"Withdrawing $4200 from the hoggy account: \n";
    hoggy.Withdraw(4200);
    hoggy.Viewacct();
}
void test02()
{
    Brass * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout<<"Enter client's name: ";
        getline(cin,temp);
        cout<<"Enter client's account number: ";
        cin>>tempnum;
        cout<<"Enter opening balance: $";
        cin>>tempbal;
        cout<<"Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout<<"Enter either 1 or 2: ";
        if(kind == '1')
        {
            p_clients[i] = new Brass(temp,tempnum,tempbal);
            cout<<endl;
        }
        else
        {
            double tmax,trate;
            cout<<"Enter the overdraft limit: $";
            cin>>tmax;
            cout<<"Enter the interest rate as a decimal fraction: ";
            cin>>trate;
            //p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
            cout<<endl;
        }
        while (cin.get() != '\n')
            continue;
    }
    for(int i = 0;i < CLIENTS; i++)
    {
        p_clients[i]->Viewacct();
        cout<<endl;
    }
    for(int i = 0;i < CLIENTS; i++)
    {
    delete p_clients[i];
    }
    cout<<"Done.";
}
void test03()
{
    AcctABC * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;

    for (int i = 0; i < CLIENTS; i++)
    {
        cout<<"Enter client's name: ";
        getline(cin,temp);
        cout<<"Enter client's account number: ";
        cin>>tempnum;
        cout<<"Enter opening balance: $";
        cin>>tempbal;
        cout<<"Enter 1 for Brass Account or 2 for BrassPlus Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
        {
            while (cin.get() != '\n')
                continue;
            cout<<"Enter either 1 or 2: ";
        }
        if(kind == '1')
        {
            p_clients[i] = new Brass(temp,tempnum,tempbal);
            cout<<endl;
        }
        else
        {
            double tmax,trate;
            cout<<"Enter the overdraft limit: $";
            cin>>tmax;
            cout<<"Enter the interest rate as a decimal fraction: ";
            cin>>trate;
            p_clients[i] = new BrassPlus(temp,tempnum,tempbal,tmax,trate);
            cout<<endl;
        }
        while (cin.get() != '\n')
            continue;
    }
    for(int i = 0;i < CLIENTS; i++)
    {
        p_clients[i]->Viewacct();
        cout<<endl;
    }
    for(int i = 0;i < CLIENTS; i++)
    {
        delete p_clients[i];
    }
    cout<<"Done.";
}

int main()
{
    test03();

    return 0;
}
