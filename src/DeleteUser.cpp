//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//

#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"


void DeleteUser::act(Session &sess) {
    std::vector<std::string>* input = sess.getInputVector();
    std::string name;
    for (int i=1;i<input->size();i++) {
        if (i>1){
            name = name + " ";
        }
        name = name + sess.getInputVector()->at(i);
    }
    std::unordered_map<std::string,User*> map= sess.getUsersMap();
    if (map[name]){ //name exists in usermap
        User* user = map[name];
        delete(user);
        map.erase(name);
        complete();
    }
    else {
        std::string errorMsg = "DeleteUser Error: the user " + name + " does not exist";
        error(errorMsg);
    }
}
 std::string DeleteUser::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "DeleteUser " + status;
}

