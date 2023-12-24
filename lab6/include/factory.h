#pragma once

#include "npc.h"
#include "Dragon.h"
#include "Druid.h"
#include "Elf.h"

std::shared_ptr<NPC> factory(std::istream &is);
std::shared_ptr<NPC> factory(NpcType type, std::string name, int x, int y);