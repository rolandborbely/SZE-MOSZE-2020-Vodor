#include "../Unit.h"
#include <gtest/gtest.h>

TEST(parserTest, test_iostream){
    Parser p;
    std::map<std::string, std::string> outputMap; 
    std::map<std::string, std::string> expectedMap{
        {"name", "Hunkrow"},
        {"hp", "200"},
        {"dmg", "11"}};                       
    std::ifstream jsonFile;
    jsonFile.open("test/units/unit1.json");
    outputMap = p.parseJson(jsonFile);
    jsonFile.close();
    for (auto e : expectedMap){
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(parserTest, test_filename){
    Parser p;
    std::map<std::string, std::string> outputMap; 
    std::map<std::string, std::string> expectedMap{
        {"name", "Kakazhom"},
        {"hp", "150"},
        {"dmg", "15"}};                       
    std::string fname = "test/units/unit2.json";
    outputMap = p.parseJson(fname);

    for (auto e : expectedMap){
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(parserTest, test_string){
    Parser p;
    std::map<std::string, std::string> outputMap; 
    std::map<std::string, std::string> expectedMap{
        {"name", "Maytcreme"},
        {"hp", "300"},
        {"dmg", "5"}};             
              
    std::string fname = "test/units/unit3.json";
    std::ifstream jsonFile;
    jsonFile.open(fname);
    std::string line;
    std::string jsonToString = "";

    while(getline(jsonFile,line))
        jsonToString += line;

    jsonFile.close();
    outputMap = p.parseJson(jsonToString);

    for (auto e : expectedMap){
        ASSERT_EQ(outputMap[e.first],e.second);
    }
}

TEST(unittests, good_battle_end){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");
    Unit* u2 = Unit::parseUnit("test/units/unit2.json");

    ASSERT_EQ(u1->fight(u2)->getName(),"Kakazhom");
}

TEST(unittests,good_levelup){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");
    Unit* u2 = Unit::parseUnit("test/units/unit2.json");

    ASSERT_EQ(u1->fight(u2)->getLevel(),3);
   
}

TEST(unittests, name_check){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");

    ASSERT_EQ(u1->getName(),"Hunkrow");

}

TEST(unittests, hp_check){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");

    ASSERT_EQ(u1->getHp(),200);

}

TEST(unittests, parsunit_test){
    ASSERT_NO_THROW(Parser::parseJson("test/units/unit1.json"));
}

TEST(unittests, whitespaceTest){
    std::map<std::string, std::string> expectedMap{
        {"name", "Teszt"},
        {"hp", "12"},
        {"dmg", "20"}}; 
    
    std::map<std::string, std::string> outputMap = Parser::parseJson("test/muchWhitespace.json");

    for (auto e : expectedMap)
        ASSERT_EQ(outputMap[e.first], e.second);
}

TEST(unittests, missingKeys){
    ASSERT_THROW(Unit::parseUnit("test/missingKeys.json"), std::string);
}

TEST(unittests, mixedupAttributes){
    ASSERT_NO_THROW(Unit::parseUnit("test/mixedupKeys.json"));    
}

TEST(unittests, brokenFile){
    ASSERT_THROW(Parser::parseJson("test/brokenFile.json"), std::string);
}

TEST(unittests, parseUnitTest){
    ASSERT_NO_THROW(Unit::parseUnit("test/units/unit1.json"));
    ASSERT_NO_THROW(Unit::parseUnit("test/units/unit2.json"));
}

TEST(unittests, fightTest){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");
    Unit* u2 = Unit::parseUnit("test/units/unit2.json");

    ASSERT_EQ(u1->fight(u2)->getName(),"Kakazhom");
}

TEST(unittests, levelUpTest){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");
    Unit* u2 = Unit::parseUnit("test/units/unit3.json");

    ASSERT_EQ(u1->fight(u2)->getLevel(), 4);
}

TEST(unittests, wrongPathTaken){
    ASSERT_THROW(Unit::parseUnit("test/thisfiledoesnotexist.json"), std::string);
}

TEST(unittests, parseUnitTest2){
    Unit* u1 = Unit::parseUnit("test/units/unit1.json");
    ASSERT_EQ(u1->getName(), "Hunkrow");
    ASSERT_EQ(u1->getHp(), 200);
    ASSERT_EQ(u1->getDmg(), 11);
    ASSERT_DOUBLE_EQ(u1->getAcd(), 12.123);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}