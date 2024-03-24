#include <iostream>
#include <limits> // for numeric_limits

using namespace std;

// Function prototypes
float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);

// Function to get a valid float input from the user
float getValidFloatInput(const string &prompt);

int main()
{
    char operation;
    float num1, num2, result;
    char repeat;

    do
    {
        cout << "Simple Calculator" << endl;

        num1 = getValidFloatInput("Enter first number: ");
        num2 = getValidFloatInput("Enter second number: ");

        bool validOperation = false;

        while (!validOperation)
        {
            cout << "Choose operation (+, -, *, /): ";
            cin >> operation;

            switch (operation)
            {
            case '+':
                result = add(num1, num2);
                cout << num1 << " + " << num2 << " = " << result << endl;
                validOperation = true;
                break;

            case '-':
                result = subtract(num1, num2);
                cout << num1 << " - " << num2 << " = " << result << endl;
                validOperation = true;
                break;

            case '*':
                result = multiply(num1, num2);
                cout << num1 << " * " << num2 << " = " << result << endl;
                validOperation = true;
                break;

            case '/':
                if (num2 != 0)
                {
                    result = divide(num1, num2);
                    cout << num1 << " / " << num2 << " = " << result << endl;
                    validOperation = true;
                }
                else
                {
                    cout << "Cannot divide by zero." << endl;
                }
                break;

            default:
                cout << "Invalid operation. Please choose +, -, *, or /." << endl;
            }
        }

        do
        {
            cout << "Do you want to perform another calculation? (y/n): ";
            cin >> repeat;

            if (cin.fail() || (repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N'))
            {
                cout << "Invalid input. Please enter either 'y' or 'n'." << endl;
                cin.clear();                                         // clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            }

        } while (repeat != 'y' && repeat != 'Y' && repeat != 'n' && repeat != 'N');

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

// Function definitions
float add(float x, float y)
{
    return x + y;
}

float subtract(float x, float y)
{
    return x - y;
}

float multiply(float x, float y)
{
    return x * y;
}

float divide(float x, float y)
{
    return x / y;
}

// Function to get a valid float input from the user
float getValidFloatInput(const string &prompt)
{
    float input;
    bool validInput = false;

    do
    {
        cout << prompt;
        cin >> input;

        if (cin.fail())
        {
            cout << "Invalid input. Please enter a valid numeric value." << endl;
            cin.clear();                                         // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
        else
        {
            validInput = true;
        }

    } while (!validInput);

    return input;
}
