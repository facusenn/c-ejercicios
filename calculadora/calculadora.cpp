#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

int main() {
    std::string linea;
    std::cout << "Introduce operación (ejemplo 9x9, 5/0, 3+4, 7-2): ";
    if (!std::getline(std::cin, linea)) return 0;

    // eliminar espacios
    std::string s;
    for (char c : linea) if (!std::isspace((unsigned char)c)) s += c;

    double a = 0, b = 0;
    char op = '\0';
    size_t pos = std::string::npos;
    for (size_t i = 0; i < s.size(); i++) {
        if ((s[i] == '+' || s[i] == '-' || s[i] == 'x' || s[i] == 'X' || s[i] == '*' || s[i] == '/') && i > 0) {
            op = s[i];
            pos = i;
            break;
        }
    }

    if (op == '\0' || pos == std::string::npos) {
        std::cout << "Formato invalido.\n";
        return 0;
    }

    try {
        a = std::stod(s.substr(0, pos));
        b = std::stod(s.substr(pos + 1));
    } catch (...) {
        std::cout << "Numeros no validos.\n";
        return 0;
    }

    if ((op == '/' ) && b == 0.0) {
        std::cout << "Error: division por 0.\n";
        return 0;
    }

    double resultado = 0;
    switch (op) {
        case '+': resultado = a + b; break;
        case '-': resultado = a - b; break;
        case 'x': case 'X': case '*': resultado = a * b; break;
        case '/': resultado = a / b; break;
        default:
            std::cout << "Operador no soportado.\n";
            return 0;
    }

    std::cout << linea << " = " << resultado << "\n";
    return 0;
}