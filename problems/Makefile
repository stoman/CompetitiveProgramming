PROBLEMS := $(wildcard *)
PROBLEMS := $(filter-out template Makefile, $(PROBLEMS))

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS): 
	../problemtools/bin/verifyproblem.sh -p config submissions -l warning $@
