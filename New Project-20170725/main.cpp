#include<iostream>
#include<string>
#include "tradestream.h"
using namespace std;

int main() {
	TradeStream tss;
	const string inputFile("input.csv");
	tss.readData(inputFile);
	const string outputFile("output.csv");
	tss.output(outputFile);
	return 0;
}

