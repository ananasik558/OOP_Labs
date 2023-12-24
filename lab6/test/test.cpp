#include <gtest/gtest.h>
#include "../include/declaration.h"
#include "../include/npc.h"
#include "../include/Dragon.h"
#include "../include/Elf.h"
#include "../include/Druid.h"
#include "../include/factory.h"
#include "../include/fight.h"
#include "../include/observConsole.h"
#include "../include/observFile.h"

TEST(Test_Dragon, Constr)
{
    std::string name = "asd";
    Dragon Dragon{name, 1, 1};
    EXPECT_TRUE(Dragon.getName() == name && Dragon.getType() == "DragonType");
}

TEST(Test_Dragon, FightDragon)
{
    std::string name = "asd";
    Dragon Dragon1(name, 1, 1);
    Dragon Dragon2(name, 1, 2);
    EXPECT_TRUE(Dragon1.accept(Dragon2) == false && Dragon2.accept(Dragon1) == false);
}

TEST(Test_Dragon, FightElf)
{
    std::string name = "asd";
    Dragon Dragon{name, 1, 1};
    Elf Elf{name, 1, 2};
    EXPECT_TRUE(Elf.accept(Dragon) == true);
}

TEST(Test_Dragon, FightDruid)
{
    std::string name = "asd";
    Dragon Dragon{name, 1, 1};
    Druid Druid{name, 1, 2};
    EXPECT_TRUE(Druid.accept(Dragon) == false);
}

TEST(Test_Elf, Constr)
{
    std::string name = "asd";
    Elf Elf{name, 1, 1};
    EXPECT_TRUE(Elf.getName() == name && Elf.getType() == "ElfType");
}

TEST(Test_Elf, FightElf)
{
    std::string name = "asd";
    Elf Elf1{name, 1, 1};
    Elf Elf2{name, 1, 2};
    EXPECT_TRUE(Elf1.accept(Elf2) == false && Elf2.accept(Elf1) == false);
}

TEST(Test_Elf, FightDragon)
{
    std::string name = "asd";
    Elf Elf{name, 1, 1};
    Dragon Dragon{name, 1, 2};
    EXPECT_TRUE(Dragon.accept(Elf) == false);
}

TEST(Test_Elf, FightDruid)
{
    std::string name = "asd";
    Elf Elf{name, 1, 1};
    Druid Druid{name, 1, 2};
    EXPECT_TRUE(Druid.accept(Elf) == true);
}

TEST(Test_Druid, Constr)
{
    std::string name = "asd";
    Druid Druid{name, 1, 1};
    EXPECT_TRUE(Druid.getName() == name && Druid.getType() == "DruidType");
}

TEST(Test_Druid, FightDruid)
{
    std::string name = "asd";
    Druid Druid1{name, 1, 1};
    Druid Druid2{name, 1, 2};
    EXPECT_TRUE(Druid1.accept(Druid2) == false && Druid2.accept(Druid1) == false);
}

TEST(Test_Druid, FightDragon)
{
    std::string name = "asd";
    Druid Druid{name, 1, 1};
    Dragon Dragon{name, 1, 2};
    EXPECT_TRUE(Dragon.accept(Druid) == true);
}

TEST(Test_Druid, FightElf)
{
    std::string name = "asd";
    Druid Druid{name, 1, 1};
    Elf Elf{name, 1, 2};
    EXPECT_TRUE(Elf.accept(Druid) == false);
}

TEST(Test_NPC, Distance)
{
    std::string name = "asd";
    Druid Druid1{name, 1, 1};
    Druid Druid2{name, 4, 5};
    float distance = 5.0;
    EXPECT_TRUE(Druid1.distance(Druid2) == distance);
}

TEST(Test_NPC, InsertObservers)
{
    std::string name = "asd";
    Druid Druid{name, 1, 1};
    ObserverConsole observer;
    Druid.subscribe(std::make_shared<ObserverConsole>(observer));
    EXPECT_TRUE(Druid.countObservers() == 1);
}

TEST(Test_NPC, EraseObservers)
{
    std::string name = "asd";
    Druid Druid{name, 1, 1};
    ObserverFile observer;
    std::shared_ptr observer1 = std::make_shared<ObserverFile>(observer);
    Druid.subscribe(observer1);
    Druid.unsubscribe(observer1);
    EXPECT_TRUE(Druid.countObservers() == 0);
}

TEST(Test_NPC, Print)
{
    std::string name = "asd";
    Druid Druid{name, 1, 1};

    std::ostringstream coutstream;
    std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

    std::cout << Druid;

    std::cout.rdbuf(coutbuf);

    std::string s = "Type : DruidType, name : asd, x : 1, y : 1\n";

    EXPECT_TRUE(s == coutstream.str());
}

TEST(Test_NPC, Notify)
{
    std::string name = "asd";
    Dragon Dragon{name, 1, 1};
    Elf Elf{name, 1, 1};
    ObserverConsole observer;
    Dragon.subscribe(std::make_shared<ObserverConsole>(observer));
    Elf.subscribe(std::make_shared<ObserverConsole>(observer));
    std::ostringstream coutstream;
    std::streambuf *coutbuf = std::cout.rdbuf(coutstream.rdbuf());

    Elf.accept(Dragon);

    std::cout.rdbuf(coutbuf);

    std::string s = "DragonType asd убил ElfType asd\n";
    std::cout << coutstream.str();
    EXPECT_TRUE(s == coutstream.str());
}

TEST(Test_Factory, CreateNPC)
{
    std::string name = "asd";
    std::shared_ptr<NPC> obj = factory(NpcType(1), name, 1, 1);
    EXPECT_TRUE(obj->getName() == name && obj->getType() == "DragonType");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
