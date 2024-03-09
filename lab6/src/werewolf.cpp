#include "../include/werewolf.h"

bool WerewolfVisitor::visit(const std::shared_ptr<Werewolf>& attacker) const {
    return 0;
}

bool WerewolfVisitor::visit(const std::shared_ptr<Outlaw>& attacker) const {
    return 1;
}

bool WerewolfVisitor::visit(const std::shared_ptr<Ork>& attacker) const {
    return 0;
}

Werewolf::Werewolf(std::string hName, short int x, short int y) : Heroes(WEREWOLF, hName, x, y) {}

Werewolf::Werewolf(std::istream & is) : Heroes(WEREWOLF, is) {}

void Werewolf::print()
{
    std::cout << *this;
}

void Werewolf::save(std::ostream & os)
{
    os << WEREWOLF << std::endl;
    Heroes::save(os);
}

std::ostream & operator<<(std::ostream & os, Werewolf & sq)
{
    os << "Werewolf: " << *static_cast<Heroes*> (&sq) << std::endl;
    return os;
}

int Werewolf::accept(const std::shared_ptr<Visitor>& attacker_visitor, const std::shared_ptr<Heroes>& attacker)
{
    std::shared_ptr<const Heroes> npc_const_ptr = shared_from_this();
    std::shared_ptr<Heroes> npc_ptr = std::const_pointer_cast<Heroes>(npc_const_ptr);
    std::shared_ptr<Werewolf> defender = std::dynamic_pointer_cast<Werewolf>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fightNotify(defender, result);

    return result;
}
