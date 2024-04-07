PATHU = unity/
PATHS = src/
PATHT = test/
PATHB = build/
PATHD = build/depends/
PATHO = build/objs/
PATHR = build/results/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRCT = $(wildcard $(PATHT)*.c)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
CFLAGS=-I. -I$(PATHU) -I(PATHS) -DTest

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo `grep -s IGNORE $(PATHR)*.txt`
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo `grep -s FAIL $(PATHR)*.txt`
	@echo "\nDONE"
