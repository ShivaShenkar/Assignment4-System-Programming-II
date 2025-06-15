#pragma once
#include <vector>
#include <algorithm>
using std::vector;
namespace ariel{
    template <typename T>
    class Iterator{
        protected:
            vector<T> dataVec;
            int ind;



        public:
            Iterator(vector<T> vec) : ind(0),dataVec(vec){}
            Iterator(vector<T> vec,int index):ind(index),dataVec(vec){}
            Iterator<T>& begin(){
                return Iterator<T>(dataVec);
            }
            Iterator<T>& end(){
                return Iterator<T>(dataVec, dataVec.size()-1);
            }
            T operator*(){return dataVec[ind];}
            Iterator<T>& operator++(int){
                if(ind<dataVec.size()){
                    ind++;
                    return *this;
                }
            }
            Iterator<T>& operator++(){
                if(ind<dataVec.size()){
                    ++ind;
                    return *this;
                }
            }
            Iterator<T>& operator--(){
                if(ind>0){
                    ind--;
                    return *this;
                }
            }
            bool operator==(Iterator<T> other){
                return this->ind==other.ind;
            }
            bool operator!=(Iterator<T> other){
                return this->ind!=other.ind;
            }
            int size() const{
                return dataVec.size();
            }

        
    };
    template <typename T>
    class AscendingOrder : public Iterator<T>{
        public:
            AscendingOrder(vector<T> vec):ariel::Iterator<T>(vec){
                std::sort(this->dataVec.begin(),this->dataVec.end());
            }
            AscendingOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                std::sort(this->dataVec.begin(),this->dataVec.end());
            }

    };
    template <typename T>
    class DescendingOrder : public Iterator<T>{
        public:
            DescendingOrder(vector<T> vec):Iterator<T>(vec){
                std::sort(this->dataVec.begin(),this->dataVec.end(),std::greater<>());
            }
            DescendingOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                std::sort(this->dataVec.begin(),this->dataVec.end(),std::greater<>());
            }
    };
    template <typename T>
    class SideCrossOrder : public Iterator<T>{
        public:
            SideCrossOrder(vector<T> vec):Iterator<T>(vec){
                setVector();
            }
            SideCrossOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                setVector();
            }
            void setVector(){
                vector<T> res;
                AscendingOrder<T> i1(this->dataVec);DescendingOrder<T> i2(this->dataVec);
                for(int i=0;i<this->dataVec.size()/2;i++){
                    res.push_back(*i1);
                    res.push_back(*i2);
                    i1++;
                    i2++;
                }
                if(this->dataVec.size()%2==1)
                    res.push_back(this->dataVec[this->dataVec.size()/2]);
                this->dataVec = res;
            }

    };
    template <typename T>
    class ReverseOrder : public Iterator<T>{
        public:
            ReverseOrder(vector<T> vec):Iterator<T>(vec){
                std::reverse(this->dataVec.begin(),this->dataVec.end());
            }
            ReverseOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                std::reverse(this->dataVec.begin(),this->dataVec.end());
            }
            
    };
    template <typename T>
    class Order : public Iterator<T>{
        public:
            Order(vector<T> vec):Iterator<T>(vec){}
            Order(vector<T> vec,int index):Iterator<T>(vec,index){}
            
    };
    template <typename T>
    class MiddleOutOrder : public Iterator<T>{
        public:
            MiddleOutOrder(vector<T> vec):Iterator<T>(vec){
                setVector();
            }
            MiddleOutOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                setVector();
            }
            void setVector(){
                vector<T> vec = this->dataVec;
                int count=1;
                vector<T> res;
                res.push_back(vec[vec.size()/2]);
                for(int i=0;i<vec.size()/2;i++){
                    res.push_back(vec[vec.size()/2-count]);
                    res.push_back(vec[vec.size()/2+count]);
                    count++;
                }
                this->dataVec = res;
            }
    };
}