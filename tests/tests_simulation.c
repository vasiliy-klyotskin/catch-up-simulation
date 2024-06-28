#include <macroassert.h>
#include <simulation.h>

void test_simulation_init(void) {
    Unit catcher = unit_init(1, 1);
    Unit runners[0] = {};

    Simulation s = simulation_init(catcher, runners, 2, 1, 60);

    assert_eq(s.catch_count, 0);
    assert_eq(s.catch_did_just_occured, false);
    assert_eq(s.any_hit_just_occured, false);
}

void test_simulation_get_catcher(void) {
    Unit catcher_input = unit_init(1, 2);
    Unit runners[0] = {};
    Simulation s = simulation_init(catcher_input, runners, 0, 1, 60);

    Unit *catcher = simulation_get_catcher(&s);

    assert_eq(catcher->position.x, 1);
    assert_eq(catcher->position.y, 2);
}

void test_simulation_get_runner(void) {
    Unit catcher_input = unit_init(1, 2);
    Unit runners[2] = { unit_init(3, 4), unit_init(5, 6) };
    Simulation s = simulation_init(catcher_input, runners, 2, 1, 60);

    Unit *runner1 = simulation_get_runner(&s, 0);
    assert_eq(runner1->position.x, 3);
    assert_eq(runner1->position.y, 4);

    Unit *runner2 = simulation_get_runner(&s, 1);
    assert_eq(runner2->position.x, 5);
    assert_eq(runner2->position.y, 6);
}

void tests_simulation(void) {
    test_simulation_init();
    test_simulation_get_catcher();
    test_simulation_get_runner();
}