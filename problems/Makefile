PROBLEMS := $(wildcard *)
PROBLEMS := $(filter-out template Makefile, $(PROBLEMS))

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS): 
	verifyproblem -p config submissions -l warning $@
