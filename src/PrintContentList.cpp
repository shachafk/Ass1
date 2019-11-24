//
// Created by shachafk@wincs.cs.bgu.ac.il on 21/11/2019.
//


#include "../include/Action.h"
#include "../include/User.h"
#include "../include/Session.h"
#include "../include/Watchable.h"


void PrintContentList::act(Session &sess) {
    std::vector<Watchable *> content = sess.getContent();
 //   Watchable* m1;
  //  for (int i = 0; i < 4; i++) {
  //      m1 = content.at(i);
   //     std::string toPrint=  m1.print();
   //     std::cout << toPrint << std::endl;

}



std::string PrintContentList::toString() const{
    std::string status = getEnumStringFromInt(this->getStatus());
    return "PrintContentList " + status;
}