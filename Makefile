CC = g++-4.9
LPS_FLAGS = -I /usr/include/lpsensor -L /usr/lib -l LpSensor -l pthread
CFLAGS = -static -c -fPIC -Wall -std=c++11
INSTALL_PATH = /usr/local

HEADERS = imu.h
SOURCES = imu.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) libimu.a libimu.so

libimu.a: $(OBJECTS)
	ar rcs libimu.a $(OBJECTS)

libimu.so: $(OBJECTS)
	$(CC) -shared -Wl,-soname,libimu.so -o libimu.so $(OBJECTS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o

install: all
	# Move shared libraries
	mv libimu.so $(INSTALL_PATH)/lib/
	mv libimu.a $(INSTALL_PATH)/lib/

	# Add header files
	mkdir -p $(INSTALL_PATH)/include/imu
	cp $(HEADERS) $(INSTALL_PATH)/include/imu/

uninstall:
	rm -f $(INSTALL_PATH)/lib/libimu.a
	rm -f $(INSTALL_PATH)/lib/libimu.so

	rm -rf $(INSTALL_PATH)/include/imu
