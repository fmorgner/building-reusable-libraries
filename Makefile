.PHONY: cppugzh_building_libraries.pdf all clean code/box code/fancy1 code/fancy2 code/nopimpl code/pimpl

all: cppugzh_building_libraries.pdf

cppugzh_building_libraries.pdf: cppugzh_building_libraries.tex code/box code/fancy1 code/fancy2 code/nopimpl code/pimpl
	@latexmk -output-directory=build \
					 -pdf \
					 -pdflatex="xelatex --shell-escape -interaction=errorstopmode" \
					 -quiet \
					 cppugzh_building_libraries >/dev/null && \
	cp -u build/cppugzh_building_libraries.pdf .

code/box:
	@$(MAKE) -C code/box
	@echo "DEMO box"

code/fancy1:
	@$(MAKE) -C code/fancy1 -i
	@echo "DEMO fancy1"

code/fancy2:
	@$(MAKE) -C code/fancy2
	@echo "DEMO fancy2"

code/nopimpl:
	@$(MAKE) -C code/nopimpl
	@echo "DEMO nopimpl"

code/pimpl:
	@$(MAKE) -C code/pimpl
	@echo "DEMO pimpl"

clean:
	@latexmk -CA -output-directory=build &>/dev/null
	@echo "CLEAN latex"
	@rm -rf build/minted
	@echo "CLEAN minted"
	@$(MAKE) -C code/box clean
	@echo "CLEAN code/box"
	@$(MAKE) -C code/fancy1 clean
	@echo "CLEAN code/fancy1"
	@$(MAKE) -C code/fancy2 clean
	@echo "CLEAN code/fancy2"
	@$(MAKE) -C code/nopimpl clean
	@echo "CLEAN code/nopimpl"
	@$(MAKE) -C code/pimpl clean
	@echo "CLEAN code/pimpl"
