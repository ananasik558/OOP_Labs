#include "../include/factory.h"

std::shared_ptr<NPC> factory(NpcType type, std::string name, int x, int y)
{
    switch (type)
    {
        case DragonType :
            return std::make_shared<Dragon>(name, x, y);
            break;
        case DruidType :
            return std::make_shared<Druid>(name, x, y);
            break;
        case ElfType :
            return std::make_shared<Elf>(name, x, y);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}

std::shared_ptr<NPC> factory(std::istream &is)
{
    int type;
    is >> type;
    switch (type)
    {
        case DragonType :
            return std::make_shared<Dragon>(is);
            break;
        case DruidType :
            return std::make_shared<Druid>(is);
            break;
        case ElfType :
            return std::make_shared<Elf>(is);
            break;
        default:
            std::cout << "unexpected type : " << type << std::endl;
            break;
    }
    return nullptr;
}