CXXFLAGS=-std=c++14

DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)

OBJDIR = obj
$(shell mkdir -p $(OBJDIR) >/dev/null)

BINDIR = bin
$(shell mkdir -p $(BINDIR) >/dev/null)

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
COMPILE.cxx = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c
POSTCOMPILE = mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d
SRCS = unicorn.cpp freddy.cpp

_OBJS = unicorn.o freddy.o
OBJS = $(patsubst %,$(OBJDIR)/%,$(_OBJS))

.PHONY: all clean

all: $(BINDIR)/freddy

clean:
	    @rm -f $(OBJDIR)/*.o bin/* $(DEPDIR)/*.d

$(OBJDIR)/%.o: %.cpp
$(OBJDIR)/%.o: %.cpp $(DEPDIR)/%.d
			@$(COMPILE.cxx) $(OUTPUT_OPTION) $<
			@$(POSTCOMPILE)
			@echo "CXX $<"

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

$(BINDIR)/freddy: $(OBJS)
			@$(CXX) -o $(BINDIR)/freddy -std=c++14 $^
			@echo "LD $@"

-include $(patsubst %,$(DEPDIR)/%.d,$(basename $(SRCS)))
