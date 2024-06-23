SRC=test.cc
DST=mybin
COMPILER=g++
STANDARD=-std=c++11

$(DST):$(SRC)
	$(COMPILER) -o $(DST) $(SRC) $(STANDARD)

.PHONY:
clean:
	rm -f $(DST)
