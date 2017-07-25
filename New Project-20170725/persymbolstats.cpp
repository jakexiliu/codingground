#include "persymbolstats.h"

void PerSymbolStats::addTrade(const Trade& trade) {
    //update latest timestamp and max time gap
	long long timestamp=trade.timestamp();
	if(m_latestTimestamp>0) {
		if(m_maxTimeGap<timestamp-m_latestTimestamp) {
			m_maxTimeGap=timestamp-m_latestTimestamp;
		}
	}
	m_latestTimestamp=timestamp;

    //update volume
	m_volume+=trade.amount();

	//update max price
	if(trade.price()>m_maxPrice)
	    m_maxPrice=trade.price();

	//update weighted avg
	double weightedAvg=(static_cast<double>(trade.amount())/m_volume)*trade.price();
	weightedAvg+=(1-static_cast<double>(trade.amount())/m_volume)*m_weightedAvgPrice;
	m_weightedAvgPrice=weightedAvg;
}