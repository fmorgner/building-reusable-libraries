OBJDIR = obj
$(shell mkdir -p $(OBJDIR) >/dev/null)

BINDIR = bin
$(shell mkdir -p $(BINDIR) >/dev/null)

LIBDIR = lib
$(shell mkdir -p $(LIBDIR) >/dev/null)

_OBJS = box_impl.o box.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

CXXFLAGS=-std=c++14 -fPIC -fvisibility=hidden -O3
LIBSTDCXX=-stdlib=libstdc++
LIBCXX=-stdlib=libc++ -lc++abi
BIN_LDFLAGS=-lbox -Llib -Wl,-rpath,$(dir $(realpath $(firstword $(MAKEFILE_LIST))))/lib

.PHONY: all
all: cbox cppbox gobox

.PHONY: clean
clean:
	    rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

$(OBJDIR)/%.o: %.cpp
	    @$(CXX) -c -o $@ $< $(CXXFLAGS)
			@echo "CXX $@"

libbox.so: $(OBJS)
	    @$(CXX) -shared -o $(LIBDIR)/libbox.so $(CXXFLAGS) $^
			@echo "LD $@"

cbox.o: cbox.c
			@$(CC) -o $(OBJDIR)/cbox.o cbox.c -c
			@echo "CC $@"

cppbox.o: cppbox.cpp
			@$(CXX) -o $(OBJDIR)/cppbox.o -std=c++14 -stdlib=libc++ cppbox.cpp -c
			@echo "CXX $@"

cbox: cbox.o libbox.so
			@$(CXX) -o $(BINDIR)/cbox $(BIN_LDFLAGS) $(OBJDIR)/cbox.o
			@echo "LD $@"

cppbox: cppbox.o libbox.so
			@$(CXX) -o $(BINDIR)/cppbox $(BIN_LDFLAGS) -std=c++14 $(LIBCXX) $(OBJDIR)/cppbox.o
			@echo "LD $@"

gobox: export CGO_LDFLAGS=$(BIN_LDFLAGS)
gobox: libbox.so
			@go build -o $(BINDIR)/gobox gobox.go
			@echo "GO $@"
