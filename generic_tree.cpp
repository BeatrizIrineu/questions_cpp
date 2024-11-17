#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

struct tree {
    tuple<int, int> node_id;
    tree* parent;
    vector<tree*> children;
    int value; 

    tree(tuple<int, int> id, int val, tree* prt){
        node_id = id;
        value = val;
        parent = prt;
    };
} ;

int sumTree(tree* aux, vector<tuple<int, int>> in, int resultados_tuplas[]){
    int sum = 0;

    int children = (aux->children).size(); 

    if ( children == 0){
        return aux->value;
    }

    for (int i = 0; i < children; i++){
        sum = sum + sumTree(aux->children[i], in, resultados_tuplas);
    }
    for (int i = 0; i < in.size(); ++i) {
        if (aux->node_id == in[i]) { 
            resultados_tuplas[i] = sum; 
        }
    }
    return sum;
}

void addChild(tree* parent, tuple<int, int> id_node, int value) {
    tree* child = new tree(id_node, value, parent);
    parent->children.push_back(child);
}

int main(){

    vector <tuple <int, int>> in; 
    in.push_back(make_tuple(1, 1));
    in.push_back(make_tuple(2, 3));
    in.push_back(make_tuple(2, 2));
    
    int resultado_tuplas[in.size()] ;

    int n = 3; 

    tree* root = new tree(make_tuple(1,1), 0, nullptr);

    addChild(root, std::make_tuple(2, 1), 4);
    addChild(root, std::make_tuple(2, 2), 0); 
    addChild(root, std::make_tuple(2, 3), 0); 

    addChild(root->children[1], std::make_tuple(3, 1), 2);
    addChild(root->children[1], std::make_tuple(3, 2), 8);
    addChild(root->children[2], std::make_tuple(3, 3), 5);


    int sum = 0;

    sumTree(root, in, resultado_tuplas); 
  
    for (int i = 0; i < in.size(); i++){
        cout << "In: " << "(" << get<0>(in[i] ) << ", " << get<1>(in[i] ) << ")" << " Total: "<< resultado_tuplas[i] << endl;
    }
   
    return 0;
}
