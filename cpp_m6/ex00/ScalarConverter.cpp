#include "ScalarConverter.hpp"

ScalarConvert::ScalarConvert(){}

ScalarConvert::ScalarConvert(const ScalarConvert& copy){
    (void)copy;
}

ScalarConvert& ScalarConvert::operator=(const ScalarConvert& copy){
    (void)copy;
    return *this;
}

ScalarConvert::~ScalarConvert(){}

static int ischar(std::string literal){
    if (literal.length() == 1 && std::isprint(literal[0])
            && !std::isdigit(literal[0]))
        return (1);
    return (0);

}

static int ispseudo(std::string literal){
    if (literal == "nanf" || literal == "+inff" || literal == "-inff" ||
        literal == "nan" || literal == "+inf" || literal == "-inf")
        return (1);
    return (0);
}

static int isint(std::string literal){
    size_t j = 0;
    if (literal[0] == '+' || literal[0] == '-')
        j++;
    for (size_t i = j; i < literal.length(); i++){
        if (!std::isdigit (literal[i]))
            return (0);
    }
    return (1);
}

static int isfloat(std::string literal){
    size_t i = 0;
    int countDot = 0;

    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (literal[i] == '.' || literal[literal.length() - 1] == '.')
        return 0;
    if (literal[literal.length() - 1] != 'f')
        return (0);
    for (; i < literal.length() - 1; i++){
        if (literal[i] == '.')
            countDot++;
        else if (!std::isdigit (literal[i]))
            return (0);
    }
    if (countDot != 1)
        return (0);
    if (literal.length() <= 2 || literal == ".f" || literal == "+.f" || literal == "-.f")
        return (0);
    return (1);
}

static int isdouble(std::string literal){
    size_t i = 0;
    int countDot = 0;

    if (literal[0] == '+' || literal[0] == '-')
        i++;
    if (literal[i] == '.' || literal[literal.length() - 1] == '.')
        return 0;
    for (; i < literal.length(); i++){
        if (literal[i] == '.')
            countDot++;
        else if (!std::isdigit (literal[i]))
            return (0);
    }
    if (countDot != 1)
        return (0);
    return (1);
}

static void printPseudo(std::string literal){
    if (literal == "nan" || literal == "nanf")
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: nanf\n"
                << "double: nan\n";
    else if (literal == "+inf" || literal == "+inff")
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: +inff\n"
                << "double: +inf\n";
    else if (literal == "-inf" || literal == "-inff")
        std::cout << "char: impossible\n" << "int: impossible\n" << "float: -inff\n"
                << "double: -inf\n";
}

static void printChar(char c){
    std::cout << "char: " << c << std::endl
                << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void printInt(long l){
    if (l < 0 || l > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(l))
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(l) << std::endl;

    if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(l) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(l) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(l) << std::endl;
}

static void printFloat(double d){

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: non displayable" << std::endl;
    else
    std::cout << "char: " << static_cast<char>(d) << std::endl;

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(d) << std::endl;
}

static void printDouble(double d){

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<int>(d)))
        std::cout << "char: non displayable" << std::endl;
    else
    std::cout << "char: " << static_cast<char>(d) << std::endl;

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}

void ScalarConvert::convert(std::string literal){
    if (ischar(literal)){
        char c = literal[0];
        printChar(c);
    }
    else if (ispseudo(literal)){
        printPseudo(literal);
    }
    else if (isint(literal)){
        long l = std::atol(literal.c_str());
        printInt(l);
    }
    else if (isfloat(literal)){
        double f = (std::atof(literal.c_str()));
        printFloat(f);
    }
    else if (isdouble(literal)){
        double d = std::atof(literal.c_str());
        printDouble(d);
    }
    else{
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: impossible\n"
                  << "double: impossible\n";
    }
}
