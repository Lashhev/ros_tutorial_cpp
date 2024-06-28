#include "fifa_server/fifa_server.hpp"
#include <functional>
#include <tuple>
std::vector<std::tuple<std::string, std::string, std::string>> players = {{"Robert", "Lewandowski", "Polish"}, {"João", "Félix Sequeira", "Portuguese"}};
namespace fifa
{
    bool FifaServer::callback(fifa_msgs::TeamInfo::Request &req, fifa_msgs::TeamInfo::Response &res)
    {
        if (req.team == "Barcelona")
        {
            res.manager = "Hans-Dieter Flick";
            for (auto &[name, last_name, nationality] : players)
            {
                fifa_msgs::Player p;
                p.info.first_name = name;
                p.info.last_name = last_name;
                p.info.nationality = nationality;
                p.team = "Barcelona";
                res.players.players.push_back(p);
            }
        }
        else
        {
            res.manager.clear();
            res.players.players.clear();
        }
        return true;
    }
    FifaServer::FifaServer(int argc, char **argv)
    {
        ros::init(argc, argv, "fifa_server");
        m_nh = std::make_shared<ros::NodeHandle>();
        m_service = m_nh->advertiseService("/get_team_info", &FifaServer::callback, this);
        ros::spin();
    }
    void FifaServer::run()
    {
        ros::spin();
    }
    void FifaServer::stop()
    {
        ros::shutdown(); // Завершает работу узла
    }

    FifaServer::~FifaServer()
    {
    }
} // namespace fifa
