#ifndef PER_SYMBOL_STATS_H
#define PER_SYMBOL_STATS_H
#include "trade.h"
#include <string>
using namespace std;

class PerSymbolStats {
private:
	long long m_maxTimeGap;
	long long m_latestTimestamp;
	long long m_volume;
	int m_maxPrice;
	double m_weightedAvgPrice; // store double for accuracy
	string m_symbol;
public:
	PerSymbolStats(const string& symbol):m_maxTimeGap(0),m_latestTimestamp(0),m_volume(0), m_maxPrice(0), m_weightedAvgPrice(0), m_symbol(symbol) {
	}
	void addTrade(const Trade& trade);
	long long maxTimeGap() const { return m_maxTimeGap; }
	string symbol() const { return m_symbol; }
	int maxPrice() const { return m_maxPrice; }
	double weightedAvgPrice() const { return m_weightedAvgPrice; }
	int weightedAvgPriceInt() const { return static_cast<int>(m_weightedAvgPrice+0.5); } //add 0.5 for rounding
	long long volume() const { return m_volume; }
};

#endif