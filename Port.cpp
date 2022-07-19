//
// Created by 华硕 on 19/7/2022.
//

#include "Port.h"
#include <cstring>


Port::Port(const char *br, const char *st, int b)
{
    brand = new char[std::strlen(br) + 1]; //new分配内存;
    std::strcpy(brand, br);
    std::strncpy(style, st, 20);
    style[19] = '\0'; //保证字符串是有效的;
    bottles = b;
}

Port::Port(const Port &p)
{
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strncpy(style, p.style, 20);
    style[19] = '\0';
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if (this == &p)
    {
        return *this;
    }
    delete[] brand;
    brand = new char[std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    std::strncpy(style, p.style, 20);
    style[19] = '\0';
    bottles = p.bottles;
}

Port &Port::operator+=(int b)
{
    bottles += b;
    return *this; //返回调用对象的引用;
}

Port &Port::operator-=(int b)
{
    bottles -= b;
    return *this; //返回调用对象的引用;
}

void Port::show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
    return;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}


VintagePort::VintagePort() : Port("none", "vintage", 0) //成员列表初始化派生类的基类对象数据;
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b) //成员列表初始化派生类的基类对象数据;
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp) //调用基类复制构造函数初始化派生类的基类对象数据;
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
    {
        return *this;
    }
    delete[] nickname;
    Port::operator=(vp); //调用基类赋值运算符修改派生类的基类数据成员;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::show() const
{
    Port::show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
    return;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp; //强制类型转换调用Port基类的重载输出流运算符方法;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
