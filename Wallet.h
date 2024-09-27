#pragma once
#include <string>
#include <map>
#include "OrderBookEntry.h"

class Wallet
{
    public:
        Wallet();
        /** insert currency to the wallet */
        void insertCurrency(std::string type, double amount);
        /** check if the wallet contains this much currecny or more */
        bool containsCurrency(std::string type, double amount);
        /** generate a string representation */
        std::string toString();
        bool removeCurrency(std::string type, double amount);
/** checks if the wallet can cope with this ask or bid */
        bool canFulfillOrder(OrderBookEntry order);
        /** update the contents of the wallet
         * assumes the order was made by the owner of the wallet
         */
        void processSale(OrderBookEntry& sale);

    private:
        std::map<std::string,double> currencies;

};