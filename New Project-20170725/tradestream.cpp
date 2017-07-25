#include "tradestream.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>

void TradeStream::readData(const string& fileName) {
	fstream read;
	read.open(fileName.c_str());
	if(!read.is_open()) {
		cout<<"Error opening "<< fileName<<endl;
	}
	const int size=100;
	while(!read.eof()) {
		string line;
		getline(read,line);    //read a row
		if(line.empty())
			break;
		istringstream iss(line);
		vector<string> fields(0);
		string field;          //parse fields separated by comma
		while(getline(iss,field,','))
			fields.push_back(field);
		string symbol=fields[1];
		
		long long timestamp;
		int price;
		int amount;

		iss.clear();
		iss.str(fields[0]);
		iss>>timestamp;

		iss.clear();
		iss.str(fields[2]);
		iss>>amount;

		iss.clear();
		iss.str(fields[3]);
		iss>>price;

		map<string,PerSymbolStats*>::iterator it=m_statistics.find(symbol);
		if(it==m_statistics.end()) {
			PerSymbolStats* p = new PerSymbolStats(symbol);
			m_statistics.insert(make_pair(symbol,p));
		}
		Trade trade(timestamp,symbol,amount,price);
		m_statistics[symbol]->addTrade(trade); //update per symbol statistics based on new trade for the symbol

	}
	read.close();
}

void TradeStream::output(const string& fileName) {
	ofstream excel;
	excel.open(fileName);
	for(map<string,PerSymbolStats*>::iterator it=m_statistics.begin();it!=m_statistics.end();++it) {
		PerSymbolStats* ptr=it->second;
		excel<<ptr->symbol()<<","
			<<ptr->maxTimeGap()<<","
			<<ptr->volume()<<","
			<<ptr->weightedAvgPriceInt()<<","
			<<ptr->maxPrice()<<endl;

	}
	excel.close();
}

TradeStream::~TradeStream() {
	for(map<string,PerSymbolStats*>::iterator it=m_statistics.begin();it!=m_statistics.end();++it) {
		PerSymbolStats* ptr=it->second;
		delete ptr;
	}
}