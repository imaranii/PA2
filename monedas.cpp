#include <limits>
#include <algorithm>
#include <iostream>

int cambio(int N, int* v, int M){
	

	int** matrix = new int*[N];
	for(int i=0; i<N; i++){
    		matrix[i] = new int[M+1];
		for(int j = 0 ; j < M+1 ; j++){
			if(j == 0){
				matrix[i][j]=0;
			}
			else{
				matrix[i][j]=-1;
			}
		}
	}

	for(int  i = 0 ; i < N ; i++){
		std::cout<<"\n";
		for(int j = 0 ; j < M+1 ; j++){
			if(v[0] > j){
				matrix[i][j] = 0;
			}
			
			if(j%v[i] == 0 && j >= v[i]){
                               	matrix[i][j] = j/v[i];
			}
			else if(v[i] > j){
				matrix[i][j] = matrix[i-i][j];
			}
			else{
				matrix[i][j] = j/v[i] + matrix[i-1][j%v[i]];
			}

			if(i > 0){
			matrix[i][j] = std::min(matrix[i][j] , matrix[i-1][j]);
			}

			std::cout<<" "<< matrix[i][j];
		};
	};
	
	std::cout<<"\n";
	
	return 0;
}

int main(){
	int* o =new int[3];

	o[0] = 1;
	o[1] = 4;
	o[2] = 6;

	cambio(3 , o , 8);
	return 0;
};
