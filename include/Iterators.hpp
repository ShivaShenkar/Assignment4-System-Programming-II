//fikhman2005@gmail.com
#pragma once
#include <vector>
#include <algorithm>
using std::vector;
namespace ariel{
    //class of Iterator with template 
    template <typename T>
    class Iterator{
        protected:
            //Each Itearator instance has a vector that stores the data of the Iterator
            //and the current index of the Iterator
            vector<T> dataVec;
            int ind;
        public:
            //constructor of Iterator<T> needs a vector<T> as an argument
            //if no index added the Iterator will point to the beginning of the vector
            Iterator(vector<T> vec) : ind(0),dataVec(vec){}
            Iterator(vector<T> vec,int index):ind(index),dataVec(vec){}

            //creates an instance of Iterator pointing at the beginning of the container.
            Iterator<T>& begin(){
                return Iterator<T>(dataVec);
            }
            //creates an instance of Iterator pointing at the end of the container.
            Iterator<T>& end(){
                return Iterator<T>(dataVec, dataVec.size()-1);
            }
            //dereference operator for Iterator, returns the value of the object currently
            //pointed at through the Iterator
            T operator*(){return dataVec[ind];}

            //post-increment operator, the Iterator will point to the next value (if hasn't reached the bounds)
            // of the container,the function doesn't make a new instance rather implementing the change on the current Iterator
            Iterator<T>& operator++(int){
                if(ind<dataVec.size()){
                    ind++;
                    return *this;
                }
            }
            
            //pre-increment operator, the Iterator will point to the next value (if hasn't reached the bounds)
            // of the container,the function doesn't make a new instance rather implementing the change on the current Iterator
            Iterator<T>& operator++(){
                if(ind<dataVec.size()){
                    ++ind;
                    return *this;
                }
            }
            
            //pre-decrement operator, the Iterator will point to the next value (if hasn't reached the bounds)
            // of the container,the function doesn't make a new instance rather implementing the change on the current Iterator
            Iterator<T>& operator--(){
                if(ind>0){
                    ind--;
                    return *this;
                }
            }
            //Comparison operator - equal
            bool operator==(Iterator<T> other){
                return this->ind==other.ind;
            }
            //Comparison operator - not equal
            bool operator!=(Iterator<T> other){
                return this->ind!=other.ind;
            }
            //const function for size
            int size() const{
                return dataVec.size();
            }

        
    };
    //AscendinOrder Iterator, inherits from Iterator and stores the data as sorted in an ascending order
    template <typename T>
    class AscendingOrder : public Iterator<T>{
        public:
            //constructors with/without index, like Iterator
            //constructor include sort function from stl lib
            AscendingOrder(vector<T> vec):ariel::Iterator<T>(vec){
                std::sort(this->dataVec.begin(),this->dataVec.end());
            }
            AscendingOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                std::sort(this->dataVec.begin(),this->dataVec.end());
            }

    };
    //DescendingOrder Iterator, inherits from Iterator and stores the data as sorted in a descending order
    template <typename T>
    class DescendingOrder : public Iterator<T>{
        public:
            //constructors with/without index, like Iterator
            //constructor include sort function from stl lib with greater functor
            DescendingOrder(vector<T> vec):Iterator<T>(vec){
                std::sort(this->dataVec.begin(),this->dataVec.end(),std::greater<>());
            }
            DescendingOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                std::sort(this->dataVec.begin(),this->dataVec.end(),std::greater<>());
            }
    };
    //SideCrossOrder Iterator, inherits from Iterator and stores the data as sorted in a side-cross order
    template <typename T>
    class SideCrossOrder : public Iterator<T>{
        public:
            //constructors with/without index, like Iterator
            SideCrossOrder(vector<T> vec):Iterator<T>(vec){
                setVector();
            }
            SideCrossOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                setVector();
            }
            //function sets the the Iterator's data vector to be side-cross ordered
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
    //ReverseOrder Iterator, inherits from Iterator and stores the data as sorted in a reverse order from original
    template <typename T>
    class ReverseOrder : public Iterator<T>{
        public:
            //constructors with/without index, like Iterator
            //constructor include reverse function from stl lib
            ReverseOrder(vector<T> vec):Iterator<T>(vec){
                std::reverse(this->dataVec.begin(),this->dataVec.end());
            }
            ReverseOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                std::reverse(this->dataVec.begin(),this->dataVec.end());
            }
            
    };
    //Order Iterator, inherits from Iterator and stores the data without change
    template <typename T>
    class Order : public Iterator<T>{
        public:
            //constructors with/without index, like Iterator
            Order(vector<T> vec):Iterator<T>(vec){}
            Order(vector<T> vec,int index):Iterator<T>(vec,index){}
            
    };
    template <typename T>
    //MiddleOutOrder Iterator, inherits from Iterator and stores the data as sorted in a middle-out order
    class MiddleOutOrder : public Iterator<T>{
        public:
        //constructors with/without index, like Iterator
            MiddleOutOrder(vector<T> vec):Iterator<T>(vec){
                setVector();
            }
            MiddleOutOrder(vector<T> vec,int index):Iterator<T>(vec,index){
                setVector();
            }

            //function sets the the Iterator's data vector to be middle-out ordered
            void setVector(){
                vector<T> vec = this->dataVec;
                int count=1;
                vector<T> res;
                if(vec.size()>0)
                    res.push_back(vec[vec.size()/2]);
                for(int i=0;i<vec.size()/2;i++){
                    if(vec.size()/2-count>=0)
                        res.push_back(vec[vec.size()/2-count]);
                    if(vec.size()/2+count<vec.size())
                        res.push_back(vec[vec.size()/2+count]);
                    count++;
                }
                this->dataVec = res;
            }
    };
}