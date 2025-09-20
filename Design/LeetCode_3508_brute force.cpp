/*Design a data structure that can efficiently manage data packets in a network router. Each data packet consists of the following attributes:

source: A unique identifier for the machine that generated the packet.
destination: A unique identifier for the target machine.
timestamp: The time at which the packet arrived at the router.
Implement the Router class:

Router(int memoryLimit): Initializes the Router object with a fixed memory limit.

memoryLimit is the maximum number of packets the router can store at any given time.
If adding a new packet would exceed this limit, the oldest packet must be removed to free up space.
bool addPacket(int source, int destination, int timestamp): Adds a packet with the given attributes to the router.

A packet is considered a duplicate if another packet with the same source, destination, and timestamp already exists in the router.
Return true if the packet is successfully added (i.e., it is not a duplicate); otherwise return false.
int[] forwardPacket(): Forwards the next packet in FIFO (First In First Out) order.

Remove the packet from storage.
Return the packet as an array [source, destination, timestamp].
If there are no packets to forward, return an empty array.
int getCount(int destination, int startTime, int endTime):

Returns the number of packets currently stored in the router (i.e., not yet forwarded) that have the specified destination and have timestamps in the inclusive range [startTime, endTime].
Note that queries for addPacket will be made in increasing order of timestamp.*/

//Time Complexity -- O(logk)

class Router {
public:
    queue<vector<int>>q;
    int memoryLimit;
    map<vector<int>,int>m;
    unordered_map<int,multiset<int>>m_des;
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int>v;
        v.push_back(source);
        v.push_back(destination);
        v.push_back(timestamp);
        if(m.count(v)){
            return false;
        }
        if(q.size()==memoryLimit){
            vector<int>oldestpacket = q.front();
            q.pop();
            m.erase(oldestpacket);
            auto it = m_des[oldestpacket[1]].find(oldestpacket[2]);
            m_des[oldestpacket[1]].erase(it);
        }
        q.push(v);
        m[v]++;
        m_des[destination].insert(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int>packetforward;
        if(q.size()!=0){
            packetforward = q.front();
            q.pop();
            m.erase(packetforward);
            auto it = m_des[packetforward[1]].find(packetforward[2]);
            m_des[packetforward[1]].erase(it);
        }
        return packetforward;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &ms = m_des[destination];
        return distance(ms.lower_bound(startTime),ms.upper_bound(endTime));
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
