#include "BitcoinExchange.hpp"

/* Canonical form*/
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db(other.db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        db = other.db;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/*load the data base file into a map container*/
bool BitcoinExchange::loadDataBase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file.\n";
        return false;
    }

    std::string line;
    if (!std::getline(file, line))
        return false;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        double rate = atof(line.substr(pos + 1).c_str());
        db[date] = rate;
    }

    file.close();
    return true;
}

/*parse the inputfile that contain an amount(value) of btc in a corresponding date*/
void BitcoinExchange::parseInputFile(const std::string& InputFile){

    std::ifstream file(InputFile.c_str());
    if (!file.is_open()){
        std::cout << "Cannot open the input file.\n";
        return;
    }
    
    std::string line;
    bool firstLine = true;
    while (std::getline (file, line)){

        if (line.empty())
            continue;

        std::string trimLine = trim(line);

        if (firstLine){
            if (trimLine == "date | value"){
                firstLine = false;
                continue;
            }
            firstLine = false;
        }
        else if (trimLine == "date | value"){
            std::cout << "Error: bad input => " << trimLine << std::endl;
            continue;
        }
        parseLine(trimLine);
    }
}

/*validate the date and the amount (value) in the input file*/
void BitcoinExchange::parseLine(const std::string& line){

    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos){
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }

    std::string d = line.substr(0, pipePos);
    std::string v = line.substr(pipePos + 1);
    std::string dateStr = trim(d);
    std::string valueStr = trim(v);

    //validate date
    if (!parseDate(dateStr)){
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }
    //validate value
    double value;
    int res = parseValue(valueStr, value);
    if (res == 0){
        std::cout << "Error: bad input => " << line << std::endl;
        return ;
    }
    else if (res == -1){
        std::cout << "Error: not a positive number.\n";
        return ;
    }
    else if (res == -2){
        std::cout << "Error: too large a number.\n";
        return ;
    }

    double rate = findRate(dateStr);

    if (rate == -1)
        return;
    
    double result = value * rate;
    std::cout << dateStr << " => " << value << " = " << result << std::endl;
}


std::string BitcoinExchange::trim(const std::string& str){
    size_t start = 0;
    size_t end = str.length();

    while (start < end && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end > start && (str[end - 1] == ' ' || str[end - 1] == '\t'))
        end--;
    return str.substr(start, end - start);
}

int BitcoinExchange::parseDate(const std::string& date){

    if (date.length() != 10)
        return 0;
    if (date[4] != '-' || date[7] != '-')
        return 0;
    for (size_t i = 0; i < date.length(); i++){
        if (!std::isdigit(date[i]) && date[i] != '-')
            return 0;
    }
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0;
    return 1;
}

int BitcoinExchange::parseValue(const std::string& valueStr, double &outValue){

    if (valueStr.empty())
        return 0;
    
    if (valueStr[0] == '.' || valueStr[valueStr.length() - 1] == '.')
        return 0;

    size_t i = 0;
    int dotCount = 0;

    if (valueStr[0] == '-' || valueStr[0] == '+')
        i++;
    if (i >= valueStr.length())
        return 0;
    
    for (; i < valueStr.length(); i++){
        if (valueStr[i] == '.'){
            dotCount++;
            if (dotCount > 1)
                return 0;
        }
        else if (!std::isdigit(valueStr[i]))
            return 0;
    }

    double v = std::atof(valueStr.c_str());
    if (v < 0)
        return -1;
    if (v > 1000)
        return -2;
    outValue = v;

    return 1;
}

/*find the corresponding rate to a date in the data base file*/
double BitcoinExchange::findRate(const std::string& date){

    if (db.empty()) {
        std::cout << "Error: data base is empty.\n";
        return -1;
    }

    std::map<std::string, double>::iterator it = db.lower_bound(date);

    if (it == db.end())
        --it;
    else if (it->first != date && it == db.begin()){
        std::cout << "Error: date before the data base.\n";
        return -1;
    }
    else if(it->first != date && it != db.begin())
        --it;

    return it->second;
}
