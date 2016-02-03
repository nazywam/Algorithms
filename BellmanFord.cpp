#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>


using namespace std;

struct Node  {
	int distanceFromSource, index;
	vector<pair<Node*, int> > roads;	

	Node(int i){
		index = i;
		distanceFromSource = INT_MAX;
	}
};

Node* nodes[1000];

void bellmanFord(Node* source){
	queue<Node*> que;
	que.push(source);
	while(!que.empty()){
		Node* current = que.front();
		que.pop();

		for(int x=0; x<current->roads.size(); x++){
			if(current->roads[x].first->distanceFromSource > current->distanceFromSource + current->roads[x].second){
				current->roads[x].first->distanceFromSource = current->distanceFromSource + current->roads[x].second;
				que.push(current->roads[x].first);
			}
		}
	}
}

int main(){
	
	int n, m, s; //no nodes, no connections, source node
	cin >> n >> m >> s;


	for(int x=0; x<n; x++){
		nodes[x] = new Node(x);
	}

	for(int x=0; x<m; x++){
		int from, to, wage;
		cin >> from >> to >> wage;

		nodes[from-1]->roads.push_back(make_pair(nodes[to-1], wage));
	}

	Node* source = nodes[s-1];
	source->distanceFromSource = 0;

	bellmanFord(source);

	cout << "Distance from " << source->index+1 << " to:" << endl;

	for(int x=0; x<n; x++){
		cout << x+1 << " = " << nodes[x]->distanceFromSource << endl;
	}
}