#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <set>
#include <memory>

#define fileOutput "log.txt"


enum NpcType 
{
    Unknown = 0,
    DragonType = 1,
    DruidType = 2,
    ElfType = 3
};

class Observer;

class ObserverConsole;
class ObserverFile;


class NPC;

class Dragon;
class Druid;
class Elf;
