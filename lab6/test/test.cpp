#include <gtest/gtest.h>

#include "../include/battle.h"
#include "../include/factory.h"

TEST(test_01, Werewolf)
{

    bool test = true;
    try
    {
        Werewolf(getRandNameWerewolf(), 17, 17);
    }
    catch (std::range_error &ex)
    {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}

TEST(test_02, OutlawConstructorTest)
{

    bool test = true;
    try
    {
        Outlaw(getRandNameOutlaw(), 17, 17);
    }
    catch (std::range_error &ex)
    {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}

TEST(test_03, OrkConstructorTest)
{

    bool test = true;
    try
    {
        Ork(getRandNameOrk(), 17, 17);
    }
    catch (std::range_error &ex)
    {
        std::cerr << " new throw exception:" << ex.what() << std::endl;
        test = false;
    }

    ASSERT_TRUE(test);
}

TEST(test_04, CloseTest)
{

    Werewolf a(getRandNameWerewolf(), 1, 1);

    std::shared_ptr<Heroes> f = std::shared_ptr<Heroes>(new Werewolf(getRandNameWerewolf(), 99, 0));

    ASSERT_TRUE(a.isClose(f));
}

TEST(test_05, NoDeathFighterTest)
{

    set_t array;

    Factory factor;

    array.insert(factor.createHero(WEREWOLF, 0, 0));
    array.insert(factor.createHero(OUTLAW, 100, 100));
    array.insert(factor.createHero(ORK, 200, 200));

    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_06, DeathFighterTest)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(WEREWOLF, 0, 0));
    array.insert(factor.createHero(OUTLAW, 0, 100));
    array.insert(factor.createHero(ORK, 1, 99));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

TEST(test_07, Werewolf)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(WEREWOLF, 0, 0));
    array.insert(factor.createHero(WEREWOLF, 0, 1));
    array.insert(factor.createHero(WEREWOLF, 0, 2));

    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_08, Outlaw)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(OUTLAW, 0, 0));
    array.insert(factor.createHero(OUTLAW, 0, 1));
    array.insert(factor.createHero(OUTLAW, 0, 2));

    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_09, OrkFightTest)
{
    set_t array;

    Factory factor;

    array.insert(factor.createHero(ORK, 0, 0));
    array.insert(factor.createHero(ORK, 0, 1));
    array.insert(factor.createHero(ORK, 0, 2));

    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_10, WerewolfWithOutlawFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(WEREWOLF, 10, 10));
    array.insert(factor.createHero(OUTLAW, 0, 0));
    array.insert(factor.createHero(OUTLAW, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_FALSE(result);
}

TEST(test_11, WerewolfWithOrkFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(WEREWOLF, 10, 10));
    array.insert(factor.createHero(ORK, 0, 0));
    array.insert(factor.createHero(ORK, 100, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 0);

    EXPECT_TRUE(result);
}

TEST(test_12, OrkWithOutlawFightTest)
{
    set_t array;

    Factory factor;
    array.insert(factor.createHero(ORK, 10, 10));
    array.insert(factor.createHero(OUTLAW, 0, 0));
    array.insert(factor.createHero(OUTLAW, 10, 0));

    set_t dead = battle(array);

    bool result = (dead.size() == 2);

    EXPECT_TRUE(result);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
