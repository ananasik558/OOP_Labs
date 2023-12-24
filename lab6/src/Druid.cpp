#include "../include/Druid.h"

Druid::Druid(std::string name, int x, int y) : NPC(DruidType, name, x, y) {}

Druid::Druid(std::istream &is) : NPC(DruidType, is) {}

bool Druid::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}

bool Druid::visit(Dragon &monster) 
{
    notify(*this, monster);
    return true;
}
