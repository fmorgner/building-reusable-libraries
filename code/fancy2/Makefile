OBJDIR = obj
$(shell mkdir -p $(OBJDIR) >/dev/null)

BINDIR = bin
$(shell mkdir -p $(BINDIR) >/dev/null)

LIBDIR = lib
$(shell mkdir -p $(LIBDIR) >/dev/null)

_OBJS = fancy_lib.o fancy.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

CXXFLAGS=-std=c++14 -fPIC -fvisibility=hidden -O3
LIBSTDCXX=-stdlib=libstdc++
LIBCXX=-stdlib=libc++ -lc++abi
BIN_LDFLAGS=-lfancy -Llib -Wl,-rpath,$(dir $(realpath $(firstword $(MAKEFILE_LIST))))/lib

.PHONY: all
all: fancy_doge fancy_sloth fancy_walrus fancy_gopher

.PHONY: clean
clean:
	    rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

$(OBJDIR)/%.o: %.cpp
	    @$(CXX) -c -o $@ $< $(CXXFLAGS)
			@echo "CXX $@"

libfancy.so: $(OBJS)
	    @$(CXX) -shared -o $(LIBDIR)/libfancy.so $(CXXFLAGS) $^
			@echo "LD $@"

fancy_doge.o: fancy_doge.cpp
			@$(CXX) -o $(OBJDIR)/fancy_doge.o -std=c++14 fancy_doge.cpp -c
			@echo "CXX $@"

fancy_sloth.o: fancy_sloth.cpp
			@$(CXX) -o $(OBJDIR)/fancy_sloth.o -std=c++14 -stdlib=libc++ fancy_sloth.cpp -c
			@echo "CXX $@"

fancy_walrus.o: fancy_walrus.c libfancy.so
			@$(CC) -o $(OBJDIR)/fancy_walrus.o fancy_walrus.c -c
			@echo "CC $@"

fancy_doge: fancy_doge.o libfancy.so
			@$(CXX) -o $(BINDIR)/fancy_doge $(BIN_LDFLAGS) -std=c++14 $(LIBSTDCXX) $(OBJDIR)/fancy_doge.o
			@echo "LD $@"

fancy_sloth: fancy_sloth.o libfancy.so
			@$(CXX) -o $(BINDIR)/fancy_sloth $(BIN_LDFLAGS) -std=c++14 $(LIBCXX) $(OBJDIR)/fancy_sloth.o
			@echo "LD $@"

fancy_walrus: fancy_walrus.o libfancy.so
			@$(CC) -o $(BINDIR)/fancy_walrus $(BIN_LDFLAGS) $(OBJDIR)/fancy_walrus.o
			@echo "LD $@"

fancy_gopher: export CGO_LDFLAGS=$(BIN_LDFLAGS)
fancy_gopher: libfancy.so
			@go build -o $(BINDIR)/fancy_gopher fancy_gopher.go
			@echo "GO $@"
