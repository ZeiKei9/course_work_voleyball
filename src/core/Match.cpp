#include "../include/core/Match.h"

bool StandardMatchStrategy::determineWinner(const Team& t1, const Team& t2) {
    const int t1_total = t1.getPowerAttack() + t1.getPowerDefend();
    const int t2_total = t2.getPowerAttack() + t2.getPowerDefend();
    
    if(t1_total == t2_total) {
        return t1.getPowerDefend() > t2.getPowerDefend();
    }
    
    return t1_total > t2_total;
}