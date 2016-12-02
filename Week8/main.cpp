#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <tuple>
#include <limits>

using namespace std;

class GraphVertex{
public:
    GraphVertex(int value)
    {
        this->value=value;
        this->tentWeight = 0;
        this->previousVertex = NULL;
        cout << "Vertex Constructed with value: " << value << endl;
    }
    ~GraphVertex()
    {
        cout << "vertex deleted" << endl;
    }
    int value;
    //newly added and modified variables needed for weighting and Dijkstra
    int tentWeight;
    GraphVertex* previousVertex;
    //changed to a tuple so weights can be calculated
    list<tuple<GraphVertex*, int>> edges;
};

class Graph{
public:
    Graph()
    {
    }
    ~Graph()
    {
        for (list<GraphVertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        {
            delete *it;
        }
        cout << "graph deleted" << endl;
    }
    list<GraphVertex*> vertices;

    bool inGraph(int item)
    {
        for (list<GraphVertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        {
            GraphVertex* curVertex;
            curVertex = *it;
            if (curVertex->value == item)
            {
                return true;
            }
        }
        return false;
    }

    GraphVertex* getVertex(int item)
    {
        for (list<GraphVertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        {
            GraphVertex* curVertex;
            curVertex = *it;
            if (curVertex->value == item)
            {
                return curVertex;
            }
        }
        return NULL;
    }

    void addVertex(int item)
    {
        if (!inGraph(item))
        {
            vertices.emplace_back(new GraphVertex(item));
        }

    }

    void addEdge(int from, int to, int weight = 0)
    {
        /*
        modified function now incorporates weight
        Complexity: O(n) as before
        */

        if ( inGraph(from) && inGraph(to))
        {
            GraphVertex* fromVertex = getVertex(from);
            GraphVertex* toVertex = getVertex(to);
            fromVertex->edges.emplace_back(toVertex, weight);
            toVertex->edges.emplace_back(fromVertex, weight);
            cout << "Edge created between " << from << " and " << to << " with weight "<< weight << endl;;
        }
    }
};

list<GraphVertex*> dijkstra(Graph* graph, int start, int destination)
{
    /*
    A function that searches a given graph for the shortest distance between
    two given vertices and outputs a list of the shortest path found
    Complexity: O()
    */
    if (graph->inGraph(start) && graph->inGraph(destination))
    {
        GraphVertex* startVertex = graph->getVertex(start);
        GraphVertex* destVertex = graph->getVertex(destination);
        GraphVertex* v = startVertex;

        //Set the starting weights for every vertex in the graph
        for (list<GraphVertex*>::iterator it = graph->vertices.begin(); it != graph->vertices.end(); ++it)
        {
            GraphVertex* curVertex = *it;
            curVertex->tentWeight = numeric_limits<int>::max();
        }
        startVertex->tentWeight = 0;
        list<GraphVertex*> visited ={};

        //until we reach our destination vertex
        while (v != destVertex)
        {
            //search every neighbour of v and update the tentative weights of each
            for (list<tuple<GraphVertex*,int>>::iterator it = v->edges.begin(); it != v->edges.end(); ++it)
            {
                tuple<GraphVertex*,int> curEdge = *it;
                int curEdgeWeight = get<1>(curEdge);
                GraphVertex* curEdgeVertex = get<0>(curEdge);
                if (v->tentWeight + curEdgeWeight < curEdgeVertex->tentWeight)
                {
                    curEdgeVertex->tentWeight = v->tentWeight + curEdgeWeight;
                    curEdgeVertex->previousVertex = v;
                }
            }
            //add v to visited list
            visited.emplace_back(v);

            int minimum = numeric_limits<int>::max();

            //search every vertex for the vertex with the lowest tentative
            //weight that has not been visited and set v to that vertex
            for (list<GraphVertex*>::iterator it = graph->vertices.begin(); it != graph->vertices.end(); ++it)
            {
                GraphVertex* curVertex = *it;
                bool inVisited = false;
                for (list<GraphVertex*>::iterator it = visited.begin(); it != visited.end(); ++it)
                {
                    GraphVertex* newVertex = *it;
                    if (curVertex == newVertex)
                    {
                        inVisited = true;
                    }
                }
                if (!inVisited && curVertex->tentWeight < minimum)
                {
                    v = curVertex;
                    minimum = curVertex->tentWeight;
                }
            }
        }

        //Create return path output list
        GraphVertex* printVertex = destVertex;
        list<GraphVertex*> shortestPath = {};
        while (printVertex != startVertex)
        {
            shortestPath.emplace_front(printVertex);
            printVertex = printVertex->previousVertex;
        }
        shortestPath.emplace_front(startVertex);

        return shortestPath;
    }
    else
    {
        cout <<"invalid vertex selection" << endl;
        list<GraphVertex*> shortestPath = {};
        return shortestPath;
    }
}


int main()
{
    Graph* graph = new Graph();
    graph->addVertex(0);
    graph->addVertex(1);
    graph->addVertex(2);
    graph->addVertex(3);
    graph->addVertex(4);
    graph->addVertex(5);
    graph->addVertex(6);
    graph->addEdge(0,1,10);
    graph->addEdge(0,2,8);
    graph->addEdge(0,3,4);
    graph->addEdge(1,4,5);
    graph->addEdge(1,5,3);
    graph->addEdge(2,4,9);
    graph->addEdge(2,5,12);
    graph->addEdge(3,5,2);
    graph->addEdge(4,6,1);
    graph->addEdge(5,6,18);

    list<GraphVertex*> dijkstraResult = dijkstra(graph, 0, 6);

    for(list<GraphVertex*>::iterator it = dijkstraResult.begin(); it != dijkstraResult.end(); ++it)
    {
        GraphVertex* curVertex = *it;
        cout << curVertex->value;
    }
    cout << endl;

    delete graph;

    return 0;
}
