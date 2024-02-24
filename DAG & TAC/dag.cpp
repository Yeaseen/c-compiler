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
		
	}
	DAG_Node(string label, int l, int r){
		
		this->label = label;
		this->lChild= l;
		this->rChild= r;
		//this->dagIndex = 0;
	}
	DAG_Node(string label, int l, int r,int index){
		
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

}

void print_dag_array(){

	cout << "DAG ARRAY" << endl;
	for(int i=1;i<currIndex;i++){
			DAG_Node* temp=dag_array[i];
			cout<<dag_array[i]->dagIndex<<"-->  "<<dag_array[i]->label<<" "<<dag_array[i]->lChild<<" "<<dag_array[i]->rChild<<endl;
	}

	
}

void construct_tac() {
    cout << "THREE ADDRESS CODE" << endl;
    
    // Temporary variable for storing TAC lines to ensure ordered printing
    vector<string> tacLines(currIndex);

    for (int i = 1; i < currIndex; i++) {
        DAG_Node* node = dag_array[i];
        // Skip leaf nodes (operands), assuming they don't have children
        if (node->lChild == -1111 && node->rChild == -1111) {
            continue;
        }

        // Fetch operand labels. If an operand is not a leaf, refer to it by its temporary variable.
        string leftOperand = (node->lChild != -1111) ? "t" + itOa(dag_array[node->lChild]->dagIndex) : dag_array[node->lChild]->label;
        string rightOperand = (node->rChild != -1111) ? "t" + itOa(dag_array[node->rChild]->dagIndex) : dag_array[node->rChild]->label;

        // Generate the TAC line for this operation
        string tacLine = "t" + itOa(node->dagIndex) + " = " + leftOperand + " " + node->label + " " + rightOperand;
        
        // Store the TAC line in the vector for ordered printing
        tacLines[node->dagIndex] = tacLine;
    }

    // Print all TAC lines in order
    for (const string& line : tacLines) {
        if (!line.empty()) {
            cout << line << endl;
        }
    }
}


#endif
