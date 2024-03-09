#pragma once

#include "NPC.hpp"
#include "Werewolf.hpp"
#include "Orc.hpp"
#include "Outlaw.hpp"
#include "Observers.hpp"

class Factory {
    public:
        static std::shared_ptr<NPC> Create(const NpcType& type, int x, int y);
};