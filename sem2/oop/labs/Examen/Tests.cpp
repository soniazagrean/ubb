//
// Created by Sonia Zagrean on 04.06.2025.
//

#include "Tests.h"

#include <cassert>

#include "Program.h"
#include "Repository.h"
#include "Service.h"
#include "Validator.h"

void runTests() {
    // === Test Program ===
    Program p("TestShow", "TestProducer", 16, 18, 5);
    assert(p.getNume() == "TestShow");
    assert(p.getProducator() == "TestProducer");
    assert(p.getOraStart() == 16);
    assert(p.getOraStop() == 18);
    assert(p.getZi() == 5);

    // === Test Validator ===
    Validator v;

    // valid
    v.validate(p);

    // invalid day
    try {
        Program p2("Bad", "Bad", 16, 18, 0);
        v.validate(p2);
        assert(false); // should not reach
    } catch (std::runtime_error&) {
        assert(true);
    }

    // invalid hour
    try {
        Program p3("Bad", "Bad", -1, 18, 5);
        v.validate(p3);
        assert(false);
    } catch (std::runtime_error&) {
        assert(true);
    }

    // invalid interval
    try {
        Program p4("Bad", "Bad", 14, 15, 5);
        v.validate(p4);
        assert(false);
    } catch (std::runtime_error&) {
        assert(true);
    }

    // === Test Repository ===
    Repository r;
    assert(r.get().size() == 0);

    r.add(p);
    assert(r.get().size() == 1);
    assert(r.get()[0].getNume() == "TestShow");

    // === Test Service ===
    Service s(r, v);

    // must throw because already exists on day 5 same interval
    try {
        Program p5("Another", "Another", 17, 19, 5); // overlap with 16-18
        s.add(p5);
        assert(false);
    } catch (std::runtime_error&) {
        assert(true);
    }

    // add on different day — must succeed
    Program p6("Another", "Another", 16, 18, 6);
    s.add(p6);
    assert(s.get().size() == 2);

    // test getMostWatched()
    auto result = s.getMostWatched();
    assert(result.first == "TestShow" || result.first == "Another"); // both have 2h each
    assert(result.second == 2);

    // test deleteProgram
    s.deleteProgram(5, 16, 18);
    assert(s.get().size() == 1);
    assert(s.get()[0].getZi() == 6);
}
