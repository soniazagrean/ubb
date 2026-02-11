//
// Created by Sonia Zagrean on 04.06.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include <map>

#include "Repository.h"
#include "Validator.h"


class Service {
private:
    Repository r;
    Validator v;
public:
    Service(Repository& r, Validator& v): r(r), v(v) {}
    ~Service()=default;

    void add(Program& p) {
        v.validate(p);

        for (auto& i : r.get()) {
            if (i.getZi() == p.getZi()) {
                if (p.getOraStop() > i.getOraStart() && p.getOraStart() < i.getOraStop()) {
                    throw std::runtime_error("overlap of 2 programs");
                }
            }
        }

        r.add(p);
    }


    std::vector<Program>& get() {
        return r.get();
    }

    void deleteProgram(int zi, int oraStart, int oraStop) {
        auto& all = r.get();
        for (auto it = all.begin(); it != all.end(); ++it) {
            if (it->getZi() == zi && it->getOraStart() == oraStart && it->getOraStop() == oraStop) {
                all.erase(it);
                return;
            }
        }
    }

    std::pair<std::string, int> getMostWatched() {
        std::map<std::string, int> count;

        for (auto& p : r.get()) {
            count[p.getNume()] += (p.getOraStop() - p.getOraStart()); // count hours
        }

        if (count.empty())
            return {"", 0}; // there is no program

        std::string mostProg;
        int maxHours = 0;

        for (auto& entry : count) {
            if (entry.second > maxHours) {
                maxHours = entry.second;
                mostProg = entry.first;
            }
        }

        return {mostProg, maxHours};
    }


};



#endif //SERVICE_H
