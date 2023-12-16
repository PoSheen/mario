#ifndef DATACENTER_H_INCLUDED
#define DATACENTER_H_INCLUDED
#include <vector>
#include <list>
#include "Hero.h"
#include "map.h"

class DataCenter{
public:
    Hero& get_Hero(){
        return dragonite;
    }
    Map& get_map(){
        return map1;
    }
private:
    Hero dragonite;
    Map map1;
};

extern DataCenter* const DC;

#endif
