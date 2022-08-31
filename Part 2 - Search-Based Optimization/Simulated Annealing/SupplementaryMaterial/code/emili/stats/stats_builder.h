//
//  Created by Federico Pagnozzi on 12/12/17.
//  Copyright (c) 2014 Federico Pagnozzi. All rights reserved.
//  This file is distributed under the BSD 2-Clause License. See LICENSE.TXT
//  for details.

#ifndef __STATS_BUILDER_H
#define  __STATS_BUILDER_H
#include "../generalParser.h"
#include "../emilibase.h"
#include "stats_rw.h"
#include "stats_bi.h"
#include "stats_fi.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace prs
{
namespace stats
{

class StatsBuilder: public Builder
{
public:
    StatsBuilder(GeneralParserE& generalParser,TokenManager& tokenManager):Builder(generalParser,tokenManager) { }
    virtual bool isCompatibleWith(char* problem_definition) { return true; } // true if the builder builds only problem indipendent components
    virtual emili::Termination* buildTermination();
    virtual emili::Acceptance* buildAcceptance();
    virtual emili::LocalSearch* buildAlgo();
};
}
}
#endif //  __STATS_BUILDER_H
