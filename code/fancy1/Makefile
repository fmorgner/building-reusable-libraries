OBJDIR = obj
$(shell mkdir -p $(OBJDIR) >/dev/null)

BINDIR = bin
$(shell mkdir -p $(BINDIR) >/dev/null)

LIBDIR = lib
$(shell mkdir -p $(LIBDIR) >/dev/null)

LOGDIR = log
$(shell mkdir -p $(LOGDIR) >/dev/null)

_OBJS = fancy.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

CXXFLAGS=-std=c++14 -fPIC
LIBSTDCXX=-stdlib=libstdc++
LIBCXX=-stdlib=libc++ -lc++abi
BIN_LDFLAGS=-lfancy -Llib -Wl,-rpath,$(dir $(realpath $(firstword $(MAKEFILE_LIST))))/lib

.PHONY: all clean

all: fancy_doge fancy_sloth

clean:
	    rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR) $(LOGDIR)

$(OBJDIR)/%.o: %.cpp
	    @$(CXX) -c -o $@ $< $(CXXFLAGS)
			@echo "CXX $@"

libfancy.so: $(OBJS)
	    @$(CXX) -shared -o $(LIBDIR)/libfancy.so $^
			@echo "LD $@"

fancy_doge: libfancy.so fancy_doge.cpp
			@$(CXX) -o $(BINDIR)/fancy_doge $(BIN_LDFLAGS) -std=c++14 $(LIBSTDCXX) fancy_doge.cpp
			@echo "CXX/BIN $@"

fancy_sloth: libfancy.so fancy_sloth.cpp
			@$(CXX) -o $(BINDIR)/fancy_sloth $(BIN_LDFLAGS) -std=c++14 $(LIBCXX) fancy_sloth.cpp 2>$(LOGDIR)/fancy_sloth.log || true
			@echo "CXX/BIN $@"

