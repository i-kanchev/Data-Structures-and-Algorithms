// https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/fullstack-developer

#include <iostream>
#include <queue>

using namespace std;

struct Order
{
    unsigned index = 0, receiveTime = 0, executionTime = 0;
    
    Order(unsigned index, unsigned receiveTime, unsigned executionTime)
    {
        this->index = index;
        this->receiveTime = receiveTime;
        this->executionTime = executionTime;
    }
};

struct CompareOrders
{
    bool operator()(const Order& o1, const Order& o2)
    {
        if (o1.executionTime == o2.executionTime)
            return o1.index > o2.index;

        return o1.executionTime > o2.executionTime;
    }
};

struct CompareOrdersReceiveTime
{
    bool operator()(const Order& o1, const Order& o2)
    {
        return o1.receiveTime > o2.receiveTime;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned N;
    cin >> N;

    priority_queue<Order, vector<Order>, CompareOrders> orders;
    priority_queue < Order, vector<Order>, CompareOrdersReceiveTime> recieveTimer;

    for (size_t i = 0; i < N; i++)
    {
        unsigned t, f;
        cin >> t >> f;

        Order temp(i, t, f);

        recieveTimer.push(temp);
    }

    unsigned currTime = 0;

    while (!orders.empty() || !recieveTimer.empty())
    {        
        if (!orders.empty())
        {
            currTime += orders.top().executionTime;
            cout << orders.top().index << ' ';
            orders.pop();
        }

        while (!recieveTimer.empty() && currTime >= recieveTimer.top().receiveTime)
        {
            orders.push(recieveTimer.top());
            recieveTimer.pop();
        }

        if (!recieveTimer.empty() && orders.empty())
            currTime = recieveTimer.top().receiveTime;
    }

    return 0;
}