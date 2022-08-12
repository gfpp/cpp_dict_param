#include <ros/ros.h>
#include "cpp_dict_param/dict_param.hpp"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "dict_param");
    //ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    //DictParam dict_param(nh, pnh);
    DictParam dict_param(pnh);
    ros::spin();

    return 0;
}
