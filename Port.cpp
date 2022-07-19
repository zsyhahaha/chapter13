//
// Created by ��˶ on 19/7/2022.
//

#include "Port.h"
#include <cstring>


Port::Port(const char *br, const char *st, int b)
{
    brand = new char[std::strlen(br) + 1]; //new�����ڴ�;
    std::strcpy(brand, br);
    std::strncpy(style, st, 20);
    style[19] = '\0'; //��֤�ַ�������Ч��;
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
    return *this; //���ص��ö��������;
}

Port &Port::operator-=(int b)
{
    bottles -= b;
    return *this; //���ص��ö��������;
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


VintagePort::VintagePort() : Port("none", "vintage", 0) //��Ա�б��ʼ��������Ļ����������;
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "vintage", b) //��Ա�б��ʼ��������Ļ����������;
{
    nickname = new char[std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp) //���û��ิ�ƹ��캯����ʼ��������Ļ����������;
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
    Port::operator=(vp); //���û��ำֵ������޸�������Ļ������ݳ�Ա;
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
    os << (const Port &)vp; //ǿ������ת������Port�����������������������;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
