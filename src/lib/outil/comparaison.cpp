#include "comparaison.h"

/* SPLIT */

bool comparaison(int value1, std::string condition, int value2)
    {
  if(condition == "=" or condition == "==" or condition == "is")
    return (value1 == value2);
  else if(condition == "!=" or condition == "is not")
    return (value1 != value2);
  else if(condition == "<")
    return (value1 < value2);
  else if(condition == "<=")
    return (value1 <= value2);
  else if(condition == ">")
    return (value1 > value2);
  else if(condition == ">=")
    return (value1 >= value2);
  else
    std::cerr << "Error: condition not found" << std::endl;
  return false;
    }
    
/* SPLIT */

bool comparaison(char value1, std::string condition, char value2)
    {
  if(condition == "=" or condition == "==" or condition == "is")
    return (value1 == value2);
  else if(condition == "!=" or condition == "is not")
    return (value1 != value2);
  else if(condition == "<")
    return (value1 < value2);
  else if(condition == "<=")
    return (value1 <= value2);
  else if(condition == ">")
    return (value1 > value2);
  else if(condition == ">=")
    return (value1 >= value2);
  else
    std::cerr << "Error: condition not found" << std::endl;
  return false;
    }
    


bool comparaison(std::string value1, std::string condition, std::string value2)
    {
  if(condition == "=" or condition == "==" or condition == "is")
    return (value1 == value2);
  else if(condition == "!=" or condition == "is not")
    return (value1 != value2);
  else if(condition == "<")
    return (value1 < value2);
  else if(condition == "<=")
    return (value1 <= value2);
  else if(condition == ">")
    return (value1 > value2);
  else if(condition == ">=")
    return (value1 >= value2);
  else
    std::cerr << "Error: condition not found" << std::endl;
  return false;
    }
    


bool comparaison(double value1, std::string condition, double value2)
    {
  if(condition == "=" or condition == "==" or condition == "is")
    return (value1 == value2);
  else if(condition == "!=" or condition == "is not")
    return (value1 != value2);
  else if(condition == "<")
    return (value1 < value2);
  else if(condition == "<=")
    return (value1 <= value2);
  else if(condition == ">")
    return (value1 > value2);
  else if(condition == ">=")
    return (value1 >= value2);
  else
    std::cerr << "Error: condition not found" << std::endl;
  return false;
    }
    


bool comparaison(int unsigned value1, std::string condition, int unsigned value2)
    {
  if(condition == "=" or condition == "==" or condition == "is")
    return (value1 == value2);
  else if(condition == "!=" or condition == "is not")
    return (value1 != value2);
  else if(condition == "<")
    return (value1 < value2);
  else if(condition == "<=")
    return (value1 <= value2);
  else if(condition == ">")
    return (value1 > value2);
  else if(condition == ">=")
    return (value1 >= value2);
  else
    std::cerr << "Error: condition not found" << std::endl;
  return false;
    }
    


bool comparaison(float value1, std::string condition, float value2)
    {
  if(condition == "=" or condition == "==" or condition == "is")
    return (value1 == value2);
  else if(condition == "!=" or condition == "is not")
    return (value1 != value2);
  else if(condition == "<")
    return (value1 < value2);
  else if(condition == "<=")
    return (value1 <= value2);
  else if(condition == ">")
    return (value1 > value2);
  else if(condition == ">=")
    return (value1 >= value2);
  else
    std::cerr << "Error: condition not found" << std::endl;
  return false;
    }
    
/* SPLIT */
    
    