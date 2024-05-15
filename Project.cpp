#include <iostream>
#include <random>
#include "time.h"
#include "Classes.h"

int main()
{
    /*
    Date date1(2024, 5, 14);
    UserAuthentication userAuth1(date1, "password123");

    //Check authentication method

    userAuth1.authenticate(1);  //Valid userID and password
    std::cout << "_________________________" << std::endl;
    userAuth1.authenticate(2);  //Valid userID and invalid password
    std::cout << "_________________________" << std::endl;
    userAuth1.authenticate(3);  //Valid userID and password
    std::cout << "_________________________" << std::endl;

    //Check Payment Initiation methods
    
    std::cout << "____________________________________________________________________________" << std::endl;

    Date date2(2024, 5, 14);
    PaymentInitiation paymentInit(date2, 1001);

    int userID_buyer = 1;
    int userID_seller = 2;
    int amount = 500;

    paymentInit.authenticate(userID_buyer);  //First authenticate user (Irrelevant for now.)
    paymentInit.initiatePayment(userID_buyer, amount);  //Initiate payment for user 1 with amount 500
    paymentInit.choosePaymentMethod();  //Choose payment method. One of four.
    paymentInit.enterDetails();  //Enter payment details (Irrelevant)
    paymentInit.transferPayments(userID_seller, amount);  //Transfer payment to userID by amount
    paymentInit.handleStandards(userID_buyer);  //Handle standards


    std::cout << "____________________________________________________________________________" << std::endl;

    Date date3(2024, 5, 14);

    //User authentication
    UserAuthentication userAuth2(date3, "password123");
    int userID_buyer_1 = 1;
    int userID_seller_1 = 3;
    userAuth2.authenticate(userID_buyer_1);//First authenticate user

    //Payment initiation
    PaymentInitiation paymentInit_1(date3, 1001);
    int amount_1 = 500;
    paymentInit_1.authenticate(userID_buyer_1);  //First authenticate user (Irrelevant for now.)
    paymentInit_1.initiatePayment(userID_buyer_1, amount_1);  //Initiate payment for user 1 with amount 500
    paymentInit_1.choosePaymentMethod();  //Choose payment method. One of four
    paymentInit_1.enterDetails();  //Enter payment details (Irrelevant)
    paymentInit_1.transferPayments(userID_seller_1, amount_1);  // Transfer payment
    paymentInit_1.handleStandards(userID_buyer_1);  // Handle standards

    //Confirmation receipt
    ConfirmationReceipt receipt(date3);
    receipt.provideReceipts(1001);  //Provide receipt for transaction ID 1001

    /
    //Unit tests for classes.

    Date date(2024, 5, 14);
    PaymentProcessing paymentProcessing(1, 500, date);
    paymentProcessing.processPayment();
    */
    srand(time(NULL));
    std::cout << (rand()%9) + 1 << " | " << (rand() % 9) + 1 << std::endl;
    return 0;
}
