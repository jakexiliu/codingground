#ifndef TRADE_STREAM_H
#define TRADE_STREAM_H
#include "trade.h"
#include "persymbolstats.h"
#include <map>

using namespace std;
class TradeStream {
public:
	void readData(const string& fileName);
	void output(const string& fileName);
	~TradeStream();
private:
	map<string,PerSymbolStats*> m_statistics; // keys are ordered automatically.
};


#endif