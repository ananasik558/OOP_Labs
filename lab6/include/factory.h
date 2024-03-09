#pragma once

#include "werewolf.h"
#include "ork.h"
#include "outlaw.h"
#include "observe.h"
#include <cstdlib>

class Factory
{
public:
    std::shared_ptr<Heroes> createHero(HeroesClass hClass, short int x, short int y);
    std::shared_ptr<Heroes> createHero(std::istream & is);
};