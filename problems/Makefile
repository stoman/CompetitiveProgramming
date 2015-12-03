PROBLEMS = solvemefirst timeconversion

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS): 
	../problemtools/src/verifyproblem.py -p config submissions -l warning $@
