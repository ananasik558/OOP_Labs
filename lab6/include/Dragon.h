#pragma once

#include "npc.h"
#include "Elf.h"
#include "Druid.h"

class Dragon : public NPC 
{
    public:
        Dragon(std::string name, int x, int y);
        Dragon(std::istream& is);
        virtual ~Dragon() = default;

        bool accept(NPC &visitor) override;
        bool visit(Elf &monster) override;
};
