#include <bits/stdc++.h>

class Server
{
public:
    int getLoad()
    {
        return load;
    }
    void setLoad(int load)
    {
        this->load = load;
    }
    void addLoad(int load)
    {
        this->load += load;
    }
    void removeLoad(int load)
    {
        this->load -= load;
    }

private:
    int load;
}

// implement a load balancer to distribute requests to multiple programs
class LoadBalancer
{
public:
    LoadBalancer(int n)
    {
        for (int i = 0; i < n; i++)
        {
            servers.push_back(new Server());
        }
    }
    void addServer(Server *server)
    {
        servers.push_back(server);
    }
    void removeServer(Server *server)
    {
        servers.erase(std::remove(servers.begin(), servers.end(), server), servers.end());
    }
    Server *getServer()
    {
        int min = INT_MAX;
        Server *server = NULL;
        for (int i = 0; i < servers.size(); i++)
        {
            if (servers[i]->getLoad() < min)
            {
                min = servers[i]->getLoad();
                server = servers[i];
            }
        }
        return server;
    }

private:
    vector<Server *> servers;
};