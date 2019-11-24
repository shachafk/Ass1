#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/Session.h"

using namespace std;

int main(int argc, char** argv){
    if(argc!=2) {
        cout << "usage splflix input_file" << endl;
        return 0;
    }
        Session s(argv[1]);
        s.start();
        return 0;
}
