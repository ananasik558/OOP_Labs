#pragma once

#include "NPC.hpp"
#include "Outlaw.hpp"
#include "Orc.hpp"
#include "Werewolf.hpp"
#include "Observers.hpp"

class Factory {
    public:
        static std::shared_ptr<NPC> Create(const NpcType& type, int x, int y);
};

class VisitorFactory {
    public:
        static std::shared_ptr<FightVisitor> Create(const NpcType& type);
};