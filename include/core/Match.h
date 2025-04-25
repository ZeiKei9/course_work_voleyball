#pragma once

#include "../entities/Team.h"

class MatchStrategy {
public:
    virtual ~MatchStrategy() = default;
    virtual bool determineWinner(const Team& t1, const Team& t2) = 0;
};

class StandardMatchStrategy : public MatchStrategy {
public:
    bool determineWinner(const Team& t1, const Team& t2) override;
};