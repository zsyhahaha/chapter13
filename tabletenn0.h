//
// Created by »ªË¶ on 19/7/2022.
//

#ifndef CHAPTER13_TABLETENN0_H
#define CHAPTER13_TABLETENN0_H
#include <string>

using std::string;

class TableTennisPlayer {
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string & fn = "none",const string & ln = "none",bool hT = false);
    void Name() const;
    bool HasTable() const
    {
        return hasTable;
    }
    void ResetTable(bool v)
    {
        hasTable = v;
    }
};

class RatedPlayer : public TableTennisPlayer
{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0,const string & fn = "none",const string & ln = "none",bool hT = false);
    RatedPlayer(unsigned int r ,const TableTennisPlayer & tp);
    unsigned int Rating() const
    {
        return rating;
    }
    void ReSetRating(unsigned int r)
    {
        rating = r;
    }
};

#endif //CHAPTER13_TABLETENN0_H
