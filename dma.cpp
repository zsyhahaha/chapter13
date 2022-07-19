//
// Created by »ªË¶ on 19/7/2022.
//

#include "dma.h"
#include <cstring>

baseDMA::baseDMA(const char *l, int r)
{
    lable = new char[std::strlen(l) + 1];
    std::strcpy(lable,l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs)
{
    lable = new char[std::strlen(rs.lable) + 1];
    std::strcpy(lable,rs.lable);
    rating = rs.rating;
}

baseDMA::~baseDMA() noexcept
{
    delete [] lable;
}

baseDMA & baseDMA::operator = (const baseDMA &rs)
{
    if(this == &rs)
        return *this;
    delete [] lable;
    lable = new char[std::strlen(rs.lable)+ 1];
    std::strcpy(lable,rs.lable);
    rating = rs.rating;
    return *this;
}

std::ostream & operator << (std::ostream & os,const baseDMA & rs)
{
    os << "Label : "<<rs.lable<<std::endl;
    os << "Rating : "<<rs.rating<<std::endl;
    return os;
}

lacksDMA::lacksDMA(const char * c ,const char * l ,int r ) : baseDMA(l,r)
{
    std::strncpy(color,c,39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs)  : baseDMA(rs)
{
    std::strncpy(color,c,COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator << (std::ostream & os,const lacksDMA & ls)
{
    os << (const baseDMA &) ls;
    os << "Color : "<<ls.color<<std::endl;
    return os;
}

hasDMA::hasDMA(const char * s, const char *l, int r) : baseDMA(l,r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style,s);
}

hasDMA::hasDMA(const char * c, const baseDMA &rs) : baseDMA(rs)
{
    style = new char[std::strlen(c) + 1];
    std::strcpy(style,c);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style,hs.style);
}

hasDMA::~hasDMA() noexcept
{
    delete [] style;
}

hasDMA & hasDMA::operator = (const hasDMA & hs)
{
    if(this == &hs)
        return *this;
    baseDMA::operator=(hs);
    delete [] style;
    style = new char[std::strlen(hs.style)+ 1];
    std::strcpy(style,hs.style);
    return *this;
}

std::ostream & operator << (std::ostream & os,const hasDMA & rs)
{
    os << (const baseDMA &) rs;
    os << "Style : "<<rs.style<<std::endl;
    return os;
}