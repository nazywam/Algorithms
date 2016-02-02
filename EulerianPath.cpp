#include <iostream>
#include <vector>

using namespace std;

struct Node  {
	int index;
	vector<Node*> outcomingConnections;
	vector<Node*> incomingConnections;
	
	Node(int i){
		index = i;
	}
};

Node* nodes[1000];
bool visited[1000];

void dfs(Node* current, bool inverted){
	visited[current->index] = true;

	if(!inverted){
		for(int i=0; i<current->outcomingConnections.size(); i++){
			if(!visited[current->outcomingConnections[i]->index]){
				dfs(current->outcomingConnections[i], inverted);
			}
		}
	} else {
		for(int i=0; i<current->incomingConnections.size(); i++){
			if(!visited[current->incomingConnections[i]->index]){
				dfs(current->incomingConnections[i], inverted);
			}
		}
	}
}

void findEulerianPath(Node* current, vector<Node*>* path){
	while(current->outcomingConnections.size()!=0){
		Node* next = current->outcomingConnections.back();
		current->outcomingConnections.erase(current->outcomingConnections.end()-1);
		findEulerianPath(next, path);
	}
	path->push_back(current);
}

//finds a Eulerian path in a directed graph
//Usage:
// Input:
// nodes, connections
// (path from, to)X connections
// Output:
// Eulerian path 

int main(){

	int n, m;
	cin >> n >> m;


	for(int x=0; x<n; x++){
		nodes[x] = new Node(x);
		visited[x] = false;
	}

	for(int x=0; x<m; x++){
		int from, to;
		cin >> from >> to;

		nodes[from-1]->outcomingConnections.push_back(nodes[to-1]);
		nodes[to-1]->incomingConnections.push_back(nodes[from-1]);
	}

	bool meetsCondition = true;

	dfs(nodes[0], false);
	for(int x=0; x<n; x++){
		if(!visited[x]){
			meetsCondition = false;
		}
	 	visited[x] = false;
	}

	dfs(nodes[0], true);
	for(int x=0; x<n; x++){
		if(!visited[x]){
			meetsCondition = false;
		}
	}

	if(!meetsCondition){
		cout << "-1" << endl; //Graph is not connected, doesn't meet the needed condition
		return 0;
	}

	for(int x=0; x<n; x++){
		if(nodes[x]->incomingConnections.size() != nodes[x]->outcomingConnections.size()){
			meetsCondition = false;
			break;
		}
	}

	if(!meetsCondition){
		cout << "-1" << endl; //Outgoing connections don't equal incoming connections, doesn't meet the needed condition
		return 0;
	}

	vector<Node*>* EulerianPath = new vector<Node*>();
	findEulerianPath(nodes[0], EulerianPath);

	for(int x=EulerianPath->size()-1; x>=0; x--){ //nodes are in reversed order
		cout << (EulerianPath->at(x))->index+1 << " ";
	}
	cout << endl;

}