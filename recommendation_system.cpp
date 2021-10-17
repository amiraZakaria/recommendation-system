#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

// Initialize an adjacency List with static length
const int N = 1e5+3;
int n;
vector<int> adj[N];
int src;
// This function adds edges between given vertices (undirected edge)
void add_undirected_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


// Initialize an array to mark visited vertices
bool vis_bfs[N];

// This function traverses the graph in breadth first search
void recommend(int src) {
    memset(vis_bfs,0,sizeof vis_bfs );

    queue<int> q;
    // push and mark the source node as visited
    q.push(src);
    vis_bfs[src] = true;
	// loop to print all vertices in the graph
    while (!q.empty()) {
        int u = q.front();
        // pop and print the front node
        q.pop();

        if( u!=src && !count(adj[src].begin(),adj[src].end(),u)){
             if (u==1){cout <<"Amira ";}
        else if (u==2){cout <<"Samaa ";}
        else if (u==3){cout <<"Esraa ";}
        else if (u==4){cout <<"Rana " ;}
        else if (u==5){cout <<"Salma ";}
        else if (u==6){cout <<"Dalia ";}
        else if (u==7){cout <<"Malak ";}
        else if (u==8){cout <<"Bebo ";}}

		// loop for all neighbors of the vertex u
        for (int v : adj[u]) {
            if (vis_bfs[v] == false) {
                // push and mark the current node as visited
                q.push(v);
                vis_bfs[v] = true;
            }
        }
    }
}

// Initialize an array to mark visited vertices

bool is_connected_node(int i , int j){
    for(int u : adj[i]){
        if(u==j){return true;}
    }
    return false;
}

// This function traverses the graph in breadth first search
void high_recommend(int src) {
    bool vis_bfs[N];
    memset(vis_bfs,0,sizeof vis_bfs );
    set<int> s;
    set<int> f;
    queue<int> q;
    vis_bfs[src] = true;
    for (int v : adj[src]) {
        q.push(v);
        f.insert(v);
        vis_bfs[v] = true;
    }

	// loop to print all vertices in the graph
    while (!q.empty()) {
        int u = q.front();
        // pop and print the front node
        q.pop();
		// loop for all neighbors of the vertex u
        for (int v : adj[u]) {
            if (vis_bfs[v] == false) {
                // push and mark the current node as visited
                s.insert(v);
                vis_bfs[v] = true;
            }
        }
    }

    map<int,int> m;

    for (int i : s){
        int counter = 0 ;
        for(int j : f){
            if(is_connected_node(i,j)){counter+=1;}
        }
        m[i]=counter;
    }

    for(auto it : m ){
        if(it.second>1)
        {
             if (it.first==1){cout <<"Amira ";}
        else if (it.first==2){cout <<"Samaa ";}
        else if (it.first==3){cout <<"Esraa ";}
        else if (it.first==4){cout <<"Rana " ;}
        else if (it.first==5){cout <<"Salma ";}
        else if (it.first==6){cout <<"Dalia ";}
        else if (it.first==7){cout <<"Malak ";}
        else if (it.first==8){cout <<"Bebo ";}}

        }
       // cout<< it.first<<" "<< it.second<< endl;
    }


void usermenu(int src){

    while(1){

    cout << "**************************\n" << endl;
    cout << "                          WELCOME TO USER SECTION \n                          \n" << endl;
    cout << "**************************\n" << endl;
    jump:
    cout<<"\n1.recommend mutual friends  ";
    cout<<"\n2.recommend friends ";
    cout<<"\n\nEnter your choice.. ";

        int choice;
        cin>>choice;

        switch(choice){
      case 1:
          high_recommend(src);

        break;
      case 2:
          recommend(src);
        break;}

    cout<<"\n1.add friend : "; // from num to num
    cout<<"\n2.exit ";
    cout<<"\n\nEnter your choice.. "; // num line + text

       int choice2;
         string friends;
        cin>>choice;

        switch(choice){
      case 1:
        cout<<"\n\nEnter your friend : ";
        cin>>friends;
             if (friends=="Amira" ){add_undirected_edge(1,src);}
        else if (friends=="Samaa" ){add_undirected_edge(2,src);}
        else if (friends=="Esraa" ){add_undirected_edge(3,src);}
        else if (friends=="Rana"  ){add_undirected_edge(4,src);}
        else if (friends=="Salma" ){add_undirected_edge(5,src);}
        else if (friends=="Dalia" ){add_undirected_edge(6,src);}
        else if (friends=="Malak" ){add_undirected_edge(7,src);}
        else if (friends=="Bebo"  ){add_undirected_edge(8,src);}
        goto jump;
        break;
        case 2:
          exit(0);
        break;
}}}

void mainmenu(){
     int pass; string name;
    cout << "**************************\n" << endl;
    cout << "                    WELCOME TO RECOMMENDATION SYSTEM\n                        \n" << endl;
    cout << "**************************\n" << endl;
    cout << "\nENTER YUOR NAME : ";
    cin>>name;
   // cout << "\nENTER YOUR -->2";
    cout << "\nENTER YOUR PASSWORD : ";
    cin>>pass;

             if (name=="Amira" && pass==123){src=1; usermenu(src);}
        else if (name=="Samaa" && pass==123){src=2; usermenu(src);}
        else if (name=="Esraa" && pass==123){src=3; usermenu(src);}
        else if (name=="Rana" && pass==123){src=4; usermenu(src);}
        else if (name=="Salma" && pass==123){src=5; usermenu(src);}
        else if (name=="Dalia" && pass==123){src=6; usermenu(src);}
        else if (name=="Malak" && pass==123){src=7; usermenu(src);}
        else if (name=="Bebo" && pass==123){src=8; usermenu(src);}
}

int main() {

    n = 8;

    add_undirected_edge(1, 2);
    add_undirected_edge(1, 3);
    add_undirected_edge(1, 4);

    add_undirected_edge(2, 5);
    add_undirected_edge(2, 6);

    add_undirected_edge(3, 6);
    add_undirected_edge(3, 7);
    add_undirected_edge(3, 8);

    while(1){
        mainmenu();
    }

}
