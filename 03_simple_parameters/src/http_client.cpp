#include "http/http_client.h"
#include <diagnostic_msgs/DiagnosticArray.h>

using namespace diagnostic_msgs;

namespace rtcpp
{
    HttpClient::HttpClient(int argc, char *argv[])
    {
        ros::init(argc, argv, "http_client");
        m_nh = std::make_unique<ros::NodeHandle>();
        m_pub = m_nh->advertise<DiagnosticArray>("/diagnostic", 10);

        // https://wiki.ros.org/roscpp/Overview/Parameter%20Server
        ros::NodeHandle p_nh("~");
        p_nh.param<std::string>("ip_address", m_param.ip_address, "127.0.0.1");
        p_nh.param<int>("port", m_param.port, 9001);
        p_nh.param<std::string>("request", m_param.request, "data");
    }
    void HttpClient::run()
    {
        ros::Rate loop_rate(1);
        while (ros::ok())
        {
            DiagnosticArray msg; // Создаем сообщение
            DiagnosticStatus status;
            status.level = DiagnosticStatus::OK;
            status.name = "HttpClient";
            status.message = "OK";
            status.hardware_id = "213";

            KeyValue v1;
            v1.key = "ip_address";
            v1.value = m_param.ip_address;
            status.values.push_back(v1);

            KeyValue v3;
            v3.key = "port";
            v3.value = m_param.port;
            status.values.push_back(v3);

            KeyValue v4;
            v4.key = "request";
            v4.value = m_param.request;
            status.values.push_back(v4);

            ROS_INFO("Request 'http://%s:%d/%s' was sent", m_param.ip_address.c_str(), m_param.port, m_param.request.c_str()); // Логирование в консоль
            msg.status.push_back(status);

            msg.header.seq = m_count;
            msg.header.frame_id = "http_client";
            msg.header.stamp = ros::Time::now();

            m_pub.publish(msg); // Публикация сообщения в топик
            ros::spinOnce();    // Обработка входящих сообщений(В данном примере не очень актуально но все же)
            loop_rate.sleep();  // Задержка
            ++m_count;
        }
    }

    HttpClient::~HttpClient()
    {
    }
}
