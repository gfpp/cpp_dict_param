#include "cpp_dict_param/dict_param.hpp"

ParamData DictParam::param_data;


DictParam::DictParam(ros::NodeHandle &pnh)
{
    std::string param_name = "dict_data";
    XmlRpc::XmlRpcValue dict_param;

    // Look for 'dict_data' parameter.
    if( pnh.hasParam(param_name) )
    {
        // Reading parameter.
        pnh.getParam(param_name, dict_param);
        ROS_INFO_STREAM(" dict_param.getType(): " << dict_param.getType());

        // Check if parameter is a 'dict'.
        if( dict_param.getType() == XmlRpc::XmlRpcValue::Type::TypeStruct )
        {
            ROS_INFO_STREAM(" dict_param.size(): " << dict_param.size());

            // Iterate through 'dict'.
            for(XmlRpc::XmlRpcValue::ValueStruct::iterator it = dict_param.begin();
                    it != dict_param.end(); ++it)
            {
                ROS_INFO_STREAM(" - key: " << it->first);
                ROS_INFO_STREAM(" - value: " << it->second
                        << " (type: " << it->second.getType() << ")");
            }

            // Reading 'dict' values.
            if(dict_param["int_data"].getType() == XmlRpc::XmlRpcValue::Type::TypeInt)
                param_data.int_data = static_cast<int>(dict_param["int_data"]);
            if(dict_param["double_data"].getType() == XmlRpc::XmlRpcValue::Type::TypeDouble)
                param_data.double_data = static_cast<double>(dict_param["double_data"]);
            if(dict_param["bool_data"].getType() == XmlRpc::XmlRpcValue::Type::TypeBoolean)
                param_data.bool_data = static_cast<bool>(dict_param["bool_data"]);
            if(dict_param["string_data"].getType() == XmlRpc::XmlRpcValue::Type::TypeString)
                param_data.string_data = static_cast<std::string>(dict_param["string_data"]);
        }
    }
    else
    {
        ROS_FATAL("'~%s' parameter has to be defined!", param_name.c_str());
        ROS_BREAK();
    }

    ROS_INFO("Node ready!");

    ROS_INFO("'dict' parameter:");
    ROS_INFO(" - int_data: %d", param_data.int_data);
    ROS_INFO(" - double_data: %.2f", param_data.double_data);
    ROS_INFO(" - bool_data: %s", (param_data.bool_data) ? "true" : "false");
    ROS_INFO(" - string_data: %s", param_data.string_data.c_str());
}

DictParam::~DictParam()
{
}
