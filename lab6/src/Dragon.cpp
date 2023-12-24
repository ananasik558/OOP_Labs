#include "../include/Dragon.h"

Dragon::Dragon(std::string name, int x, int y) : NPC(DragonType, name, x, y) {}

Dragon::Dragon(std::istream &is) : NPC(DragonType, is) {}

bool Dragon::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}

bool Dragon::visit(Elf &monster) 
{
    notify(*this, monster);
    return true;
}
