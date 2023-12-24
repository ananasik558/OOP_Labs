#ifndef Druid_H
#define Druid_H

#include "npc.h"
#include "Dragon.h"
#include "Elf.h"

class Druid : public NPC
{
    public:
        Druid(std::string name, int x, int y);
        Druid(std::istream& is);
        virtual ~Druid() = default;

        bool accept(NPC &visitor) override;
        bool visit(Dragon &monster) override;
};

#endif
