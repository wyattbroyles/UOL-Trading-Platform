#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"
#include <limits>

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    wallet.insertCurrency("BTC", 10);
    while (true) {
        printMenu();
        input = getUserInput();
        printFunction(input);
    }
}

void MerkelMain::printMenu() {
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats " << std::endl;
    // 3 make an offer (want to sell)
    std::cout << "3: Make an offer " << std::endl;
    // 4 made a bid (want to buy like auction bid)
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print Wallet " << std::endl;
    // 6 next time step (continue)
    std::cout << "6: Continue " << std::endl;

    std::cout << "================ " << std::endl;
    std::cout << "Type in 1-6" << std::endl;
    std::cout << "OR Enter 7 to quit " << std::endl;
    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyze the market and make a bid or offer" << std::endl;
 
}

void MerkelMain::printMarketStats()
{
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    /* std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for (OrderBookEntry& e : orders) 
    {
        if (e.orderType == OrderBookType::ask)
        {
            asks++;
        }
        if (e.orderType == OrderBookType::bid)
        {
            bids++;
        }
    }
    std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl; */
}

void MerkelMain::enterOffer()
{
    std::cout << "Mark and offer  - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterOffer Bad input! " << input << std::endl;
    }
    else {
        try {
        OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
        obe.username = "simuser";
        if (wallet.canFulfillOrder(obe))
        {
            std::cout << "Wallet looks good. " << std::endl;
            orderBook.insertOrder(obe);
        }
        orderBook.insertOrder(obe);
        } catch (const std::exception& e) {
            std::cout << " MerkelMain::enterOffer Bad input" << std::endl;
        }
    }
    //std::cout << "You typed: " << input << std::endl;

}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount: product, price, amount, eg ETH/BTC,200,0.5" << std::endl;
    std::string input;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::getline(std::cin, input);
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterBid Bad input! " << input << std::endl;
    }
    else {
        try {
        OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::bid);
        obe.username = "simuser";

        if (wallet.canFulfillOrder(obe))
        {
            std::cout << "Wallet looks good. " << std::endl;
            orderBook.insertOrder(obe);
        }
        orderBook.insertOrder(obe);
        } catch (const std::exception& e) {
            std::cout << " MerkelMain::enterBid Bad input" << std::endl;
        }
    }
    //std::cout << "You typed: " << input << std::endl;

}

void MerkelMain::printWallet()
{
    std::cout << wallet.toString() << std::endl;

}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Going to next time frame..." << std::endl;
    std::vector<OrderBookEntry> sales = orderBook.matchAsksToBids("ETH/BTC", currentTime);
    std::cout << "Sales: " << sales.size() << std::endl;
    for (OrderBookEntry& sale : sales)
    {
        std::cout << "Sale price:" << sale.price << " amount " << sale.amount << std::endl;
        if (sale.username == "simuser")
        {
            // update the wallet
            wallet.processSale(sale);
        }
    }
    currentTime = orderBook.getNextTime(currentTime);

}


int MerkelMain::getUserInput() {
    int userOption = 0;
    std::string line;
    std::getline(std::cin, line);
    try {
    userOption = std::stoi(line);
    } catch (const std::exception& e)
    {
        // 
    }
    //std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::printFunction(int userOption) {
    if (userOption <= 0 || userOption >= 8) {
            std::cout << "Invalid input. Please try again using 1-6" << std::endl;
        }
        else if (userOption == 1) {
            printHelp();
        }
        else if (userOption == 2) {
            printMarketStats();
        }
        else if (userOption == 3) {
            enterOffer();
        }
        else if (userOption == 4) {
            enterBid();
        }
        else if (userOption == 5) {
            printWallet();
        }
        else if (userOption == 6) {
            gotoNextTimeframe();
        }
        else if (userOption == 7) {
            std::cout << "BYE!" << std::endl;
            exit(0);
        }

}