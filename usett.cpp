#include <iostream>
#include "tabletenn0.h"

using namespace std;

int main() {
    TableTennisPlayer player1("Chuck","Blizzard", true);
    TableTennisPlayer player2("Tara","Boomdea", false);
    RatedPlayer player3(1140,"Mallory","Duck",true);
    player3.Name();
    if(player3.HasTable())
        cout<<": has a table"<<endl;
    else
        cout<<": hasn't a table"<<endl;
    player1.Name();
    if(player1.HasTable())
        cout<<": has a table"<<endl;
    else
        cout<<": hasn't a table"<<endl;
    player2.Name();
    if(player2.HasTable())
        cout<<": has a table"<<endl;
    else
        cout<<": hasn't a table"<<endl;
    player3.Name();
    cout<<"; Rating: "<<player3.Rating()<<endl;
    RatedPlayer player4(1212,player1);
    cout<<"Name: ";
    player4.Name();
    cout<<"; Rating: "<<player4.Rating()<<endl;
    return 0;
}
