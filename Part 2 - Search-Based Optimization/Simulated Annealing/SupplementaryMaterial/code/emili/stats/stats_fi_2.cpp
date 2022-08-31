/*#include "./stats_fi.h"

emili::Solution* emili::StatsFirstImprovementSearch::search(emili::Solution* initial)
{
        termcriterion->reset();
        neighbh->reset();
        emili::Solution* incumbent = initial->clone();
        emili::Solution* ithSolution;

        Neighborhood::NeighborhoodIterator end = neighbh->end();
        long int iteration_counter;
        long int neighbourhood_size = neighbh->size();
        do{

            *bestSoFar = *incumbent;
            Neighborhood::NeighborhoodIterator iter = neighbh->begin(incumbent);
            ithSolution = *iter;

            iteration_counter = 0;
            for(;iter!=end;++iter)
            {
                iteration_counter++;
                if(incumbent->operator >(*ithSolution)){
                    *incumbent=*ithSolution;
                    printSolstats(incumbent);
                    print("iteration_counter stopped at: %ld/%ld\n", iteration_counter, neighbourhood_size);
                    break;
                }
            }
            delete ithSolution;
        }while(!termcriterion->terminate(bestSoFar,incumbent));
        if(*bestSoFar > *incumbent)
        {
            *bestSoFar = *incumbent;
        }
        delete incumbent;
        return bestSoFar->clone();
}*/
