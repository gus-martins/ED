#include <iostream>
#include <vector>

using namespace std;

const int dead = 0;

//find the next element alive from the beginning + 1;
int next_alive(vector<int> vet, int begin){
    int position = (begin + 1) % vet.size();
        
        while(vet[position] == dead)
            position = (position + 1) % vet.size();
    
    return position;

};

void show(vector<int> vet){
    cout << "[";
    bool first = true;
    for (int i = 0; i < vet.size(); i++){
        if(vet[i] != dead){
            if(first)
                first = false;
            else
                cout << " ";

            cout << vet[i];
        }
    }
    cout << "]\n";  
};

int main() {

    int size = 0;
    cin >> size;

    vector<int> vet(size);

    for (int i = 0; i < vet.size(); i++) {
        vet[i] = i + 1;
    }

    int chosen_one = 0;
    cin >> chosen_one;
    chosen_one = chosen_one - 1;

    show(vet);
    int count = vet.size() - 1;

    while(count--){
        int gonna_die = next_alive(vet,chosen_one);
        vet[gonna_die] = 0;
        chosen_one = next_alive(vet, gonna_die);
        show(vet);
    }

    return 0;
}