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
                row.push_back(std::numeric_limits<float>::infinity()); // ��ʾδ���ӵı�
            }
            adjMatrix.push_back(std::vector<float>(nextIndex, std::numeric_limits<float>::infinity()));
            return nextIndex - 1;
        }
    }

public:
    // �Ӽ������ʼ��ͼ
    void initFromSimpleInput(std::istream& input) {
        int numVertices, edgeStart, edgeEnd;
        float edgeWeight;

        input >> numVertices; // ��ȡ������
        for (int i = 0; i < numVertices; ++i) {
            getOrCreateVertexIndex(std::to_string(i)); // ��������
        }

        while (input >> edgeStart >> edgeEnd >> edgeWeight) {
            int v = getOrCreateVertexIndex(std::to_string(edgeStart));
            int w = getOrCreateVertexIndex(std::to_string(edgeEnd));
            adjMatrix[v][w] = edgeWeight; // ��ӱ�
            adjMatrix[w][v] = edgeWeight; // ��Ϊ�����ƺ�������ͼ�����������һ������ı�
        }
    }
    // ���ļ���ʼ��ͼ
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
                adjMatrix[v][w] = weight; // ��������
            }
        }

        file.close();
    }

    // ��ӡͼ���ڽӾ���
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

    // ��ȡ��Ӧ�����Ķ����ǩ
    std::string getIndexVertex(int index)
    {
        for (auto& pair : vertexMap)
        {
            if (pair.second == index)
                return pair.first;
        }
        return ""; // ֻ�е�û���ҵ���Ӧ����ʱ�Żᵽ��˴�
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
        // ��������ʹ�� INT_MAX ���������޴󣬱�ʾû������
        std::vector<int> parent(nextIndex, -1);                                    // �洢��С������
        std::vector<float> key(nextIndex, std::numeric_limits<float>::infinity()); // ����ѡ���߽���Ȩ����С�Ķ���
        std::vector<bool> inMST(nextIndex, false);                                 // ׷���Ѿ���ӵ�MST�Ķ���

        // �ӵ�һ�����㿪ʼ
        key[0] = 0;
        parent[0] = -1; // ��һ����������MST�ĸ�

        for (int count = 0; count < nextIndex - 1; count++)
        {
            // ѡ��һ����С�ļ�ֵ���ö��㻹û����ӵ�MST��
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

            // ��ѡ��Ķ�����ӵ�MST��
            inMST[u] = true;

            // �����ڽӶ���ļ�ֵ�͸�ָ��
            for (int v = 0; v < nextIndex; v++)
            {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }

        // ��ӡ���ɵ���С������
        for (int i = 1; i < nextIndex; i++)
        {
            std::cout << getIndexVertex(parent[i]) << " - " << getIndexVertex(i) << " \t" << adjMatrix[i][parent[i]] << std::endl;
        }
    }
    // �޸�ͼΪ����ͼ
    void makeUndirected()
    {
        for (int i = 0; i < nextIndex; ++i)
        {
            for (int j = 0; j < nextIndex; ++j)
            {
                if (adjMatrix[i][j] != INF)
                {
                    adjMatrix[j][i] = adjMatrix[i][j]; // ȷ��������˫���
                }
            }
        }
    }
    // ����ͼ��ֱ��
    float calculateDiameter()
    {
        // ��ͼת��Ϊ����
        makeUndirected();

        // ��ʼ���������·������Ϊ����󣬳�����Щ�����Լ����Լ���·������Ϊ0
        std::vector<std::vector<float>> dist = adjMatrix;
        for (int i = 0; i < nextIndex; ++i)
        {
            dist[i][i] = 0;
        }

        // Floyd-Warshall�㷨
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

        // �����·���������ҵ�ֱ��
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

    // ��ʼ��ͼ
    g.initFromSimpleInput(input);

    // ���������������(DFS)
    g.DFS("0");

    // ���Թ����������(BFS)
    g.BFS("0");

    std::cout << g.calculateDiameter() << std::endl;
    return 0;
}