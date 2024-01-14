#pragma once
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

class Graph {
    private:
        std::unordered_map<std::string, std::unordered_set<std::string>> adjList;

    public:
        bool addVertex(std::string vertex) {
            if (adjList.count(vertex) == 0) {
                adjList[vertex];
                return true;
            }
            return false;
        }

        bool addEdge(std::string vertex1, std::string vertex2) {
            if (adjList.count(vertex1) == 0 && adjList.count(vertex2) == 0) return false;
            adjList[vertex1].insert(vertex2);
            adjList[vertex2].insert(vertex1);
            return true;
        }

        bool removeEdge(std::string vertex1, std::string vertex2) {
            if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList[vertex1].erase(vertex2);
                adjList[vertex2].erase(vertex1);
                return true;
            }
            return false;
        }

        bool removeVertex(std::string vertex) {
            if (adjList.count(vertex) == 0) return false; 
            for (auto otherVertex: adjList[vertex]) {
                adjList[otherVertex].erase(vertex);
            }
            adjList.erase(vertex);
            return true;
        }

        void printGraph() {
            for (auto [vertex, edges] : adjList) {
                std::cout << vertex << ": [ ";
                for (auto edge: edges) {
                    std::cout << edge << " ";
                }
                std::cout << "]" << std::endl;
            }
        }
};