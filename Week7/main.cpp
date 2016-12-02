#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <fstream>

using namespace std;

// Task 13

//Class for an individual Vertex
class GraphVertex{
public:
    GraphVertex(int value)
    {
        this->value=value;
        cout << "Vertex Constructed with value: " << value << endl;
    }
    ~GraphVertex()
    {
        cout << "Vertex Deleted" << endl;
    }
    //used as both the data and unique id
    int value;
    //list of neighbouring vertices
    list<GraphVertex*> edges;
};

//Class for the Graph structure itself
class Graph{
public:
    Graph()
    {
        //empty constructor - not sure if required
    }
    ~Graph()
    {
        for (list<GraphVertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        {
            delete *it;
        }
        cout << "graph deleted" << endl;
    }
    //list of all the vertices in the graph
    list<GraphVertex*> vertices;

    bool inGraph(int item)
    {
        /*
        A method to return whether a vertex of given value exists within the graph
        Complexity: O(n) due to single for loop
        */

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
        /*
        A method to fetch the vertex of given value within the graph
        Complexity: O(n) due to single for loop
        */

        for (list<GraphVertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        {
            GraphVertex* curVertex = *it;
            if (curVertex->value == item)
            {
                return curVertex;
            }
        }
        return NULL;
    }

    void addVertex(int item)
    {
        /*
        A method to add a vertex of given value to the graph
        Complexity: O(1) emplace_back is constant
        */

        if (!inGraph(item))
        {
            vertices.emplace_back(new GraphVertex(item));
        }
    }

    void addEdge(int from, int to)
    {
        /*
        A method to add an edge between two given vertices in the graph
        Complexity: O(n) due to use of methods inGraph and getVertex
        */

        if ( inGraph(from) && inGraph(to))
        {
            GraphVertex* fromVertex = getVertex(from);
            GraphVertex* toVertex = getVertex(to);

            //Find if edge already exists between the given vertices
            bool edgeExists = false;
            for (list<GraphVertex*>::iterator it = fromVertex->edges.begin(); it != fromVertex->edges.end(); ++it)
                {
                GraphVertex* curVertex = *it;
                if (curVertex->value == toVertex->value)
                {
                    edgeExists = true;
                }
            }

            //if it does not create the edge
            if (!edgeExists)
            {
               fromVertex->edges.emplace_back(toVertex);
                toVertex->edges.emplace_back(fromVertex);
                cout << "Edge created between " << from << " and " << to << endl;
            }
        }
    }
};

// Task 14

list<GraphVertex*> depthFirstSearch(Graph* graph, int start)
{
    /*
    A function that searches a given graph from a given start point
    using a depth first approach
    Complexity: O(n^2) due to nested loops
    */
    stack<GraphVertex*> myStack;
    list<GraphVertex*> visited = {};
    GraphVertex* startVertex = graph->getVertex(start);

    myStack.push(startVertex);
    while (!myStack.empty())
    {
        GraphVertex* u = myStack.top();
        myStack.pop();

        //Find out if the visited list contains the vertex u and store result
        //in isIn
        bool isIn = false;
        for (list<GraphVertex*>::iterator it = visited.begin(); it != visited.end(); ++it)
        {
            GraphVertex* curVertex = *it;
            if (u->value == curVertex->value)
            {
                isIn = true;
            }
        }

        if (isIn == false)
        {
            //add vertex u to visited list and add all its
            //neighbouring vertices to the stack
            visited.emplace_back(u);
            for (list<GraphVertex*>::iterator it = u->edges.begin(); it != u->edges.end(); ++it)
            {
                myStack.push(*it);
            }
        }
    }
    return visited;
}

list<GraphVertex*> breadthFirstSearch(Graph* graph, int start)
{
    /*
    A function that searches a given graph from a given start point
    using a breadth first approach
    Complexity: O(n^2) due to nested loops
    */

    queue<GraphVertex*> myQueue;
    list<GraphVertex*> visited = {};
    GraphVertex* startVertex = graph->getVertex(start);

    myQueue.push(startVertex);
    while (!myQueue.empty())
    {
        GraphVertex* u = myQueue.front();
        myQueue.pop();

        //Find out if the visited list contains the vertex u and store result
        //in isIn
        bool isIn = false;
        for (list<GraphVertex*>::iterator it = visited.begin(); it != visited.end(); ++it)
        {
            GraphVertex* curVertex = *it;
            if (u->value == curVertex->value)
            {
                isIn = true;
            }
        }

        if (isIn == false)
        {
            //add vertex u to visited list and add all its
            //neighbouring vertices to the queue
            visited.emplace_back(u);
            for (list<GraphVertex*>::iterator it = u->edges.begin(); it != u->edges.end(); ++it)
            {
                myQueue.push(*it);
            }
        }
    }
    return visited;
}

int main()
{
    //open a file called Output.txt for output, if it already exists
    //overwrite any old data
    ofstream myFile ("Output.txt", ios::out | ios::trunc);
    Graph* graph = new Graph();
    graph->addVertex(1);
    graph->addVertex(2);
    graph->addVertex(3);
    graph->addVertex(4);
    graph->addVertex(5);
    graph->addEdge(1,2);
    graph->addEdge(1,3);
    graph->addEdge(2,5);
    graph->addEdge(3,4);
    graph->addEdge(3,5);

    list<GraphVertex*> dfsResult = depthFirstSearch(graph, 1);
    list<GraphVertex*> bfsResult = breadthFirstSearch(graph, 1);

    if (myFile.is_open())
    {
        myFile << "Depth First Search Result: ";
        for(list<GraphVertex*>::iterator it = dfsResult.begin(); it != dfsResult.end(); ++it)
        {
            GraphVertex* curVertex = *it;
            myFile << curVertex->value;
        }
        myFile << endl;

        myFile << "Breadth First Search Result: ";
        for(list<GraphVertex*>::iterator it = bfsResult.begin(); it != bfsResult.end(); ++it)
        {
            GraphVertex* curVertex = *it;
            myFile << curVertex->value;
        }
        myFile << endl;
        myFile.close();
        cout << "Results saved to Output.txt" << endl;
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    delete graph;
    return 0;
}
