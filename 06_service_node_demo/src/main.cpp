#include "fifa_server/fifa_server.hpp"

int main(int argc, char **argv)
{
    try
    {
        auto server = fifa::FifaServer(argc, argv);
        server.run();
    }
    catch (const ros::InvalidNodeNameException &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}