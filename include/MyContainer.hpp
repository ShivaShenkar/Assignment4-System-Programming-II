#pragma once
#define INITIAL_CAPACITY 10
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Iterators.hpp"
using std::vector;
namespace ariel{
    template <typename T>
    class MyContainer{
        private:
        vector<T> items;
        public:
        T get(int index) const{
            return items[index];
        }
        void addElement(T item){
            items.push_back(item);
        }
        void removeElement(T item){
            for(int i=0;i<this->size();++i){
                if(items[i]==item){
                    items.erase(items.begin()+i);
                }
            }
        }
        int size() const{
            return items.size();
        }
        
        friend std::ostream& operator<<(std::ostream& os,MyContainer<T> mc){
            os<<"( ";
            for(int i=0;i<mc.size();++i) os<<""<<mc.get(i)<<" ";
            os<<")"<<std::endl;
        }
        AscendingOrder<T> begin_ascending_order(){
            AscendingOrder<T> ao(items);
            return ao;
        }
        AscendingOrder<T> end_ascending_order(){
            AscendingOrder<T> ao(items,items.size());
            return ao;
        }
        DescendingOrder<T> begin_descending_order(){
            DescendingOrder<T> dOrd(items);
            return dOrd;
        }
        DescendingOrder<T> end_descending_order(){
            DescendingOrder<T> dOrd(items,items.size());
            return dOrd;
        }
        SideCrossOrder<T> begin_side_cross_order(){
            SideCrossOrder<T> sco(items);
            return sco;
        }
        SideCrossOrder<T> end_side_cross_order(){
            SideCrossOrder<T> sco(items,items.size());
            return sco;
        }

        ReverseOrder<T> begin_reverse_order(){
            ReverseOrder<T> ro(items);
            return ro;
        }
        ReverseOrder<T> end_reverse_order(){
            ReverseOrder<T> ro(items,items.size());
            return ro;
        }
        Order<T> begin_order(){
            Order<T> ord(items);
            return ord;
        }
        Order<T> end_order(){
            Order<T> ord(items,items.size());
            return ord;
        }
        MiddleOutOrder<T> begin_middle_out_order(){
            MiddleOutOrder<T> moo(items);
            return moo;
        }
        MiddleOutOrder<T> end_middle_out_order(){
            MiddleOutOrder<T> moo(items,items.size());
            return moo;
        }



    };
}