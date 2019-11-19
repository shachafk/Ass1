#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/json.hpp"
#include "../include/Watchable.h"
#include "../include/Session.h"

using namespace std;

int main(int argc, char** argv){
   //std::cout << "Hello, World!" << std::endl;


  /*  std::ifstream i(argv[1]);
    nlohmann::json j;
    i >> j;
    // std::cout<<j;
    std::cout<<j["movies"][0];
    Movie("movie")*/
    Episode e(2, "Brooklyn",24, 02, 03 , nullptr);

    if(argc!=2)
    {
        cout << "usage splflix input_file" << endl;
        return 0;
    }
    Session s(argv[1]);
    //s.start();
    return 0;

}