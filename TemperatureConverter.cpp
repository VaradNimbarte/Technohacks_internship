#include <iostream>
using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    cout << "Temperature Converter" << endl;

    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Fahrenheit to Celsius" << endl;
        cout << "2. Celsius to Fahrenheit" << endl;
        cout << "3. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    double fahrenheit;
                    cout << "Enter temperature in Fahrenheit: ";
                    cin >> fahrenheit;
                    cout << "Temperature in Celsius: " << fahrenheitToCelsius(fahrenheit) << "°C" << endl;
                }
                break;
            case 2:
                {
                    double celsius;
                    cout << "Enter temperature in Celsius: ";
                    cin >> celsius;
                    cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(celsius) << "°F" << endl;
                }
                break;
            case 3:
                cout << "Exiting the Temperature Converter. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl << endl;
        }
    }

    return 0;
}
