//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//


#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"

void PrintWatchHistory::act(Session &sess) {
    std::vector<Watchable *> myhistory = sess.getActiveUser()->get_history();
    std::cout << "Watch history for " + sess.getActiveUser()->getName() << std::endl;
    for (int i = 0; (unsigned) i < myhistory.size(); i++) {
        std::cout << std::to_string(i+1) + ". " + myhistory[i]->toString() << std::endl;
    }
    complete();
}


std::string PrintWatchHistory::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "PrintWatchHistory " + status;
}

BaseAction* PrintWatchHistory::clone() const{ return new PrintWatchHistory(*this);}
