#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void clear_array(int** T, int dim_A, int dim_B){
	for(int i=0; i<dim_A; i++)
		for(int j=0; j<dim_B; j++)
			T[i][j]=0;
}

class arr2{//2D dynamic array
	int a_len, b_len;
public:
	int **p;
	arr2(int a_len, int b_len):a_len(a_len), b_len(b_len){
		p=(int**)malloc(a_len*sizeof(int*)+a_len*b_len*sizeof(int));
		int *ptr=(int*)(p+a_len);
		for(int i=0; i<a_len; i++)
			p[i]=ptr+i*b_len;
	}
	~arr2(){
		free(p);
	}
	void clear(){
		for(int i=0, count=0; i<a_len; i++)
			for(int j=0; j<b_len; j++, count++)
				p[i][j]=0;
	}
	void init(){
		for(int i=0, count=0; i<a_len; i++)
			for(int j=0; j<b_len; j++, count++)
				p[i][j]=count;
	}
	void print(){
		for(int i=0; i<a_len; i++){
			for(int j=0; j<b_len; j++)
				cout << p[i][j] << ' ';
			cout << '\n';
		}
	}
	int*& operator[](int i){
		return p[i];
	}
};

int main(){
	//string A, B;
	char A[1001], B[1001];
	while(cin.getline(A, 1001), cin.getline(B, 1001)){
		//int a_len=A.length(), b_len=B.length();
		int a_len=strlen(A), b_len=strlen(B);
		arr2 p(a_len+1, b_len+1);
		p.clear();//Try using calloc of memset?
		for(int i=0; i<a_len; i++)
			for(int j=0; j<b_len; j++)
				if(A[i]==B[j])
					p[i+1][j+1]=p[i][j]+1;
				else p[i+1][j+1]=max(p[i][j+1], p[i+1][j]);
		cout << p[a_len][b_len] << '\n';
	}
}
