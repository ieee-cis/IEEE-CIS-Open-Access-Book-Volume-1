#ifndef __STATS_FI_H__
#define __STATS_FI_H__

#include "../emilibase.h"

#include <cfloat>

namespace emili {

class StatsFISearch : public emili::LocalSearch
{
public:
    StatsFISearch(InitialSolution& initialSolutionGenerator ,Termination& terminationcriterion, Neighborhood& neighborh):emili::LocalSearch(initialSolutionGenerator,terminationcriterion,neighborh) {}
    virtual Solution* search();
    virtual Solution* search(emili::Solution* initial);
   
    /*virtual emili::Solution* getBestSoFar() {
       return getBestSolution();
    }*/

};

}

#endif
