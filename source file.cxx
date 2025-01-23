#include <iostream>
#include <string>

using namespace std;

// Function to display the main menu
void displayMainMenu() {
    cout << "\t\t\t---------- Layyah Food -----------\n\n";
    cout << "1) Customer Assistant\n";
    cout << "2) Order Inquiry\n";
    cout << "3) Place Order\n\n";
    cout << "Please Enter your Choice: ";
}

// Function to display sub-menu for a specific category
void displaySubMenu(string items[], double prices[], int size) {
    cout << "\nChoose your item:\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ") " << items[i] << " - Rs." << prices[i] << endl;
    }
    cout << "Please Enter your Choice: ";
}

// Function to handle orders
void takeOrder(string items[], double prices[], int size, double &totalBill) {
    int choice, quantity;
    double total = 0.0;

    displaySubMenu(items, prices, size);
    cin >> choice;

    if (choice > 0 && choice <= size) {
        cout << "You chose: " << items[choice - 1] << endl;
        cout << "Enter Quantity: ";
        cin >> quantity;

        total = prices[choice - 1] * quantity;
        totalBill += total;
        cout << "\n\t\t-------- Your Order --------\n";
        cout << quantity << " x " << items[choice - 1] << " = Rs." << total << endl;
        cout << "Your Order will be delivered in 40 minutes.\n";
        cout << "Thank you for ordering from Layyah Food!\n";
    } else {
        cout << "Invalid choice. Returning to the main menu.\n";
    }
}

// Function for customer care
void customerCare() {
    int inquiryType;
    cout << "\nIs your inquiry about:\n";
    cout << "1) Your Order\n";
    cout << "2) General Inquiry\n";
    cout << "Please Enter your Choice: ";
    cin >> inquiryType;

    if (inquiryType == 1) {
        string orderNumber;
        cout << "Kindly enter your Order Number: ";
        cin >> orderNumber;
        cout << "You will shortly receive SMS updates about your order.\n";
        cout << "Thanks for ordering from Layyah Food!\n";
    } else if (inquiryType == 2) {
        string phoneNumber;
        cout << "Kindly enter your 11-digit phone number (e.g., 03001112223): ";
        cin >> phoneNumber;
        cout << "We will contact you shortly about your inquiry.\n";
    } else {
        cout << "Invalid choice. Returning to the main menu.\n";
    }
}

// Function to handle payment options
void paymentMethod(double totalBill) {
    int paymentChoice;
    cout << "\n\t\t-------- Payment Options --------\n";
    cout << "1) Cash on Delivery\n";
    cout << "2) Online Payment\n";
    cout << "Please Enter your Choice: ";
    cin >> paymentChoice;

    if (paymentChoice == 1) {
        cout << "\nKindly take your cash of Rs." << totalBill << " while the rider is on the way.\n";
        cout << "Thank you for choosing Layyah Food!\n";
    } else if (paymentChoice == 2) {
        cout << "\nKindly send Rs." << totalBill << " to the following JazzCash account:\n";
        cout << "Title: Layyah Food\n";
        cout << "Account Number: 03006110022\n";
        cout << "Thank you for your payment!\n";
    } else {
        cout << "Invalid choice. Please try again.\n";
    }
}

// Main function
int main() {
    string pizzas[] = {"Chicken Fazita", "Chicken Bar BQ", "Peri Peri", "Creamy Max"};
    double pizzaPrices[] = {250, 500, 900, 1200};

    string burgers[] = {"Zinger Burger", "Chicken Burger", "Beef Burger"};
    double burgerPrices[] = {180, 150, 160};

    string sandwiches[] = {"Club Sandwich", "Chicken Crispy Sandwich", "Veg Sandwich"};
    double sandwichPrices[] = {240, 160, 100};

    string rolls[] = {"Chicken Chatni Roll", "Chicken Mayo Roll", "Veg Roll with Fries"};
    double rollPrices[] = {150, 100, 120};

    string biryanis[] = {"Chicken Biryani", "Prawn Biryani", "Beef Biryani"};
    double biryaniPrices[] = {160, 220, 140};

    int mainChoice;
    char continueOrder;
    double totalBill = 0.0;

    cout << "\t\t\t---------- Layyah Food -----------\n\n";
    cout << "Please Enter Your Name: ";
    string name;
    getline(cin, name);

    string orderNumber; // Declare outside switch to fix scope issues

    do {
        system("CLS");
        cout << "Hello " << name << "!\n\n";

        displayMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                customerCare();
                break;

            case 2:
                cout << "Kindly enter your Order Number: ";
                cin >> orderNumber;
                cout << "You will shortly receive SMS updates about your order.\n";
                break;

            case 3:
                do {
                    system("CLS");
                    cout << "\t\t\t---------- Layyah Food -----------\n\n";
                    cout << "1) Pizzas\n";
                    cout << "2) Burgers\n";
                    cout << "3) Sandwiches\n";
                    cout << "4) Rolls\n";
                    cout << "5) Biryani\n\n";
                    cout << "Please Enter your Choice: ";

                    int categoryChoice;
                    cin >> categoryChoice;

                    switch (categoryChoice) {
                        case 1:
                            takeOrder(pizzas, pizzaPrices, 4, totalBill);
                            break;
                        case 2:
                            takeOrder(burgers, burgerPrices, 3, totalBill);
                            break;
                        case 3:
                            takeOrder(sandwiches, sandwichPrices, 3, totalBill);
                            break;
                        case 4:
                            takeOrder(rolls, rollPrices, 3, totalBill);
                            break;
                        case 5:
                            takeOrder(biryanis, biryaniPrices, 3, totalBill);
                            break;
                        default:
                            cout << "Invalid choice. Returning to the menu.\n";
                            break;
                    }

                    cout << "\nWould you like to order anything else? (Y/N): ";
                    cin >> continueOrder;

                } while (continueOrder == 'Y' || continueOrder == 'y');

                cout << "\n\t\tYour Total Bill: Rs." << totalBill << endl;

                // Call payment method function
                paymentMethod(totalBill);
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "\nWould you like to return to the main menu? (Y/N): ";
        cin >> continueOrder;

    } while (continueOrder == 'Y' || continueOrder == 'y');

    cout << "\nThank you for visiting Layyah Food. Have a great day!\n";

    return 0;
}