#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <limits>

class Graph
{
private:
    std::map<std::string, int> vertexMap;
    std::vector<std::vector<float>> adjMatrix;
    const float INF = std::numeric_limits<float>::infinity();
    int nextIndex = 0;

    int getOrCreateVertexIndex(const std::string& vertex)
    {
        auto it = vertexMap.find(vertex);
        if (it != vertexMap.end())
        {
            return it->second;
        }
        else
        {
            vertexMap[vertex] = nextIndex++;
            for (auto& row : adjMatrix)
            {
                row.push_back(std::numeric_limits<float>::infinity()); // 表示未连接的边
            }
            adjMatrix.push_back(std::vector<float>(nextIndex, std::numeric_limits<float>::infinity()));
            return nextIndex - 1;
        }
    }

public:
    // 从简单输入初始化图
    void initFromSimpleInput(std::istream& input) {
        int numVertices, edgeStart, edgeEnd;
        float edgeWeight;

        input >> numVertices; // 读取顶点数
        for (int i = 0; i < numVertices; ++i) {
            getOrCreateVertexIndex(std::to_string(i)); // 创建顶点
        }

        while (input >> edgeStart >> edgeEnd >> edgeWeight) {
            int v = getOrCreateVertexIndex(std::to_string(edgeStart));
            int w = getOrCreateVertexIndex(std::to_string(edgeEnd));
            adjMatrix[v][w] = edgeWeight; // 添加边
            adjMatrix[w][v] = edgeWeight; // 因为输入似乎是无向图，所以添加另一个方向的边
        }
    }
    // 从文件初始化图
    void initFromFile(const std::string& filename)
    {
        std::ifstream file(filename);
        std::string line;

        while (std::getline(file, line))
        {
            if (line.substr(0, 5) != "Query")
                continue;

            std::istringstream iss(line);
            std::string vertexLabel;
            iss >> vertexLabel;

            iss >> vertexLabel;
            int v = getOrCreateVertexIndex(vertexLabel);

            while (!iss.eof())
            {
                std::string adjacentVertexLabel;
                float weight;
                iss >> adjacentVertexLabel >> weight;
                int w = getOrCreateVertexIndex(adjacentVertexLabel);
                adjMatrix[v][w] = weight; // 建立连接
            }
        }

        file.close();
    }

    // 打印图的邻接矩阵
    void printGraph()
    {
        for (int i = 0; i < adjMatrix.size(); ++i)
        {
            for (int j = 0; j < adjMatrix[i].size(); ++j)
            {
                if (adjMatrix[i][j] != std::numeric_limits<float>::infinity())
                {
                    std::cout << "Weight from " << getIndexVertex(i) << " to " << getIndexVertex(j) << " is " << adjMatrix[i][j] << std::endl;
                }
            }
        }
    }

    // 获取对应索引的顶点标签
    std::string getIndexVertex(int index)
    {
        for (auto& pair : vertexMap)
        {
            if (pair.second == index)
                return pair.first;
        }
        return ""; // 只有当没有找到相应索引时才会到达此处
    }

    void DFSUtil(int v, std::vector<bool>& visited)
    {
        visited[v] = true;
        std::cout << getIndexVertex(v) << " ";
        for (int i = 0; i < adjMatrix[v].size(); ++i)
        {
            if (!visited[i] && adjMatrix[v][i] != std::numeric_limits<float>::infinity())
            {
                DFSUtil(i, visited);
            }
        }
    }
    void DFS(const std::string& startVertex)
    {
        std::vector<bool> visited(nextIndex, false);

        int v = vertexMap[startVertex];
        DFSUtil(v, visited);
        std::cout << std::endl;
    }
    void BFS(const std::string& startVertex)
    {
        std::vector<bool> visited(nextIndex, false);

        std::queue<int> queue;

        int s = vertexMap[startVertex];
        visited[s] = true;
        queue.push(s);

        while (!queue.empty())
        {
            s = queue.front();
            std::cout << getIndexVertex(s) << " ";
            queue.pop();

            for (int i = 0; i < adjMatrix[s].size(); ++i)
            {
                if (!visited[i] && adjMatrix[s][i] != std::numeric_limits<float>::infinity())
                {
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }
        std::cout << std::endl;
    }

    void calculateMST()
    {
        // 假设我们使用 INT_MAX 来代表无限大，表示没有连接
        std::vector<int> parent(nextIndex, -1);                                    // 存储最小生成树
        std::vector<float> key(nextIndex, std::numeric_limits<float>::infinity()); // 用于选出边界上权重最小的顶点
        std::vector<bool> inMST(nextIndex, false);                                 // 追踪已经添加到MST的顶点

        // 从第一个顶点开始
        key[0] = 0;
        parent[0] = -1; // 第一个顶点总是MST的根

        for (int count = 0; count < nextIndex - 1; count++)
        {
            // 选择一个最小的键值，该顶点还没有添加到MST中
            int u = -1;
            float min = std::numeric_limits<float>::infinity();
            for (int v = 0; v < nextIndex; v++)
            {
                if (!inMST[v] && key[v] < min)
                {
                    min = key[v];
                    u = v;
                }
            }

            // 将选择的顶点添加到MST中
            inMST[u] = true;

            // 更新邻接顶点的键值和父指针
            for (int v = 0; v < nextIndex; v++)
            {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // 打印构成的最小生成树
        for (int i = 1; i < nextIndex; i++)
        {
            std::cout << getIndexVertex(parent[i]) << " - " << getIndexVertex(i) << " \t" << adjMatrix[i][parent[i]] << std::endl;
        }
    }
    // 修改图为无向图
    void makeUndirected()
    {
        for (int i = 0; i < nextIndex; ++i)
        {
            for (int j = 0; j < nextIndex; ++j)
            {
                if (adjMatrix[i][j] != INF)
                {
                    adjMatrix[j][i] = adjMatrix[i][j]; // 确保连接是双向的
                }
            }
        }
    }
    // 计算图的直径
    float calculateDiameter()
    {
        // 将图转换为无向
        makeUndirected();

        // 初始化所有最短路径长度为无穷大，除了那些顶点自己到自己的路径长度为0
        std::vector<std::vector<float>> dist = adjMatrix;
        for (int i = 0; i < nextIndex; ++i)
        {
            dist[i][i] = 0;
        }

        // Floyd-Warshall算法
        for (int k = 0; k < nextIndex; ++k)
        {
            for (int i = 0; i < nextIndex; ++i)
            {
                for (int j = 0; j < nextIndex; ++j)
                {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // 从最短路径长度中找到直径
        float diameter = 0;
        for (int i = 0; i < nextIndex; ++i)
        {
            for (int j = 0; j < nextIndex; ++j)
            {
                if (dist[i][j] != INF)
                {
                    diameter = std::max(diameter, dist[i][j]);
                }
            }
        }

        return diameter;
    }
};

int main()
{
    Graph g;
    std::istringstream input("5\n"  
        "0 1 1\n"  
        "0 2 1\n"
        "1 3 1\n"
        "2 3 1\n"
        "2 4 1\n"
        "3 4 1");

    // 初始化图
    g.initFromSimpleInput(input);

    // 测试深度优先搜索(DFS)
    g.DFS("0");

    // 测试广度优先搜索(BFS)
    g.BFS("0");

    std::cout << g.calculateDiameter() << std::endl;
    return 0;
}