//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//


#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"

void PrintWatchHistory::act(Session &sess) {
    std::vector<Watchable *> myhistory = sess.myHistory();

    for (int i = 0; i < myhistory.size(); i++) {
        std::cout << myhistory[i]->toString() << std::endl;
    }
    complete();
}


std::string PrintWatchHistory::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "PrintWatchHistory " + status;
}