#include "resistor_color.h"
#include <vector>
#include <string> 
using namespace std;
namespace resistor_color {
    vector<string> color_list = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
    int color_code(string color) {
        for (size_t i = 0; i < color_list.size(); i++) {
            if (color == color_list.at(i)){
                return i;
            }
        }
        return -1;
    }
    vector<string> colors() {
        return color_list;
    }


}  // namespace resistor_color





#pragma once
#include <string>
#include <vector>
namespace resistor_color {

    int color_code(std::string color);
    std::vector<std::string> colors();
// TODO: add your solution here

}  // namespace resistor_color
