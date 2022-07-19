//
// Created by »ªË¶ on 19/7/2022.
//
#include "dma.h"
#include <iostream>

using namespace std;

int main()
{
    baseDMA shirt("portabelly",8);
    lacksDMA ballon("red","bilipo",4);
    hasDMA map("Mercator","Bufollo Keys",5);
    cout<<"Displaying baseDMA object: "<<endl;
    cout<<shirt<<endl;
    cout<<"Displaying lacksDMA object: "<<endl;
    cout<<ballon<<endl;
    cout<<"Displaying hasDMA object: "<<endl;
    cout<<map<<endl;
    lacksDMA ballon2(ballon);
    cout<<"LacksDMA copy: "<<ballon2<<endl;
    hasDMA map2;
    map2 = map;
    cout<<"HasDMA assignment: "<<map2<<endl;
    return 0;
}