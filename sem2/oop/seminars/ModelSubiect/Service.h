//
// Created by Sonia Zagrean on 31.05.2025.
//

#ifndef SERVICE_H
#define SERVICE_H
#include "Repository.h"


class Service {
private:
    Repository& r;
public:
    Service(Repository& r) : r(r){}
    void add(MijlocDeTransport* m) {
        r.add(m);
    }
    std::vector<MijlocDeTransport*>& get() {
        return r.getAll();
    }
    std::vector<MijlocDeTransport*> filterCap(int minCap) {
        std::vector<MijlocDeTransport*> result;
        for (auto* i : r.getAll())
            if (i->getCapacitate() > minCap)
                result.push_back(i);
        return result;
    }

    std::pair<int, int> countTypes() {
        int autobuze = 0, tramvaie = 0;
        for (auto* i: r.getAll())
            if (i->getTip() == "autobuz")
                autobuze++;
            else if (i->getTip() == "tramvai")
                tramvaie++;
        return {autobuze, tramvaie};
    }
    MijlocDeTransport* largestCapacity() {
        if (r.getAll().empty())
            return nullptr;

        MijlocDeTransport* maxMijloc = r.getAll()[0];
        for (auto* mijloc : r.getAll()) {
            if (mijloc->getCapacitate() > maxMijloc->getCapacitate()) {
                maxMijloc = mijloc;
            }
        }
        return maxMijloc;
    }

    ~Service()=default;
};



#endif //SERVICE_H
