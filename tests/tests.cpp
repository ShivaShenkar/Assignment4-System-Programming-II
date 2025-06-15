#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include <vector>
#include "doctest.h"
#include "../include/MyContainer.hpp"
using std::vector;
using std::string;
using namespace ariel;
class Person{
    public:
    int age;
    bool sex;
    string name;
    Person(string name,int age,bool sex):name(name),age(age),sex(sex){}
    bool operator<(Person& p){
        return age<p.age;
    }
};
TEST_CASE("Strings Iterators"){
    vector<string> vec1 = {"abba", "","","","zulu","alpha","","golf","","",""};
    MyContainer<string> mcString;
    mcString.addElement("abba");
    mcString.addElement("zuzu");
    mcString.addElement("zaza");
    mcString.addElement("baba");
    mcString.addElement("gamma");
    mcString.addElement("sigma");
    mcString.addElement("echo");
    mcString.addElement("delta");


    MyContainer<string> mcOrder;
    for(auto i=mcString.begin_order();i!=mcString.end_order();++i){
        mcOrder.addElement(*i);
    }
    for(int i=0;i<mcString.size();i++){
        CHECK_EQ(mcOrder.get(i),mcString.get(i));
    }
    

    MyContainer<string> mcRevOrder;
    for(auto i=mcString.begin_reverse_order();i!=mcString.end_reverse_order();++i){
        mcRevOrder.addElement(*i);
    }
    for(int i=0;i<mcString.size();i++){
        CHECK_EQ(mcRevOrder.get(i),mcString.get(mcOrder.size()-1-i));
    }


    MyContainer<string> mcAscOrder;
    for(auto i=mcString.begin_ascending_order();i!=mcString.end_ascending_order();++i){
        mcAscOrder.addElement(*i);
    }
    vector<string> res = {"abba","baba","delta","echo","gamma","sigma","zaza","zuzu"};

    for(int i=0;i<mcString.size();i++){
        CHECK_EQ(mcAscOrder.get(i),res[i]);
    }


    MyContainer<string> mcDescOrder;
    for(auto i=mcString.begin_descending_order();i!=mcString.end_descending_order();++i){
        mcDescOrder.addElement(*i);
    }
    std::reverse(res.begin(),res.end());
    for(int i=0;i<mcString.size();i++){
        CHECK_EQ(mcDescOrder.get(i),res[i]);
    }

    MyContainer<string> mcSCOrder;
    for(auto i=mcString.begin_side_cross_order();i!=mcString.end_side_cross_order();++i){
        mcSCOrder.addElement(*i);
    }
    vector<string> res1(res.rbegin(),res.rend());


    for(int i=0;i<mcString.size();i++){
        if(i%2==0)
            CHECK_EQ(mcSCOrder.get(i),res1[i]);
        else
            CHECK_EQ(mcSCOrder.get(i),res[i]);
    }

    MyContainer<string> mcMidOutOrder;
    for(auto i=mcString.begin_middle_out_order();i!=mcString.end_middle_out_order();++i){
        mcMidOutOrder.addElement(*i);
    }
    vector<string> res2 ={"gamma","echo","sigma","delta","zaza","baba","zuzu","abba"};
    for(int i=0;i<mcString.size();i++){
        CHECK_EQ(mcMidOutOrder.get(i),res2[i]);
    }
}