//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"


void DeleteUser::act(Session &sess) {
    std::string name = sess.getInputVector()->at(1);
    std::unordered_map<std::string,User*> map= sess.getUsersMap();
    if (map[name]){ //name exists in usermap
        User* user = map[name];
        delete(user);
        map.erase(name);
        complete();
    }
    else {
        std::string errorMsg = "user " + name + " doesn't exists";
        error(errorMsg);
    }
}
 std::string DeleteUser::toString() const{
    return ""; //TBD to implement;
}

