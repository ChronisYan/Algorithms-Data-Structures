#include <iostream>
#include <string>
#include <vector>

class Node
{
public:
    std::string name;
    std::vector<Node *> children;

    Node(std::string str) { name = str; }

    std::vector<std::string> depthFirstSearch(std::vector<std::string> *array)
    {
        array->push_back(this->name);
        for (int i = 0; i < this->children.size(); i++)
        {
            children[i]->depthFirstSearch(array);
        }
        return *array;
    }

    Node *addChild(std::string name)
    {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};

int main()
{
    Node graph("A");
    graph.addChild("B")->addChild("C")->addChild("D");
    graph.children[0]->addChild("E")->addChild("F");
    graph.children[2]->addChild("G")->addChild("H");
    graph.children[0]->children[1]->addChild("I")->addChild("J");
    graph.children[2]->children[0]->addChild("K");

    std::vector<std::string> result;
    graph.depthFirstSearch(&result);

    for (int i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}