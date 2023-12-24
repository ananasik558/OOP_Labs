#ifndef Elf_H
#define Elf_H

#include "npc.h"
#include "Dragon.h"
#include "Druid.h"

class Elf : public NPC
{
    public:
        Elf(std::string name, int x, int y);
        Elf(std::istream& is);
        virtual ~Elf() = default;

        bool accept(NPC &visitor) override;
        bool visit(Druid &monster) override;
};

#endif
