#ifndef TRADE_H
#define TRADE_H

#include<string>
using namespace std;


class Trade {
public:
	Trade(long long timestamp, string symbol, int amount, int price): 
	  m_timestamp(timestamp), m_symbol(symbol), m_amount(amount), m_price(price) {}
	  long long timestamp() const {return m_timestamp;}
	  string symbol() const {return m_symbol;}
	  int amount() const {return m_amount;}
	  int price() const {return m_price;}
private:
	long long m_timestamp;
	string m_symbol;
	int m_amount;
	int m_price;
};

#endif