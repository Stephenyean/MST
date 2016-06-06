sSOURCES=$(wildcard *.cpp)
HEADERS=$(wildcard *.h)
sOBJECTS=$(sSOURCES:%.cpp=%.o)
TARGET=mst

all: $(TARGET)
$(TARGET): main.o mst.o head.o $(HEADERS)
	@echo "Now Generating $(TARGET) ..."
	g++ $(sOBJECTS) -o $(TARGET) -std=c++11 -lCGAL -lCGAL_Core -lgmp
%.o: %.cpp $(HEADERS)
	@echo "Now Compiling $< ..."
	g++ -c $< -o $@ -std=c++11 -lCGAL -lCGAL_Core -lgmp
clean:
	rm *.o mst
explain:
	@echo "Headers: $(HEADERS)"
	@echo "User Sources: $(sSOURCES)"
	@echo "User Objects: $(sOBJECTS)"
	@echo "Lib: $(LIB)"
	@echo "Target: $(TARGET)"
