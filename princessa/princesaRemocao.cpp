#include <iostream>
#include <vector>

using namespace std;

void show(vector<int> vet, int sword){
    
    for(int i = 0; i < (int) vet.size(); i++)
        cout << vet[i] << (i == sword ? "> " : " ");
    
    cout << endl;
}

int main(){
    int size {0}, sword {0};

    cin >> size >> sword;
    vector<int> vet(size);

    for(int i = 0; i < size; i++)
        vet[i] = i + 1;

    sword -= 1;

    int count = vet.size() - 1;

    while(count--){
        show(vet, sword);
        sword = (sword + 1) % vet.size();
        vet.erase(vet.begin() + sword);
        sword = sword % vet.size();
    }
    show(vet, sword);
}