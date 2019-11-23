//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"



void PrintActionsLog::act(Session &sess) {
    std::vector<BaseAction*> all = sess.getActionsLog();
    for (auto i=all.size() ; i>=0;i--){
        if (all[i] != nullptr) {
            std::string stype = typeid(all[i]).name();
            std::string status = all[i]->getEnumStringFromInt(all[i]->getStatus());
            std::string toPrint = stype + " " + status + " ";  //need to add errorMsg
            std::cout << toPrint << std::endl;
        }
    }
    return;
}
std::string PrintActionsLog::toString() const{
    return ""; //TBD
}

