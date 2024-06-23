#pragma once
#include <ros/ros.h> //  ROS API
#include <memory>

namespace rtcpp
{
    class HttpClient
    {
    public:
        HttpClient(int argc, char *argv[]);
        void run();
        ~HttpClient();

    private:
        struct Parameters
        {
            std::string ip_address;
            int port;
            std::string request;
        };
        std::unique_ptr<ros::NodeHandle> m_nh;
        Parameters m_param;
        ros::Publisher m_pub;
        int m_count = 0;
    };

} // namespace rtcpp
