//
//  Created by Federico Pagnozzi on 12/12/17.
//  Copyright (c) 2014 Federico Pagnozzi. All rights reserved.
//  This file is distributed under the BSD 2-Clause License. See LICENSE.TXT
//  for details.

#include "stats_builder.h"
//#include "stats_bi.h"
//#include "stats_fi.h"
//#include "stats_rw.h"

#define PROBSIZE_TERMINATION "probsizeterm"
#define RWMETROPOLIS "rwmetropolis"
#define TALS "tals" // timed ALS
#define STATSRWALGO "statsrw"
#define STATSBIALGO "statsbi"
#define STATSFIALGO "statsfi"

    
    /*bool prs::stats::StatsBuilder::isCompatibleWith(char* problem_definition)
    {
        return true;
    }*/

    
    emili::Termination* prs::stats::StatsBuilder::buildTermination() {
       prs::incrementTabLevel();
       emili::Problem* instance = gp.getInstance();
       emili::Termination* term = nullptr;
       std::ostringstream oss;
       if(tm.checkToken(PROBSIZE_TERMINATION))
       {
           int n = instance->problemSize();
           float k = tm.getDecimal();

           int nmoves = std::ceil(n * k);

           oss.str(""); oss  << "Termination based on problem-size " << k << " x " << n << " = " << nmoves;
           printTab(oss.str().c_str());
           term = new  emili::MaxStepsTermination(nmoves);
        } 

        prs::decrementTabLevel();
        return term;
    }

    emili::Acceptance* prs::stats::StatsBuilder::buildAcceptance() {
       prs::incrementTabLevel();
       emili::Problem* instance = gp.getInstance();
       emili::Acceptance* acc = nullptr;
       std::ostringstream oss;

       if(tm.checkToken(RWMETROPOLIS)) {
          emili::Neighborhood* nei = retrieveComponent(COMPONENT_NEIGHBORHOOD).get<emili::Neighborhood>();
          emili::InitialSolution* is = retrieveComponent(COMPONENT_INITIAL_SOLUTION_GENERATOR).get<emili::InitialSolution>();
          int length = tm.getInteger();
          float value = tm.getDecimal();
          int i;
          double init_temp;
          //clock_t ti = clock(), tf;

          emili::Solution *s1;
          emili::Solution *s2 = is->generateSolution();

          double c1,
                 c2 = s2->getSolutionValue();
          double bestcost = c2,
                 costsum = 0;

          for (i = 0 ; i < length ; i++) {
              s1 = s2;
              s2 = nei->random(s1);; //is->generateSolution();
              c1 = c2;
              c2 = s2->getSolutionValue();
              costsum += abs(c2 - c1);

              delete s1;
          }
 
          delete s2;

          //tf = clock();
 
          //move_time = ((float)(tf - ti)) / (CLOCKS_PER_SEC * length);
 
          init_temp = value * costsum / length;
          oss.str(""); oss  << "RW-based Metropolis acceptance with temperature " << init_temp;
          printTab(oss.str().c_str());
          acc = new  emili::MetropolisAcceptance(init_temp);
       }

       prs::decrementTabLevel();
       return acc;
    }

    emili::LocalSearch* prs::stats::StatsBuilder::buildAlgo() {
       prs::incrementTabLevel();
       emili::LocalSearch* ls = nullptr;
       if(tm.checkToken(STATSRWALGO))
       {
          printTab("Random Walk to compute probing landscape features");
          emili::InitialSolution* in = retrieveComponent(COMPONENT_INITIAL_SOLUTION_GENERATOR).get<emili::InitialSolution>();
          emili::Termination* term = retrieveComponent(COMPONENT_TERMINATION_CRITERION).get<emili::Termination>();
          emili::Neighborhood* nei = retrieveComponent(COMPONENT_NEIGHBORHOOD).get<emili::Neighborhood>();
          ls = new emili::StatsRWSearch(*in, *term, *nei);
       } else if(tm.checkToken(STATSBIALGO)) {
          printTab("BI to compute probing landscape features");
          emili::InitialSolution* in = retrieveComponent(COMPONENT_INITIAL_SOLUTION_GENERATOR).get<emili::InitialSolution>();
          emili::Termination* term = retrieveComponent(COMPONENT_TERMINATION_CRITERION).get<emili::Termination>();
          emili::Neighborhood* nei = retrieveComponent(COMPONENT_NEIGHBORHOOD).get<emili::Neighborhood>();
          ls = new emili::StatsBISearch(*in, *term, *nei);
       } else if(tm.checkToken(STATSFIALGO)) {
          printTab("FI to compute probing landscape features");
          emili::InitialSolution* in = retrieveComponent(COMPONENT_INITIAL_SOLUTION_GENERATOR).get<emili::InitialSolution>();
          emili::Termination* term = retrieveComponent(COMPONENT_TERMINATION_CRITERION).get<emili::Termination>();
          emili::Neighborhood* nei = retrieveComponent(COMPONENT_NEIGHBORHOOD).get<emili::Neighborhood>();
          ls = new emili::StatsFISearch(*in, *term, *nei);
       } else if(tm.checkToken(TALS)) {
          printTab("Timed Alternate Local Search");
          emili::InitialSolution* in = retrieveComponent(COMPONENT_INITIAL_SOLUTION_GENERATOR).get<emili::InitialSolution>();
          emili::LocalSearch* ls1 = retrieveComponent(COMPONENT_ALGORITHM).get< emili::LocalSearch>();
          emili::LocalSearch* ls2 = retrieveComponent(COMPONENT_ALGORITHM).get< emili::LocalSearch>();
          emili::Termination* term = new emili::WhileTrueTermination();
          ls = new emili::AlternateLocalSearch(*in,ls1,ls2, term);
       }
       prs::decrementTabLevel();
       return ls;
    }


