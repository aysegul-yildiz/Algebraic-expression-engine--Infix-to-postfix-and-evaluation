#ifndef ALGEBRAIC_EXPRESSION_H
#define ALGEBRAIC_EXPRESSION_H

#include <string>

std::string infix2postfix(const std::string exp);
double evaluatePostfix(const std::string exp);

#endif
