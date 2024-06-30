#if !defined(SIMULATION_H)
#define SIMULATION_H

#include <stdlib.h>
#include <unit.h>
#include <collision.h>
#include <stdbool.h>

typedef struct {
    double catch_count;
    bool catch_did_just_occured;
    bool any_hit_just_occured;
    Unit *__units;
    Collision *__collisions;
    double __integration_delta;
    double __unit_radius;
    double __fps;
    int __ticks_since_last_catch;
} Simulation;

Simulation simulation_init(
    Unit catcher,
    Unit *const runners,
    const size_t runners_size,
    const double unit_radius,
    const double fps
);
Unit *simulation_get_catcher(const Simulation *const simulation);
Unit *simulation_get_runner(const Simulation *const simulation, const size_t index);
void tick(const Simulation *const simulation);

#endif // SIMULATION_H
