all : main

main: main.o trade.o persymbolstats.o tradestream.o
	g++ --std=c++11 -o main main.o trade.o persymbolstats.o tradestream.o
main.o : trade.h persymbolstats.h persymbolstats.cpp tradestream.h tradestream.cpp
	g++ -c --std=c++11 main.cpp

trade.o : trade.h trade.cpp
	g++ -c --std=c++11 trade.cpp

persymbolstats.o : trade.h persymbolstats.h persymbolstats.cpp
	g++ -c --std=c++11 persymbolstats.cpp

tradestream.o : trade.h persymbolstats.h persymbolstats.cpp tradestream.h tradestream.cpp
	g++ -c --std=c++11 tradestream.cpp

clean:
	\rm main main.o trade.o persymbolstats.o tradestream.o
