#pragma once

#include "NPC.hpp"
#include "Werewolf.hpp"
#include "Orc.hpp"
#include "Outlaw.hpp"
#include "Factory.hpp"

class DataMethods {
    public:
        static void save_array(const set_t& array, const std::string& filename);
        static set_t load_array(const std::string& filename);
};

std::ostream& operator << (std::ostream& os, const set_t& array);