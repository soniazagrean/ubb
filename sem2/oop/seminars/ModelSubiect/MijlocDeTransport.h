//
// Created by Sonia Zagrean on 31.05.2025.
//

#pragma once
#include <string>

class MijlocDeTransport {
public:
    virtual int getId()=0;
    virtual int getCapacitate()=0;
    virtual std::string getTip()=0;
};



class Autobuz : public MijlocDeTransport {
private:
    int id, capacitate;
public:
    Autobuz(int id, int capacitate): id(id), capacitate(capacitate){}
    int getId() {
        return id;
    }
    int getCapacitate() {
        return capacitate;
    }
    std::string getTip() {
        return "autobuz";
    }
};

class Tramvai : public MijlocDeTransport {
private:
    int id, capacitate;
public:
    Tramvai(int id, int capacitate): id(id), capacitate(capacitate){}
    ~Tramvai()=default;
    int getId() {
        return id;
    }
    int getCapacitate() {
        return capacitate;
    }
    std::string getTip() {
        return "tramvai";
    }
};
