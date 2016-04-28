#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>

using namespace std;

struct Expression {
    string token;
    vector<Expression> args;

    Expression(string token) : token(token) {}
    Expression(string token, Expression a) : token(token), args({ a }) {}
    Expression(string token, Expression a, Expression b) : token(token), args({ a, b }) {}
};

class Parser {
public:
    Parser(const char* input) : input(input) {}
    Expression parse();
    static double eval(const Expression& e);
private:
    string parse_token();
    Expression parse_simple_expression();
    Expression parse_binary_expression(int min_priority);
    const char* input;

};