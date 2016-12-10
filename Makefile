TARGET = Fill
SRCS = $(TARGET).C
OBJS = $(TARGET).o

#TARGET2 = Fill2
#SRCS2 = $(TARGET2).C
#OBJS2 = $(TARGET2).o

ROOTCFLAGS = $(shell root-config --cflags)
ROOTLIBS = $(shell root-config --libs)
ROOTGLIBS = $(shell root-config --glibs)

CXXFLAGS = $(ROOTCFLAGS) -Wall -fPIC
CXXLIBS = $(ROOTLIBS)
CC = g++

$(TARGET): $(OBJS)
	$(CC) $(CXXLIBS) $(OBJS) -o $@

#$(TARGET2): $(OBJS2)
	#$(CC) $(CXXLIBS) $(OBJS2) -o $@
.C.o:
	$(CC) $(CXXFLAGS) -c $<
clean:
	rm -rf $(TARGET)
	rm -rf $(OBJS)
	#rm -rf $(TARGET2)
	#rm -rf $(OBJS2)
