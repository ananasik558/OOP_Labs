#include "../include/Elf.h"

Elf::Elf(std::string name, int x, int y) : NPC(ElfType, name, x, y) {}

Elf::Elf(std::istream &is) : NPC(ElfType, is) {}

bool Elf::accept(NPC &visitor) 
{
    return visitor.visit(*this);
}

bool Elf::visit(Druid &monster) 
{
    notify(*this, monster);
    return true;
}
