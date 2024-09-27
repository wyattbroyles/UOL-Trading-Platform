#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "Wallet.h"

class MerkelMain
{
    public:
        MerkelMain();
        void init();
    private:
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeframe();
        void printMenu();
        int getUserInput();
        void printFunction(int userOption);

        std::string currentTime;

        OrderBook orderBook{"20200317.csv"};
        std::vector<OrderBookEntry> orders;

        Wallet wallet;
};