PROBLEMS := $(wildcard *)
PROBLEMS := $(filter-out template Makefile, $(PROBLEMS))
DCJ := ../../dcjtools/dcj.sh

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS):
	cd $@; \
	for s in submissions/*/*.cpp; do \
		for f in data/*/*.h; do \
			for n in 10 100; do \
				echo "$@: checking solution $$s on case $$f with $$n nodes"; \
				cp $$f $@.h; cp $$s $@.cpp; \
				diff="$$(time $(DCJ) test --source $@.cpp --nodes $$n --output all 2>/dev/null | diff - $${f%.*}.ans)"; \
				rm $@.h $@.cpp $@; \
				if [ $${#diff} -gt 0 ]; then \
					echo "error, diff:\n$$diff"; \
					exit 1; \
				fi; \
			done; \
		done; \
	done; \
