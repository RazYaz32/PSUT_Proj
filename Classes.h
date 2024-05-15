#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <vector>
#include "Mock_Database.h"

std::vector<std::string> paymentMethods = { "Credit Card", "Debit Card", "PayPal", "Bank Transfer" };

class Date {
public:
    int year;
    int month;
    int day;

    Date(int year = 1970, int month = 1, int day = 1) : year(year), month(month), day(day) {}
};

class Interface {
public:
    Date date;

    Interface(Date date) : date(date) {}

    virtual void authenticate(int userID) = 0;
    virtual void transferPayments(int userID, int amount) = 0;
    virtual void handleStandards(int userID) = 0;
};

class UserAuthentication : public Interface {
private:
    std::string password;
    Date date;
public:
    

    UserAuthentication(Date date, std::string password) : Interface(date), password(password) {}

    void auth(int userID, std::string password) {
        if (userDatabase.find(userID) != userDatabase.end()) {
            if (userDatabase[userID] == password) {
                std::cout << "User " << userID << " authenticated successfully." << std::endl;
            }
            else {
                std::cout << "Authentication failed: Incorrect password." << std::endl;
            }
        }
        else {
            std::cout << "Authentication failed: User ID not found." << std::endl;
        }
    }

    void multiFactorAuth(int userID) {
        if (mfaDatabase.find(userID) != mfaDatabase.end()) {
            if (mfaDatabase[userID]) {
                std::cout << "User " << userID << " passed multi-factor authentication." << std::endl;
            }
            else {
                std::cout << "User " << userID << " did not set up multi-factor authentication." << std::endl;
            }
        }
        else {
            std::cout << "Multi-factor authentication failed: User ID not found." << std::endl;
        }
    }

    void authenticate(int userID) override {
        std::cout << "Authenticating user " << userID << "..." << std::endl;
        auth(userID, password);
        multiFactorAuth(userID);
    }

    void transferPayments(int userID, int amount) override {
        std::cout << "Transferring amount " << amount << " for user " << userID << std::endl;
    }

    void handleStandards(int userID) override {
        std::cout << "Handling standards for user " << userID << std::endl;
    }
};

class PaymentInitiation : public Interface {
public:
    int transactionID;
    std::string chosenPaymentMethod;
    std::string paymentDetails;

    PaymentInitiation(Date date, int transactionID) : Interface(date), transactionID(transactionID) {}

    void initiatePayment(int userID, int amount) {
        //TODO: Further Payment Initiation Logic
        transactionDatabase[transactionID] = amount;
        std::cout << "Payment initiated for user " << userID << " with transaction ID " << transactionID << " and amount " << amount << "." << std::endl;
    }

    void choosePaymentMethod() {
        std::cout << "Available payment methods:\n";
        for (size_t i = 0; i < paymentMethods.size(); ++i) {
            std::cout << i + 1 << ". " << paymentMethods[i] << std::endl;
        }
        int choice;
        std::cout << "Choose a payment method (1-" << paymentMethods.size() << "): ";
        std::cin >> choice;
        if (choice > 0 && choice <= paymentMethods.size()) {
            chosenPaymentMethod = paymentMethods[choice - 1];
            std::cout << "Payment method chosen: " << chosenPaymentMethod << "." << std::endl;
        }
        else {
            std::cout << "Invalid choice. Defaulting to " << paymentMethods[0] << "." << std::endl;
            chosenPaymentMethod = paymentMethods[0];
        }
    }

    void enterDetails() {
        std::cout << "Enter payment details for " << chosenPaymentMethod << ": ";
        std::cin.ignore();  //Clear stdin buffer
        std::getline(std::cin, paymentDetails);
        std::cout << "Payment details entered: " << paymentDetails << "." << std::endl;
    }

    void authenticate(int userID) override {
        std::string password;
        std::cout << "Enter password for user " << userID << ": ";
        std::cin >> password;
        if (userDatabase.find(userID) != userDatabase.end() && userDatabase[userID] == password) {
            std::cout << "User " << userID << " authenticated successfully." << std::endl;
        }
        else {
            std::cout << "Authentication failed for user " << userID << "." << std::endl;
        }
    }

    void transferPayments(int userID, int amount) override {
        std::cout << "Transferring amount " << amount << " for user " << userID << std::endl;
        //TODO: Make Mock Database for Monetary Transfers
    }

    void handleStandards(int userID) override {
        std::cout << "Handling standards for user " << userID << std::endl;
        //TODO: Handle Optional Standards for Users
    }
};

// Class: ConfirmationReceipt (inherits Interface)
class ConfirmationReceipt : public Interface {
public:
    ConfirmationReceipt(Date date) : Interface(date) {}

    void provideReceipts(int transactionID) {
        if (transactionDatabase.find(transactionID) != transactionDatabase.end()) {
            double amount = transactionDatabase[transactionID];
            std::cout << "Receipt for Transaction ID: " << transactionID << ", Amount: $" << amount << std::endl;
        }
        else {
            std::cout << "No transaction found for ID " << transactionID << "." << std::endl;
        }
    }

    // Implementing pure virtual functions from Interface
    void authenticate(int userID) override {
        std::cout << "Authenticating user " << userID << " for receipt provision..." << std::endl;
        // Authentication logic here
    }

    void transferPayments(int userID, int amount) override {
        std::cout << "Transferring amount $" << amount << " for user " << userID << std::endl;
        // Transfer payment logic here
    }

    void handleStandards(int userID) override {
        std::cout << "Handling standards for user " << userID << std::endl;
        // Handle standards logic here
    }
};

// Class: PaymentProcessing
class PaymentProcessing {
public:
    int userID_buyer;
    int userID_seller;
    double amount;
    Date date;

    PaymentProcessing(int userID_buyer, int userID_seller, double amount, Date date) : userID_buyer(userID_buyer), userID_seller{ userID_seller }, amount(amount), date(date) {}

    void processPayment() {
        UserAuthentication userAuth(date, "password123");
        userAuth.authenticate(userID_buyer);

        PaymentInitiation paymentInit(date, 1001);
        paymentInit.authenticate(userID_buyer);
        paymentInit.initiatePayment(userID_buyer, amount);
        paymentInit.choosePaymentMethod();
        paymentInit.enterDetails();
        paymentInit.transferPayments(userID_seller, amount);
        paymentInit.handleStandards(userID_buyer);

        ConfirmationReceipt receipt(date);
        receipt.provideReceipts(1001);
    }

    void authorizePayment(int userID) {
        std::cout << "Authorizing payment for user " << userID << std::endl;
        //TODO: Authorization logic
    }

    void executeTransaction(int userID, int amount) {
        std::cout << "Executing transaction for user " << userID_buyer << " with amount $" << amount << " to user " << userID_seller << std::endl;
        //TODO: Further transaction logic
    }

    void manageTransfers(int userID) {
        std::cout << "Managing transfers for user " << userID << std::endl;
        //TODO: Extra feature for managing multiple transfers.
    }
};


#endif