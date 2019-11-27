//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//


#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


void PrintContentList::act(Session &sess) {
    std::vector<Watchable *> content = sess.getContent();

    for (int i = 1; (unsigned) i < content.size(); i++) {
        std::cout << content[i]->printContent() << std::endl;
    }
    complete();
}


std::string PrintContentList::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "PrintContentList " + status;
}

BaseAction* PrintContentList::clone() const{ return new PrintContentList(*this);}
