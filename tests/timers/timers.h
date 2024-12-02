/*----------------------------------------------------------------------------------
// Name: timers.h
// Description: Includes functions intended to read information off of the hpmcounters
//              available in a given RISCV simulator.
//----------------------------------------------------------------------------------
*/

#include <stdint.h>
#ifndef TIMERS_H
#define TIMERS_H

uint64_t update_cpu_time_val();
uint64_t update_instrets_val();
uint64_t update_num_cycles_val();
uint64_t update_instr_cache_miss_val();
uint64_t update_data_cache_miss_val();
uint64_t update_branch_taken_val();
uint64_t update_branch_miss_val();

typedef struct Timer
{
    uint64_t numInstretsStart;
    uint64_t numInstretsEnd;
    uint64_t numCPUCyclesStart;
    uint64_t numCPUCyclesEnd;
    uint64_t CPUTimeStart;
    uint64_t CPUTimeEnd;
    uint64_t branchesTakenStart;
    uint64_t branchesTakenEnd;
    uint64_t branchMissStart;
    uint64_t branchMissEnd;
    uint64_t instrCacheMissStart;
    uint64_t instrCacheMissEnd;
    uint64_t dataCacheMissStart;
    uint64_t dataCacheMissEnd;
} Timer;

    void print_timing_data(Timer t);
    struct Timer update_start_timers(Timer t);
    struct Timer update_stop_timers(Timer t);

#endif