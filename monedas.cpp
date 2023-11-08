#include <limits>
#include <algorithm>
#include <iostream>

int cambio(int N, int* v, int M) {


	int** matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[M + 1];
		for (int j = 0; j < M + 1; j++) {
			if (j == 0) {
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << "\n";
		for (int j = 0; j < M + 1; j++) {
			if (j == 0) {
				matrix[i][j] = 0;
			}
			else if (v[i] > j) {
				matrix[i][j] = 9;
			}
			else {
				if (j % v[i] == 0) {
					matrix[i][j] = j/v[i];
				}
				else if(i > 0){
					matrix[i][j] = j / v[i] + matrix[i - 1][j % v[i]];
				}
				else {
					matrix[i][j] = 9;
				}
			}


			if (i > 0) {
				matrix[i][j] = std::min(matrix[i][j], matrix[i - 1][j]);
			}

			std::cout << " " << matrix[i][j];
		};
	};

	std::cout << "\n";

	int consul;


	std::cin >> consul;
	int arr[3]{};
	int y = N-1;
	while (consul > 0) {
		if (consul < v[y]) {
			y--;
		}
		else {
			if (matrix[y][consul] == 1 + matrix[y][consul - v[y]]) {
				arr[y]++;
				consul -= v[y];
			}
			else {
				y--;
			}
		}
	}

	std::cout << arr[0] << " " << arr[1] << " " << " " << arr[2] << std::endl;

	return 0;
}

int main() {
	int* o = new int[3];

	o[0] = 1;
	o[1] = 4;
	o[2] = 6;

	cambio(3, o, 8);
	return 0;
};
