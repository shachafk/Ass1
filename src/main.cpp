#include <iostream>
#include <fstream>
#include <iomanip>
#include "../include/json.hpp"
#include "../include/Session.h"
using namespace std;

int main(int argc, char** argv){
   //std::cout << "Hello, World!" << std::endl;


    std::ifstream i("../config1.json");
    nlohmann::json j;
    i >> j;
    //  std::cout<<j;
    std::cout<<j["tv_series"];
    //std::cout <<std::setw(4) << j << std::endl;


    //std::vector<std::uint8_t> v = {'t', 'r', 'u', 'e'};
    //nlohmann::json j = nlohmann::json::parse(v.begin(), v.end());



/*
    if(argc!=2)
    {
        cout << "usage splflix input_file" << endl;
        return 0;
    }
    Session s(argv[1]);
    s.start();
    return 0;
*/
}