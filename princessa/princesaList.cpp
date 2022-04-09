#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int>::iterator next(list<int>& alive, list<int>::iterator it){
    it++;
    if(it == alive.end())
        return alive.begin();
    return it;
    
}

void show(list<int>& list){
    cout << "[";
    bool first = true;
    for(auto element : list){
        if(first)
            first = false;
        else
            cout << " ";
        cout << element; 
    }
    cout << "]" << endl;
};

int main(){

    int size = 0;
    cin >> size;

    list<int> alive;

    for (int i = 1; i <= size; i++) {
        alive.push_back(i);
    }

    int chosen_one = 0;
    cin >> chosen_one;

    show(alive);
    
    auto it = alive.begin();
    while(*it != chosen_one){
        it++;
    }

    while(alive.size() > 1){
        auto gonna_die = next(alive, it);
        it = alive.erase(gonna_die); 
        if(it == alive.end())
            it = alive.begin();
        show(alive);
    }

    return 0;
}
