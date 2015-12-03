PROBLEMS := $(wildcard *)
PROBLEMS := $(filter-out template Makefile, $(PROBLEMS))

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS): 
	../problemtools/src/verifyproblem.py -p config submissions -l warning $@
