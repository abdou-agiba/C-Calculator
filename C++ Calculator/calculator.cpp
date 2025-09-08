#include <iostream>
#include <limits> 
#include <string>
#include <cctype>

// header
void printHeader(const std::string &title)
{
    std::cout << "========================================\n";
    std::cout << "|                                      |\n";
    std::cout << "|          " << title << "          |\n";
    std::cout << "|                                      |\n";
    std::cout << "========================================\n";
}

// result
void printResult(double result)
{
    std::cout << "----------------------------------------\n";
    std::cout << "| The Result is: " << result << "                  |\n";
    std::cout << "----------------------------------------\n";
}

int main()
{
    char op;
    double num1, num2;
    std::string again;

    printHeader(" C++ Calculator");

    do
    {
        // frist num
        std::cout << "Enter first number: ";
        std::cin >> num1;

        // operator
        std::cout << "Enter operator (+, -, *, /): ";
        std::cin >> op;

        // second num
        std::cout << "Enter second number: ";
        std::cin >> num2;

        std::cout << "\n"; // spcae

        switch (op)
        {
        case '+':
            printResult(num1 + num2);
            break;
        case '-':
            printResult(num1 - num2);
            break;
        case '*':
            printResult(num1 * num2);
            break;
        case '/':
            if (num2 != 0)
            {
                printResult(num1 / num2);
            }
            else
            {
                std::cout << "----------------------------------------\n";
                std::cout << "| Error! Division by zero is not allowed. |\n";
                std::cout << "----------------------------------------\n";
            }
            break;
        default:
            // error invalid operator
            std::cout << "----------------------------------------\n";
            std::cout << "| Error! Invalid operator.             |\n";
            std::cout << "----------------------------------------\n";
            break;
        }

        std::cout << "\nDo you want to perform another calculation? (yes/no): ";
        std::cin >> again;
        // clear input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // lowercase
        for (char &c : again)
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    } while (again == "yes");

    std::cout << "\nThank you for using the calculator!\n";
    return 0;
}
