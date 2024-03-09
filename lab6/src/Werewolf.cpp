#include "../headers/Werewolf.hpp"

bool WerewolfVisitor::visit(const std::shared_ptr<Werewolf>& defender) const {
    return false;
}

bool WerewolfVisitor::visit(const std::shared_ptr<Outlaw>& defender) const {
    return true;
}

bool WerewolfVisitor::visit(const std::shared_ptr<Orc>& defender) const {
    return false;
}

Werewolf::Werewolf() : NPC(WerewolfType, 0, 0) {}

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y) {}

Werewolf::Werewolf(std::istream& in) : NPC(WerewolfType, in) {}

void Werewolf::save(std::ostream& out) {
    out << WerewolfType << std::endl;
    NPC::save(out);
}

bool Werewolf::accept(const std::shared_ptr<FightVisitor>& attacker_visitor, const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<const NPC> npc_const_ptr = shared_from_this();
    std::shared_ptr<NPC> npc_ptr = std::const_pointer_cast<NPC>(npc_const_ptr);
    std::shared_ptr<Werewolf> defender = std::dynamic_pointer_cast<Werewolf>(npc_ptr);

    bool result = attacker_visitor->visit(defender);

    attacker->fight_notify(defender, result);

    return result; 
}

std::ostream& operator << (std::ostream& out, Werewolf& Werewolf) {
    out << "Werewolf: " << *static_cast<NPC*>(&Werewolf) << std::endl;
    return out;
}

void Werewolf::print() {
    std::cout << *this;
}