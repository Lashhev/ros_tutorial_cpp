#include "http/http_client.h"

int main(int argc, char *argv[])
{
    try
    {
        auto node = std::make_unique<rtcpp::HttpClient>(argc, argv);
        node->run();
    }
    catch (const ros::InvalidNodeNameException &e)
    {
        std::cerr << e.what() << '\n';
    }
}