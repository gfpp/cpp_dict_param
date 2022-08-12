#ifndef DICT_PARAM_HPP
#define DICT_PARAM_HPP

#include <ros/ros.h>

#include <string>
#include <ostream>

struct ParamData {
    int int_data;
    double double_data;
    bool bool_data;
    std::string string_data;

    ParamData() : int_data(0), double_data(0.0), bool_data(false), string_data("") {}

    friend std::ostream &operator<<(std::ostream &out, const ParamData &p)
    {
        out << std::setiosflags(std::ios::fixed) << std::setprecision(2);
        out << "int_data: " << p.int_data << "\n"
            << "double_data: " << p.double_data << "\n"
            << "bool_data: " << (p.bool_data ? "true" : "false");
        return out;
    }
};


class DictParam {
    public:
        DictParam(ros::NodeHandle & );
        ~DictParam();

    private:
        static ParamData param_data; // 'static' for Dynamic Reconfigure
};

#endif
