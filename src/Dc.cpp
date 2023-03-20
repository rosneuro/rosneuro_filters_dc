#include "rosneuro_filters_dc/Dc.hpp"
#include "pluginlib/class_list_macros.h"

PLUGINLIB_EXPORT_CLASS(rosneuro::Dc<int>, rosneuro::Filter<int>)
PLUGINLIB_EXPORT_CLASS(rosneuro::Dc<float>, rosneuro::Filter<float>)
PLUGINLIB_EXPORT_CLASS(rosneuro::Dc<double>, rosneuro::Filter<double>)

