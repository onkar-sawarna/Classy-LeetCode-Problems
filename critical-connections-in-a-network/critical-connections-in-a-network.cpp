class Solution {
public:
    //this is the application of tarzan's algorithm
// the algorithm works in such a way that for every node is alloted a rank in increasing order
//as we get a cycle we start backtracking from that point and start returning the rank of the 
    //node in which cycle was being made till we get a rank less than the node on which the 
    //cycle was made
    int dfs(vector<vector<int>>& graph,int start,int rank,vector<int>& visited,
           vector<vector<int>>& res){
        visited[start]=rank;
        int t=INT_MAX,rv=INT_MAX;
        
        for(auto i:graph[start]){
            if(!visited[i]){
                t=dfs(graph,i,rank+1,visited,res);
                //if our current rank is less than that obtained from  dfs then its critical
                if(t>rank)
                    res.push_back({start,i});
            }
            else{
                //this is back edge that is, its deep in the cycle i.e current rank is greater
                //than the neigbor's rank+1
                if(rank>visited[i]+1)
                    t=visited[i];
            }
            rv=min(rv,t);
            }
        visited[start]=graph.size()+1;//just initialising with a value which will never be 
        //possible to compute from above
        return rv;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
          // Construct the graph
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);
        vector<vector<int>> res;
        
        for(int i = 0; i < connections.size(); i++) {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        // Ready to do a DFS
        //starting node index = 0, starting node rank=1
       dfs(graph, 0, 1, visited, res);
        
        return res;
    }
};