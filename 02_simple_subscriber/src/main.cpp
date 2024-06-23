#include <ros/ros.h>         //  ROS API
#include <std_msgs/String.h> // Подлючаем сообщения из стандартного пакета

void callback(std_msgs::String::ConstPtr msg)
{
    ROS_INFO("%s", msg->data.c_str()); // Логирование в консоль
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "simple_subscriber");

    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("/chatting", 100, callback); // Создается объект публикант для отправки сообщения в указанный топик

    ros::spin(); // Блокирующий вызов обработки входящих сообщений. Ожидает пока не будет вызвана Ctr + C
}