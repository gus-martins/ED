#include <iostream>
#include <sstream>
#include <vector>

struct Position {
    int lines, columns;
    Pos(int lines, int columns) {  } 
    bool operator == (Position position) { ... }
    bool operator != (Position position) { ... }
    std::string str() { ... }
};

std::ostream &operator << (std::ostream &os, Positon position) {
    return os << position.str();
}

template <class T>
class matrix {
    int nlines { 0 }, ncolumns { 0 };
    std::vector<std::vector<T>> data;

public:
    // construtor com todos os valores default nulos
    matrix(int nlines, int ncolumns) 
    { 
        for (int i = 0; i < nlines; i++){
            for (int j = 0; j < ncolumns; j++) {
                data.push_back(std::vector<T>());      
            }
            data.pushback(std::vector<T>());
        }
    } 

    // construtor passando o valor default de cada elemento
    matrix(int nlines, int ncolumns, T def) { ... } 

    //return number of lines
    int nlines() 
    { 
        return nlines; 
    }

    //return number of columns
    int ncols() 
    { 
        return ncolumns; 
    }

    // retorna elemento se passar posicão
    T& at(Position position) { ... }

    // retorna elemento se passar posicão
    T& operator[](Position position) { ... }

    // retorna linha
    std::vector<T> &operator[](int l) { ... }

    // retorna se posição está dentro da matrix
    bool inside(Position position) { ... }

    // retorna se essa posição existe e eh esse valor
    bool is_value(Position position, char value) { ... }

    //retorna string com valores separados por espaço
    std::string str() { ... }
};

//faz uma especialização para imprimir matrix de char
//sem espaços entre os elementos
template <>
std::string matrix<char>::str() { ... }

template <class T>
std::ostream& operator<<(std::ostream& os, matrix<T>& m) {
    return os << m.str();
}

int main() {
    {
        matrix<int> m(3, 4, 5);
        std::cout << m;
    }
    {
        matrix<char> m(3, 4, 'a');
        std::cout << m;
    }
    {
        matrix<int> m(3, 4);
        m[0][0] = 1; //acesso via vetor secundário
        m[{2, 2}] = 2; //acesso via posicao
        std::cout << m;
        std::cout << m.inside({-1, 2}) << '\n';//nao existe
        std::cout << m.is_value({2, 2}, 2) << '\n';//se eh esse valor
        std::cout << m.is_value({-1, 2}, 0) << '\n';
    }

}