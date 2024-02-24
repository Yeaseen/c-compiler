#include<string.h>
#include<string>
#include<bits/stdc++.h>
#ifndef DAG_INCLUDED
#define DAG_INCLUDED

using namespace std;


string itOa(int INT){
    ostringstream ss;
    ss<<INT;
    return ss.str();
}

string myHash(string lebel, int lIndex , int rIndex){
    return itOa(lIndex) + lebel + itOa(rIndex);
}

class DAG_Node{
public:
	string label;
	int lChild;
	int rChild;
	int dagIndex;

  DAG_Node(){
		this->label = "";
		this->lChild= -1111;
		this->rChild= -1111;
		this->dagIndex = 0;
		//write code here
	}
	DAG_Node(string label, int l, int r){
		//write code here
		this->label = label;
		this->lChild= l;
		this->rChild= r;
		//this->dagIndex = 0;
	}
	DAG_Node(string label, int l, int r,int index){
		//write code here
		this->label = label;
		this->lChild= l;
		this->rChild= r;
		this->dagIndex = index;
	}

	~DAG_Node(){
		//Write Code Here
	}
};

int currIndex=1; // Current entry in dag_array will be at currIndex
DAG_Node* dag_array[1000]; // Start from index 1
unordered_map <string,DAG_Node*> hashMap;


int constructNode(string label, int l, int r){

		string hashValue = myHash(label,l,r);
    unordered_map< string, DAG_Node* >::const_iterator it = hashMap.find(hashValue);
    if(it == hashMap.end()){
			DAG_Node* temp = new DAG_Node(label,l,r,currIndex);
			hashMap[hashValue] = temp;
			dag_array[currIndex++]= temp;
			return temp->dagIndex;
		}
		else{
			return it->second->dagIndex;
		}



	// Write code to implement value number method
	// You can Declare additional global variables and functions
	// You have to do hashing instead of searching linearly in the dag_array
	// STL can be used




}

void print_dag_array(){

	for(int i=1;i<currIndex;i++){
			DAG_Node* temp=dag_array[i];
			cout<<dag_array[i]->dagIndex<<"-->  "<<dag_array[i]->label<<" "<<dag_array[i]->lChild<<" "<<dag_array[i]->rChild<<endl;
	}

	// write code for printing a all entries of dag_array
	// you should print exactly in the way shown in sample output
}

void construct_tac(){
	// write code to construct and print three address code generated from dag
	// you should print exactly in the way shown in sample output

}

#endif
