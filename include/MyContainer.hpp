//fikhman2005@gmail.com
#pragma once
#define INITIAL_CAPACITY 10
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Iterators.hpp"
using std::vector;
namespace ariel{
    //MyContainer<T> template class
    template <typename T>
    class MyContainer{
        private:
        //the items in the container are stored in a vector
        vector<T> items;
        public:
        //const function for container's size
        int size() const{
            return items.size();
        }
        //get function returns the item with the appropriate index
        T get(int index) const{
            if(index<0||index>=size())
                throw std::out_of_range("index out of bounds");
            return items[index];
        }
        //function adds element to the container
        void addElement(T item){
            items.push_back(item);
        }
        //function removes element to the container
        void removeElement(T item){
            for(int i=0;i<this->size();++i){
                if(items[i]==item){
                    items.erase(items.begin()+i);
                }
            }
        }

        //firend operator function for printing the conatiner
        //this function allows to print the container as is without the need of assisting functions
        friend std::ostream& operator<<(std::ostream& os,MyContainer<T> mc){
            os<<"( ";
            for(int i=0;i<mc.size();++i) os<<""<<mc.get(i)<<" ";
            os<<")"<<std::endl;
            return os;
        }
        //begin function of AscendingOrder Iterator
        AscendingOrder<T> begin_ascending_order(){
            AscendingOrder<T> ao(items);
            return ao;
        }
        //end function of AscendingOrder Iterator
        AscendingOrder<T> end_ascending_order(){
            AscendingOrder<T> ao(items,items.size());
            return ao;
        }
        //begin function of DescendingOrder Iterator
        DescendingOrder<T> begin_descending_order(){
            DescendingOrder<T> dOrd(items);
            return dOrd;
        }
        //end function of DescendingOrder Iterator
        DescendingOrder<T> end_descending_order(){
            DescendingOrder<T> dOrd(items,items.size());
            return dOrd;
        }
        //begin function of SideCrossOrder Iterator
        SideCrossOrder<T> begin_side_cross_order(){
            SideCrossOrder<T> sco(items);
            return sco;
        }
        //end function of SideCrossOrder Iterator
        SideCrossOrder<T> end_side_cross_order(){
            SideCrossOrder<T> sco(items,items.size());
            return sco;
        }
        //begin function of ReverseOrder Iterator
        ReverseOrder<T> begin_reverse_order(){
            ReverseOrder<T> ro(items);
            return ro;
        }
        //end function of ReverseOrder Iterator
        ReverseOrder<T> end_reverse_order(){
            ReverseOrder<T> ro(items,items.size());
            return ro;
        }
        //begin function of Order Iterator
        Order<T> begin_order(){
            Order<T> ord(items);
            return ord;
        }
        //end function of Order Iterator
        Order<T> end_order(){
            Order<T> ord(items,items.size());
            return ord;
        }
        //begin function of MiddleOutOrder Iterator
        MiddleOutOrder<T> begin_middle_out_order(){
            MiddleOutOrder<T> moo(items);
            return moo;
        }
        //end function of MiddleOutOrder Iterator
        MiddleOutOrder<T> end_middle_out_order(){
            MiddleOutOrder<T> moo(items,items.size());
            return moo;
        }
        
    };
}