//
// Created by »ªË¶ on 19/7/2022.
//

#include "tabletenn0.h"
#include <iostream>

using namespace std;

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool hT) : firstname(fn),lastname(ln),hasTable(hT)
{}

void TableTennisPlayer::Name() const {
    cout<<lastname<<" , "<<firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool hT) : TableTennisPlayer(fn,ln,hT)
{
    rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp) : TableTennisPlayer(tp),rating(r)
{}