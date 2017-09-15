#include <iostream>

int pow(int a, int n){
	return n==0 ? 1 : a * pow(a, n-1);
}

void showTN(int N, int X){
	int i,j,k=pow(X+1, N), sum, flag;
	int stack[9]={};

	for(i=1;i<=k;++i){
		// Get the sum of the stack element
		sum = 0, flag = 1;
		for(j=0;j<N;++j){
			sum += stack[j];
			if(sum>X){
				flag = 0;
				break;
			}
		}

		// Isn't the sum more than X?
		if(flag){
			// If not, Print the stack backwards.
			for(j=N-1;j>=0;--j)
				std::cout << stack[j];
			std::cout<<std::endl;
		}	

		// Add one
		++stack[0];
		for(j=0;j<N;++j)
			if(stack[j]>X){
				stack[j+1]+=1;
				stack[j]=0;
			}
	}
}

void rec(int arr[], int N, int X, int level=0, int sum=0){
	int i;
	if(level>=N){
		for(i=0;i<N;++i) std::cout << arr[i];
		std::cout << std::endl;
		return;
	}
	
	for(i=0;i<=X;++i){
		if(sum+i<=X){
			arr[level]=i;
			rec(arr, N, X, level+1, sum+i);
		}
	}
}

void showTN_recursive(int N, int X){
	int arr[8]={};
	rec(arr,N,X);
}

int main(){
	int N, X;
	std::cin >> N >> X;
	showTN(N, X);
	showTN_recursive(N, X);
}
