#ifndef __STATS_BI_H__
#define __STATS_BI_H__

#include "../emilibase.h"

#include <cfloat>

namespace emili {

class StatsBISearch : public emili::LocalSearch
{
public:
    StatsBISearch(InitialSolution& initialSolutionGenerator ,Termination& terminationcriterion, Neighborhood& neighborh):emili::LocalSearch(initialSolutionGenerator,terminationcriterion,neighborh) {}
    virtual Solution* search();
    virtual Solution* search(emili::Solution* initial);
   
    /*virtual emili::Solution* getBestSoFar() {
       return getBestSolution();
    }*/

};

}

#endif
