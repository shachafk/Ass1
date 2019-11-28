//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"



void PrintActionsLog::act(Session &sess) {
    std::vector<BaseAction*> all = sess.getActionsLog();
            int i= all.size()-1;
            while (i>=0) {
                if (all[i] != nullptr) {
                    const std::string actionandstatus = (all[i])->toString();
                    if ((all[i])->getStatus() != 2) { // completed or pending
                        std::cout << actionandstatus << std::endl;
                    } else {
                        std::string error = (all[i])->getError();
                        std::cout << error << std::endl;
                    }
                }
                i--;
            }
    this->complete();
    return;
}
std::string PrintActionsLog::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "PrintActionsLog " + status;
}

BaseAction* PrintActionsLog::clone() const{ return new PrintActionsLog(*this);}
