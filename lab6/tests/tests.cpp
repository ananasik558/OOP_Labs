#include "../headers/NPC.hpp"
#include "../headers/Werewolf.hpp"
#include "../headers/Orc.hpp"
#include "../headers/Outlaw.hpp"
#include "../headers/Factory.hpp"
#include "../headers/Observers.hpp"

#include <gtest/gtest.h>

TEST(NPC_class_tests, getters) {
    std::shared_ptr<NPC> ptr = std::make_shared<Werewolf>(2,2);
    ASSERT_TRUE(ptr->gettype() == 0 && ptr->get_x_value() == 2 && ptr->get_y_value() == 2);
}

TEST(NPC_class_tests, is_close_method_1) {
    std::shared_ptr<NPC> ptr1 = std::make_shared<Orc>(0,0);
    std::shared_ptr<NPC> ptr2 = std::make_shared<Outlaw>(10,10);
    ASSERT_TRUE(ptr1->is_close(ptr2, 20));
}

TEST(NPC_class_tests, is_close_method_2) {
    std::shared_ptr<NPC> ptr1 = std::make_shared<Orc>(0,0);
    std::shared_ptr<NPC> ptr2 = std::make_shared<Outlaw>(10,10);
    ASSERT_FALSE(ptr1->is_close(ptr2, 2));
}

TEST(Werewolf_tests, Werewolf_visitor_test_1) {
    WerewolfVisitor visitor;
    std::shared_ptr<Werewolf> ptr = std::make_shared<Werewolf>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Werewolf_tests, Werewolf_visitor_test_2) {
    WerewolfVisitor visitor;
    std::shared_ptr<Outlaw> ptr = std::make_shared<Outlaw>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(Werewolf_tests, Werewolf_visitor_test_3) {
    WerewolfVisitor visitor;
    std::shared_ptr<Orc> ptr = std::make_shared<Orc>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Werewolf_class_tests, default_constructor_and_destructor) {
    Werewolf s;
    s.~Werewolf();
}

TEST(Werewolf_class_tests, int_constructor) {
    Werewolf s(2,2);
    ASSERT_TRUE(s.gettype() == 0 && s.get_x_value() == 2 && s.get_y_value() == 2);
}

TEST(Werewolf_class_tests, accept_method_1) {
    std::shared_ptr<NPC> defender = std::make_shared<Werewolf>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Orc>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<OrcVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Werewolf_class_tests, accept_method_2) {
    std::shared_ptr<NPC> defender = std::make_shared<Werewolf>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Werewolf>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<WerewolfVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Werewolf_class_tests, accept_method_3) {
    std::shared_ptr<NPC> defender = std::make_shared<Werewolf>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<OutlawVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(Outlaw_tests, Outlaw_visitor_test_1) {
    OutlawVisitor visitor;
    std::shared_ptr<Werewolf> ptr = std::make_shared<Werewolf>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(Outlaw_tests, Outlaw_visitor_test_2) {
    OutlawVisitor visitor;
    std::shared_ptr<Outlaw> ptr = std::make_shared<Outlaw>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Outlaw_tests, Outlaw_visitor_test_3) {
    OutlawVisitor visitor;
    std::shared_ptr<Orc> ptr = std::make_shared<Orc>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Outlaw_class_tests, default_constructor_and_destructor) {
    Outlaw d;
    d.~Outlaw();
}

TEST(Outlaw_class_tests, int_constructor) {
    Outlaw d(2,2);
    ASSERT_TRUE(d.gettype() == 1 && d.get_x_value() == 2 && d.get_y_value() == 2);
}

TEST(Outlaw_class_tests, accept_method_1) {
    std::shared_ptr<NPC> defender = std::make_shared<Outlaw>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Orc>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<OrcVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(Outlaw_class_tests, accept_method_2) {
    std::shared_ptr<NPC> defender = std::make_shared<Outlaw>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Werewolf>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<WerewolfVisitor>();
    ASSERT_TRUE(defender->accept(visitor_ptr, attacker));
}

TEST(Outlaw_class_tests, accept_method_3) {
    std::shared_ptr<NPC> defender = std::make_shared<Outlaw>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<OutlawVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Orc_tests, orc_visitor_test_1) {
    OrcVisitor visitor;
    std::shared_ptr<Werewolf> ptr = std::make_shared<Werewolf>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Orc_tests, orc_visitor_test_2) {
    OrcVisitor visitor;
    std::shared_ptr<Outlaw> ptr = std::make_shared<Outlaw>();
    ASSERT_TRUE(visitor.visit(ptr));
}

TEST(Orc_tests, orc_visitor_test_3) {
    OrcVisitor visitor;
    std::shared_ptr<Orc> ptr = std::make_shared<Orc>();
    ASSERT_FALSE(visitor.visit(ptr));
}

TEST(Orc_class_tests, default_constructor_and_destructor) {
    Orc o;
    o.~Orc();
}

TEST(Orc_class_tests, int_constructor) {
    Orc o(2,2);
    ASSERT_TRUE(o.gettype() == 2 && o.get_x_value() == 2 && o.get_y_value() == 2); 
}

TEST(Orc_class_tests, accept_method_1) {
    std::shared_ptr<NPC> defender = std::make_shared<Orc>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Werewolf>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<WerewolfVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Orc_class_tests, accept_method_2) {
    std::shared_ptr<NPC> defender = std::make_shared<Orc>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Outlaw>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<OutlawVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Orc_class_tests, accept_method_3) {
    std::shared_ptr<NPC> defender = std::make_shared<Orc>(2,2);
    std::shared_ptr<NPC> attacker = std::make_shared<Orc>(3,3);
    std::shared_ptr<FightVisitor> visitor_ptr = std::make_shared<OrcVisitor>();
    ASSERT_FALSE(defender->accept(visitor_ptr, attacker));
}

TEST(Factory_tests, create_1) {
    std::shared_ptr<NPC> ptr = Factory::Create(WerewolfType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 0 && ptr->get_x_value() == 1 && ptr->get_y_value() == 1);
}

TEST(Factory_tests, create_2) {
    std::shared_ptr<NPC> ptr = Factory::Create(OrcType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 2 && ptr->get_x_value() == 1 && ptr->get_y_value() == 1);
}

TEST(Factory_tests, create_3) {
    std::shared_ptr<NPC> ptr = Factory::Create(OutlawType, 1, 1);
    ASSERT_TRUE(ptr->gettype() == 1 && ptr->get_x_value() == 1 && ptr->get_y_value() == 1);
}

TEST(Factory_tests, create_throw) {
    std::shared_ptr<NPC> ptr;
    ASSERT_ANY_THROW(ptr = Factory::Create(NpcType(534), 2, 2));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}