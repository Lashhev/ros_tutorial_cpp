#include "fifa_msgs/TeamInfo.h"
#include <ros/ros.h> //  ROS API
#include <memory>

namespace fifa
{
    class FifaServer
    {
    public:
        FifaServer(int argc, char **argv);
        void run();
        void stop();
        ~FifaServer();

    private:
        bool callback(fifa_msgs::TeamInfo::Request &req, fifa_msgs::TeamInfo::Response &res);

    private:
        std::shared_ptr<ros::NodeHandle> m_nh;
        ros::ServiceServer m_service;
    };

}