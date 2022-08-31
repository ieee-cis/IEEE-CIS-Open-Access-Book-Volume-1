#include "stats_rw.h"

emili::Solution* emili::StatsRWSearch::search() {
    emili::Solution* current = init->generateSolution();
    emili::Solution* sol = emili::StatsRWSearch::search(current);
    if(current!=sol)
        delete current;
    
    return sol;
} // end search

emili::Solution* emili::StatsRWSearch::search(emili::Solution* initial)
{
        termcriterion->reset();
        neighbh->reset();
        emili::Solution* incumbent = initial->clone();
        emili::Solution* ithSolution;
        Neighborhood::NeighborhoodIterator end = neighbh->end();

        // neighbourhood stats 
        long int iteration_counter,
                 improving_counter,
                 neutral_counter,
                 worsening_counter;
        long int neighbourhood_size = neighbh->size();
        long int i,
                 chosen_solution,
                 cntr = 0;
        double gap,
               max_gap,
               min_gap,
               avg_gap,
               std_gap,
               value,
               stored_value,
               prev_value,
               init_value,
               best_value,
               worst_value;
        std::vector<double> gaps(neighbourhood_size + 1, 0.0);
        *bestSoFar = *incumbent;

        do
        {
            cntr++;

            //std::cout << "sa" << std::endl;
            Neighborhood::NeighborhoodIterator iter = neighbh->begin(incumbent->clone());
            ithSolution = *iter;

            init_value = incumbent->getSolutionValue();
            prev_value = init_value;
            best_value = DBL_MAX;
            worst_value = DBL_MIN;
            min_gap = DBL_MAX;
            max_gap = DBL_MIN;
            avg_gap = 0.0;
            std_gap = 0.0;

            iteration_counter = 0;
            improving_counter = 0;
            neutral_counter = 0;
            worsening_counter = 0;

            std::fill(gaps.begin(), gaps.end(), 0.0);

            chosen_solution = rand() % neighbourhood_size;
            //std::cout << "x " << chosen_solution << std::endl;

            for(;iter!=end && iteration_counter < neighbourhood_size;++iter)
            {
                value = ithSolution->getSolutionValue();

                if (value < best_value) {
                    best_value = value;
                } else if (value > worst_value) {
                    worst_value = value;
                }

                if (value < prev_value) {
                    improving_counter++;
                } else if (value == prev_value) {
                    neutral_counter++;
                } else {
                    worsening_counter++;
                }

                gap = abs(value - prev_value);
                gaps[iteration_counter] = gap;
                if (gap > max_gap) {
                    max_gap = gap;
                } else if (gap < min_gap && gap != 0) {
                    min_gap = gap;
                }

                if (iteration_counter == chosen_solution){
                    incumbent = ithSolution->clone();
                    //bestSoFar = ithSolution->clone();
                    status->newBestSolution(incumbent->clone());
                    //std::cout << value << std::endl;
                    stored_value = value;
                    *bestSoFar = *incumbent;
                }

                iteration_counter++;
                //std::cout << iteration_counter << " " ;
            }
            delete ithSolution;
            //std::cout << std::endl;
            for (i = 0 ; i < iteration_counter ; i++) {
                avg_gap += gaps[i];
            }
            avg_gap = avg_gap / iteration_counter;
            for (i = 0 ; i < iteration_counter ; i++) {
                std_gap += std::pow(gaps[i] - avg_gap, 2);
            }
            std_gap = sqrt(std_gap / (iteration_counter - 1));

            std::cout << std::fixed << "ROUNDSTATS " << cntr << " " << stored_value << " " <<
                         best_value << " " <<
                         worst_value << " " <<
                         improving_counter << " " << 1.0 * improving_counter / iteration_counter << " " <<
                         neutral_counter << " " << 1.0 * neutral_counter / iteration_counter << " " <<
                         worsening_counter << " " << 1.0 * worsening_counter / iteration_counter << " " <<
                         min_gap << " " << min_gap / best_value << " " <<
                         max_gap << " " << max_gap / best_value << " " <<
                         avg_gap << " " << avg_gap / best_value << " " <<
                         std_gap << " " << std_gap / best_value <<
                         std::endl;
            //std::cout << bestSoFar->getSolutionValue() << std::endl;
            //std::cout << incumbent->getSolutionValue() << std::endl;

        }while(!termcriterion->terminate(bestSoFar,incumbent));                  

        //*bestSoFar = *incumbent;

        //delete incumbent;

        return bestSoFar;
        //return status->getBestSolution();
}
