VREP=$(VREP_ROOT)
CXXFLAGS=-I$(MADARA_ROOT)/include -I$(ACE_ROOT) \
-I.. -I$(VREP)/programming/remoteApi -I$(VREP)/programming/include \
-DNON_MATLAB_PARSING -DMAX_EXT_API_CONNECTIONS=255 -D__linux
LIB=$(MADARA_ROOT)/libMADARA.so

all : testExtApi

testExtApi : testExtApi.o libDaslVrep.a 
	g++ $(CXXFLAGS) -o $@ $^ $(LIB) -lpthread

testExtApi.o : testExtApi.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

libDaslVrep.a : extApi.o extApiPlatform.o DmplVrep.o
	ar rc $@ $^

extApi.o : $(VREP)/programming/remoteApi/extApi.c
	cc $(CXXFLAGS) -c -o $@ $<

extApiPlatform.o : $(VREP)/programming/remoteApi/extApiPlatform.c
	cc $(CXXFLAGS) -c -o $@ $<

DmplVrep.o : DmplVrep.cpp DmplVrep.hpp
	g++ $(CXXFLAGS) -c -o $@ $<

clean :
	rm -f *.o testExtApi
