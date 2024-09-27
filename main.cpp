//Object Oriented Programming Specialization
//1. Introduction to Object Oriented Programming in C++
//2. C++ Programming: Classes and Data 
//3. Object-Oriented Programming in C++: Functions
//4. Working with Objects in C++ 
//5. Use C++ to build a Crypto Trading Platform: Final System

// by University of London & Goldsmiths, University of London on Coursera

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"
#include "CSVReader.h"
#include "Wallet.h"

//void printMenu();
//int getUserInput();
//void printFunction(int userOption);



int main() {
    MerkelMain app{};
    app.init();
  
    
    /* double price = 5315.6477491;
    double amount = 0.00027634;
    std::vector<OrderBookEntry> orders;

    std::string timestamp{"2020/03/17 17:01:24.884492"};
    std::string product{"BTC/USDT"};
    std::string orderType{"bid"};

    
    OrderBookType orderType = OrderBookType::bid;

    std::vector<double> prices;
    std::vector<double> amounts;
    std::vector<std::string> timestamps;
    std::vector<std::string> products;
    std::vector<OrderBookType> orderTypes;

    prices.push_back(5000.01);
    amounts.push_back(0.001);
    timestamps.push_back("2020/03/17 17:01:24.884492");
    products.push_back("BTC/USDT");
    orderTypes.push_back(OrderBookType::bid);

    std::cout << "prices: " << prices[0] << std::endl; */

    

    //OrderBookEntry order1{100000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid};
    //order1.price = 100000;
    //order1.amount = 0.002;
    //order1.timestamp = "2020/03/17 17:01:24.884492";
    //order1.product = "BTC/USDT";
    //order1.orderType = OrderBookType::bid;

    /* orders.push_back(OrderBookEntry {100000, 0.002, "2020/03/17 17:01:24.884492", "BTC/USDT", OrderBookType::bid});


    std::cout << "The price is " << orders[0].price << std::endl;

    for (OrderBookEntry order: orders)
    {
        std::cout << "The price is " << order.price << std::endl;
    }

    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders[i].price << std::endl;
    }

    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders.at(i).price << std::endl;
    }

    while (true)
    {
        printMenu();
        int userOption = getUserInput();
        printFunction(userOption);
    } */
}


//char c = 0;
//std::cout << "char: " << sizeof(c) << std::endl; //1 byte 8 bits

//unsigned int i = 0;
//std::cout << "unsigned int: " << sizeof(i) << std::endl;

//signed int j = 0;
//std::cout << "signed int: " << sizeof(j) << std::endl;

//float f = 0.0f;
///std::cout << "float: " << sizeof(f) << std::endl; //all float types are signed

//long double d = 0.0;
//std::cout << "ld: " << sizeof(d) << std::endl;



