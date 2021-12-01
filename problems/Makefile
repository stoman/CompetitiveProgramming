PROBLEMS := $(wildcard *)
PROBLEMS := $(filter-out template Makefile, $(PROBLEMS))

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS): 
	~/.local/bin/verifyproblem -p config submissions -l warning $@
