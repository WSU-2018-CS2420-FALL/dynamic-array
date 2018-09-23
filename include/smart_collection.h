#ifndef _SMART_COLLECTION_H_
#define _SMART_COLLECTION_H_

#include <iostream>
#include <memory>
template<typename Item>
class Collection {
public:
    Collection(): sz(0), capacity(8), elements(std::make_unique<Item[]>(8)){}
    Collection(int size): sz(size), capacity(size), elements(std::make_unique<Item[]>(size)){}
    Collection(const Collection<Item>& c): sz(c.sz), capacity(c.capacity), elements(std::make_unique<Item[]>(c.capacity)) {
        for(int i = 0; i < c.sz; i++){
            elements[i] = c.elements[i];
        }
    }

    // Required to support range-based for loop
    Item* begin(){ return elements.get(); }
    Item* end(){ return elements.get() + sz; }

    void add(Item e){
        if(sz == capacity){
            auto newElements = std::make_unique<Item[]>(capacity * 2);
            for(int i = 0; i < sz; i++){
                newElements[i] = elements[i];
            }
            elements = std::move(newElements);
            capacity *= 2;
        }
        elements[sz++] = e;
    }

    Collection<Item>& operator=(const Collection<Item>& c){
       auto newElements = std::make_unique<Item[]>(c.capacity);
       for(int i = 0; i < sz; i++){
             newElements[i] = c.elements[i];
       }

       elements = std::move(newElements);
       sz = c.sz;
       capacity = c.capacity;
    }

    Item operator[](int i) const{
        return elements[i];
    }
    Item& operator[](int i) {
        return elements[i];
    }
    Collection<Item>& remove(){
        sz--;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Collection<Item>& c){
        for(int i = 0; i < c.sz; i++){
            out << c.elements[i] << " ";
        }

        return out;
    }

    ~Collection(){}
protected:
    int  sz, capacity;
    std::unique_ptr<Item[]> elements;
};
#endif