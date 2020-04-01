#include <iostream>
#include <algorithm>
#include <vector>
#define INF 10000001 // 100 * 100000 + 1 = 10000001
using Map = std::vector<std::vector<int>>;
Map d;

int getInput(){
	int N, M;
	int a, b, c;
	#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define INF ((INT_MAX) >> 2)
using Map = std::vector<std::vector<int>>;
Map d;

int getInput(){
	int N, M;
	int a, b, c;
	
	std::cin >> N >> M;
	d.assign(N, std::vector<int>(N, INF));

	while(M--){
		std::cin >> a >> b >> c;
		d[a][b] = std::min(d[a][b], c);
	}
	
	return N;
}

void Floyd(int N){
	for (int m = 0; m < N; m++) //가운데 노드
		for (int s = 0; s < N; s++) //시작 노드
			for (int e = 0; e < N; e++) //마지막 노드
				if (d[s][e] > d[s][m] + d[m][e])
					d[s][e] = d[s][m] + d[m][e]; //가운데를 거쳐가는 것이 더 빠르면 그걸로 업데이트한다.
}

void printResult(int N){
	for(auto i=0;i<N;++i){
		for(auto j=0;j<N;++j){
			std::cout << (d[i][j] != INF ? d[i][j] : 0);
		}
	}
}

int main(){
	std::ios_base.sync_with_stdio(false);
	std::cin.tie(false);
	std::cout.tie(false);
	
	int N = getInput();	
	Floyd(N);	
	printResult(N);
	return 0;
}
	std::cin >> N >> M;
	auto row = std::vector<int>();
	row.assign(N, INF);
	d.assign(N, row);

	for(auto i = 0; i < N; ++i)
		d[i][i] = 0;
	
	while(M--){
		std::cin >> a >> b >> c;
		// Zero-indexing
		a -= 1, b -= 1;
		d[a][b] = std::min(d[a][b], c);
	}
	
	return N;
}

void Floyd(int N){
	//가운데 노드
	for (int m = 0; m < N; m++){
		//시작 노드
		for (int s = 0; s < N; s++) {
			//마지막 노드
			for (int e = 0; e < N; e++) {
				if (d[s][e] > d[s][m] + d[m][e])
					d[s][e] = d[s][m] + d[m][e]; //가운데를 거쳐가는 것이 더 빠르면 그걸로 업데이트한다.
			}
		}
	}
}

void printResult(int N){
	for(auto i=0;i<N;++i){
		for(auto j=0;j<N;++j){
			std::cout << (d[i][j] != INF ? d[i][j] : 0) << " ";
		}
		std::cout << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int N = getInput();	
	Floyd(N);	
	printResult(N);
	return 0;
}