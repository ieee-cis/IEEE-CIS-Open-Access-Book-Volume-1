#ifndef __STATS_RW_H__
#define __STATS_RW_H__

#include "../emilibase.h"

#include <cfloat>

namespace emili {

class StatsRWSearch : public emili::LocalSearch
{
public:
    StatsRWSearch(InitialSolution& initialSolutionGenerator ,Termination& terminationcriterion, Neighborhood& neighborh):emili::LocalSearch(initialSolutionGenerator,terminationcriterion,neighborh) {}
    virtual Solution* search();
    virtual Solution* search(emili::Solution* initial);
   
    /*virtual emili::Solution* getBestSoFar() {
       return getBestSolution();
    }*/

};

}

#endif
