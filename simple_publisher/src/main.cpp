#include <ros/ros.h>         //  ROS API
#include <std_msgs/String.h> // Подлючаем сообщения из стандартного пакета

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "simple_publisher"); // Инициализация узла и обработка аргументов коммандной строки
    // указанное имя узла является значением по умолчанию и может быть изменено параметрически
    ros::NodeHandle nh;                                                   // Объект управление узлом. Обязательно создается после вызова  ros::init()
    ros::Publisher pub = nh.advertise<std_msgs::String>("/chatting", 10); // Создается объект публикант для отправки сообщения в указанный топик
    ros::Rate loop_rate(10);                                              // Объект помогающий публиковать данные с нужной частотой

    int count = 0;    // Счетчик сообщений
    while (ros::ok()) // Пока узел активен цикл работает(Узел закрывается командой Ctl + C)
    {
        std_msgs::String msg; // Создаем сообщение
        msg.data = "Hello world " + std::to_string(count);
        ROS_INFO("%s", msg.data.c_str()); // Логирование в консоль

        pub.publish(msg);  // Публикация сообщения в топик
        ros::spinOnce();   // Обработка входящих сообщений(В данном примере не очень актуально но все же)
        loop_rate.sleep(); // Задержка
        ++count;
    }
}