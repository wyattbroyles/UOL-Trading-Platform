#pragma once
#include "OrderBookEntry.h"
#include "CSVReader.h"

class OrderBook
{
    public:
        /** construct, reading a csv data file */
        OrderBook(std::string filename);
        /** return vector of all known products in dataset */
        std::vector<std::string> getKnownProducts();
        /** retun vector of Orders according to the sent filters */
        std::vector<OrderBookEntry> getOrders(OrderBookType type, std::string product, std::string timestamp);

/** returns earliest time in the orderbook */
        std::string getEarliestTime();
        /** returns the next time after the sent time in the orderbook 
         * if there is no next timestamp, wrap back around to the start
        */
        std::string getNextTime(std::string timestamp);

        void insertOrder(OrderBookEntry& order);

        std::vector<OrderBookEntry> matchAsksToBids(std::string product, std::string timestamp);

        static double getHighPrice(std::vector<OrderBookEntry>& orders);
        static double getLowPrice(std::vector<OrderBookEntry>& orders);

    
    private:
        std::vector<OrderBookEntry> orders;
};