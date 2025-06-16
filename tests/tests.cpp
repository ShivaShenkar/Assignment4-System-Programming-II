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
            CHECK_EQ(mcSCOrder.get(i),res1[i/2]);
        else
            CHECK_EQ(mcSCOrder.get(i),res[i/2]);
    }


    MyContainer<string> mcMidOutOrder;
    for(auto i=mcString.begin_middle_out_order();i!=mcString.end_middle_out_order();++i){
        mcMidOutOrder.addElement(*i);
    }
    vector<string> res2 ={"gamma","baba","sigma","zaza","echo","zuzu","delta","abba"};
    for(int i=0;i<mcString.size();i++){
        CHECK_EQ(mcMidOutOrder.get(i),res2[i]);
    }
}

TEST_CASE("char Iterators"){
    MyContainer<char> mcChar;
    mcChar.addElement('a');
    mcChar.addElement('q');
    mcChar.addElement('f');
    mcChar.addElement(0);
    mcChar.addElement(4);
    mcChar.addElement('0');
    mcChar.addElement('!');
    mcChar.addElement('?');

    vector<char> charVec = {'a','q','f',0,4,'0','!','?'};

    MyContainer<char> mcOrder;
    for(auto i=mcChar.begin_order();i!=mcChar.end_order();++i){
        mcOrder.addElement(*i);
    }
    for(int i=0;i<mcChar.size();i++){
        CHECK_EQ(mcOrder.get(i),mcChar.get(i));
    }
    

    MyContainer<char> mcRevOrder;
    for(auto i=mcChar.begin_reverse_order();i!=mcChar.end_reverse_order();++i){
        mcRevOrder.addElement(*i);
    }
    for(int i=0;i<mcChar.size();i++){
        CHECK_EQ(mcRevOrder.get(i),mcChar.get(mcOrder.size()-1-i));
    }


    MyContainer<char> mcAscOrder;
    for(auto i=mcChar.begin_ascending_order();i!=mcChar.end_ascending_order();++i){
        mcAscOrder.addElement(*i);
    }
    std::sort(charVec.begin(),charVec.end());

    for(int i=0;i<mcChar.size();i++){
        CHECK_EQ(mcAscOrder.get(i),charVec[i]);
    }


    MyContainer<char> mcDescOrder;
    for(auto i=mcChar.begin_descending_order();i!=mcChar.end_descending_order();++i){
        mcDescOrder.addElement(*i);
    }
    std::reverse(charVec.begin(),charVec.end());
    for(int i=0;i<mcChar.size();i++){
        CHECK_EQ(mcDescOrder.get(i),charVec[i]);
    }

    MyContainer<char> mcSCOrder;
    for(auto i=mcChar.begin_side_cross_order();i!=mcChar.end_side_cross_order();++i){
        mcSCOrder.addElement(*i);
    }

    vector<char> charVec2(charVec.rbegin(),charVec.rend());
    for(int i=0;i<mcChar.size();i++){
        if(i%2==0)
            CHECK_EQ(mcSCOrder.get(i),charVec2[i/2]);
        else
            CHECK_EQ(mcSCOrder.get(i),charVec[i/2]);
    }


    MyContainer<char> mcMidOutOrder;
    for(auto i=mcChar.begin_middle_out_order();i!=mcChar.end_middle_out_order();++i){
        mcMidOutOrder.addElement(*i);
    }
    vector<char> charVec3 ={4,0,'0','f','!','q','?','a'};
    for(int i=0;i<mcChar.size();i++){
        CHECK_EQ(mcMidOutOrder.get(i),charVec3[i]);
    }
}
TEST_CASE("double Iterators"){
    MyContainer<double> mcDouble;
    mcDouble.addElement(9.3);
    mcDouble.addElement(3.14);
    mcDouble.addElement(2.98);
    mcDouble.addElement(10.10);
    mcDouble.addElement(100);
    mcDouble.addElement(1);
    mcDouble.addElement(88.7010510);
    mcDouble.addElement(10000.23456789);


    MyContainer<double> mcOrder;
    for(auto i=mcDouble.begin_order();i!=mcDouble.end_order();++i){
        mcOrder.addElement(*i);
    }
    for(int i=0;i<mcDouble.size();i++){
        CHECK_EQ(mcOrder.get(i),mcDouble.get(i));
    }
    

    MyContainer<double> mcRevOrder;
    for(auto i=mcDouble.begin_reverse_order();i!=mcDouble.end_reverse_order();++i){
        mcRevOrder.addElement(*i);
    }
    for(int i=0;i<mcDouble.size();i++){
        CHECK_EQ(mcRevOrder.get(i),mcDouble.get(mcOrder.size()-1-i));
    }


    MyContainer<double> mcAscOrder;
    for(auto i=mcDouble.begin_ascending_order();i!=mcDouble.end_ascending_order();++i){
        mcAscOrder.addElement(*i);
    }
    vector<double> vec1Double = {1,2.98,3.14,9.3,10.10,88.7010510,100,10000.23456789};

    for(int i=0;i<mcDouble.size();i++){
        CHECK_EQ(mcAscOrder.get(i),vec1Double[i]);
    }


    MyContainer<double> mcDescOrder;
    for(auto i=mcDouble.begin_descending_order();i!=mcDouble.end_descending_order();++i){
        mcDescOrder.addElement(*i);
    }
    std::reverse(vec1Double.begin(),vec1Double.end());
    for(int i=0;i<mcDouble.size();i++){
        CHECK_EQ(mcDescOrder.get(i),vec1Double[i]);
    }

    MyContainer<double> mcSCOrder;
    for(auto i=mcDouble.begin_side_cross_order();i!=mcDouble.end_side_cross_order();++i){
        mcSCOrder.addElement(*i);
    }

    vector<double> vec2Double(vec1Double.rbegin(),vec1Double.rend());
    for(int i=0;i<mcDouble.size();i++){
        if(i%2==0)
            CHECK_EQ(mcSCOrder.get(i),vec2Double[i/2]);
        else
            CHECK_EQ(mcSCOrder.get(i),vec1Double[i/2]);
    }


    MyContainer<double> mcMidOutOrder;
    for(auto i=mcDouble.begin_middle_out_order();i!=mcDouble.end_middle_out_order();++i){
        mcMidOutOrder.addElement(*i);
    }
    vector<double> vec3Double ={100,10.10,1,2.98,88.7010510,3.14,10000.23456789,9.3};
    for(int i=0;i<mcDouble.size();i++){
        CHECK_EQ(mcMidOutOrder.get(i),vec3Double[i]);
    }
}