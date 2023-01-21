/*
  Alejandro Hidalgo Badillo  A01423412
	Graph Coloring Implementation
	fecha de creacion
	8 10 2022
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
//inicio de funciones 

//funcion bubble sort la cual utilizamos para ordenar la matriz de entrada
vector<vector<int>> BubbleSort(vector<vector<int>> SortedArray,int size)
{
  vector<int> sort; //vector utilizado para cambiar de posicion los valores 

	/*
		se compone de dos ciclos for anidados y por ende tiene una complejidad O(n x n)
		Su complejidad se debe a que recorre todos los elementos en el vector de vectores
	*/
	
  for (int a=0;a<size-1;a++) {
    for (int b=0;b<size-1;b++) {
      
      if (SortedArray[b][0] < SortedArray[b+1][0]) {
        sort = SortedArray[b+1]; SortedArray[b+1] = SortedArray[b];
        SortedArray[b] = sort;
      }
      else if (SortedArray[b][0] == SortedArray[b+1][0] && SortedArray[b][1] > SortedArray[b+1][1]) {
        	sort = SortedArray[b+1]; SortedArray[b+1] = SortedArray[b];
        	SortedArray[b] = sort;
      }
    }
		}
  return SortedArray;
}

/*
funcion booleana complementaria de comprobacion de colores de grafo
retorna falso si el color se repite o verdadero si es nuevo el color
*/
bool ColorSearch(vector<int>nodes, vector<int> checkList,int color)
{
  for (int a=0;a<checkList.size();a++) { if ( checkList[a] == color && nodes[a] == 1)return false;}
	return true;
}//colorSearch tiene una complejidad lineal O(n)
/*
	funcion principal de coloreo de grafos
	tiene una complejidad de O(n x n) debido a que tiene dos ciclos anidados en su estructura principal
	*/
void GraphgColoring(int n, vector<vector<int>> matriz)
{
  vector<vector<int>> CopyMatrix;
	vector<int>  checkList;
	int color = 1;
	//auamentamos en tamano n los vectores complementarios utilizados
  checkList.resize(n);
  CopyMatrix.resize(n);
	
  for (int i = 0; i < n; i++) //creamos una copia de nuestro vector de vectores de tipo entero dado como entrada
	{
    CopyMatrix[i].push_back(count(matriz[i].begin(), matriz[i].end(), 1));
    CopyMatrix[i].push_back(i + 1);
  }
  CopyMatrix=BubbleSort(CopyMatrix, n); //llamamos a la funcion bubbleSort para ordenar los valores de entrada

  while (!CopyMatrix.empty()) //recorre todo el listado de valores hasta que este sea nulo
	{
    int pos = 0; int m = CopyMatrix.size();

    for (int i = 0; i < m; i++) {
      int nodo = CopyMatrix[pos][1] - 1;

			
      if (ColorSearch(matriz[nodo],checkList,color) && checkList[nodo]!=color) {
        checkList[nodo] = color; CopyMatrix.erase(CopyMatrix.begin() + pos);
				//comprobamos los colores existentes en el vector resultante 
      }
      else {
        pos++; //sumamos a la posicion 
      }
		}  color++; //aumentamos la cantidad de colores
  }
	
  for (int a=0;a<n;a++) //imprimimos la lista resultante de coloreo de grafos
	{
    cout<<"Node: "<<a+1<<", Color: "<<checkList[a]<<endl;
  }
}
//fin de las funciones
int main() {
	//declaracion de variables
	vector<vector<int>> nodos;
	string line;
	int cont = 0;
	int n;
	cin>>n;
	//almacenamiento de datos pertenecientes a la matriz
	getline(cin, line);
	 while (getline(cin, line)) {
		stringstream ss(line);  
		nodos.push_back(vector<int>());
		while (ss.good()) {
        string substr;
        getline(ss, substr,' ');
        nodos[cont].push_back(stoi(substr));
    }
		 cont++;
  }//guardar matriz
	GraphgColoring(n, nodos); //llamamos a la funcion principal de coloreo de grafos 
}
/*
el main tiene una complejidad O(n x n) debido a que utilizamos dos ciclos while para almacenar los valores de entrada

la complejidad que gobierna nuestro programa es de O(n x n) debido a que esta misma se presenta en el main como en el bubble sort y la funcion GraphColoring
*/