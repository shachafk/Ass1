//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"



void PrintActionsLog::act(Session &sess) {
    std::vector<BaseAction*> all = sess.getActionsLog();

        for (auto it = all.rend(); it!= all.rbegin();it++){
        if (*it != nullptr) {
            const std::string actionandstatus = (*it)->toString(); //SIGSEGV (Segmentation fault) error - TBD
            if ((*it)->getStatus() !=2){ // completed or pending
                std::cout << actionandstatus << std::endl;
            }
            else {
                std::string error = (*it)->getError();
                std::cout << error << std::endl;
            }
        }
    }
    return;
}
std::string PrintActionsLog::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "PrintActionsLog " + status;
}

