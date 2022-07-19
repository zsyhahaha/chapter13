//
// Created by »ªË¶ on 19/7/2022.
//

#ifndef CHAPTER13_DMA_H
#define CHAPTER13_DMA_H
#include <iostream>

class baseDMA {
private:
    char * lable;
    int rating;
public:
    baseDMA(const char * l = "null",int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator = (const baseDMA & rs);
    friend std::ostream & operator << (std::ostream & os,const baseDMA & rs);
};

class lacksDMA : public baseDMA
{
private:
    enum {
        COL_LEN =40
    };
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank",const char * l = "null",int r = 0);
    lacksDMA(const char * c ,const baseDMA & rs);
    friend std::ostream & operator << (std::ostream & os,const lacksDMA & ls);
};

class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none",const char * l = "null",int r = 0);
    hasDMA(const char * c ,const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator = (const hasDMA & hs);
    friend std::ostream & operator << (std::ostream & os,const hasDMA & rs);
};


#endif //CHAPTER13_DMA_H
