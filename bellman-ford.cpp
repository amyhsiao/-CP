vector<int> distance(n+1);
vector< tuple<int, int, int>> 

for(int i = 1; i <= n; i++) distance[i] = INF;
distance[x] = 0;
for(int i = 1; i <= n-1; i++){
	for(auto e : edges){
		int a, b, w;
		tie(a, b, w) = e;
		distance[b] = min(distance[b], distance[a] + w);
	}
}
