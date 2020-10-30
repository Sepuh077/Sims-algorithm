#pragma once
#include <iostream>

class tex {
public:
    short a[5];
    tex (){
        for(int i = 1;i <= 4; i++) {
            a[i] = i;
        }
    }
    tex(const tex& b) {
        for(int i = 1;i <= 4; ++i) {
            a[i] = b.a[i];
        }
    }
    tex hakadardz() {
        tex b;
        for(int i = 1;i <= 4; ++i) {
            b.a[a[i]] = i;
        }
        return b;
    }
    void input() {
        for(int i = 1;i <= 4; ++i) {
            std::cin >> a[i];
        }
        return;
    }
    tex operator*(tex b) {
        tex c;
        for(int i = 1;i <= 4; ++i) {
            c.a[i] = b.a[this->a[i]];
        }
        return c;
    }
    void print() const{
        for(int i = 1;i <= 4; ++i) {
            std::cout<<a[i]<<" ";
        }
        std::cout<<" | ";
    }
    void operator=(tex b) {
        for(int i = 1;i <= 4; ++i) {
            a[i] = b.a[i];
        }
    }
    bool operator==(const tex& b) const{
        for(int i = 1;i <= 4; ++i) {
            if(a[i]!=b.a[i])
                return false;
        }
        return true;
    }
    bool operator!=(const tex& b) const {
        if(b == (*this))
            return false;
        return true;
    }
};