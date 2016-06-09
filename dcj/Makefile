PROBLEMS := $(wildcard *.cpp)
DCJ := localtest/dcj.sh

all: $(PROBLEMS)
.PHONY: all $(PROBLEMS)

$(PROBLEMS):
	problem="$@"; problem=$${problem%.*}; \
	for f in $${problem}.*.h; do \
		for n in 10 100; do \
			echo "$@: checking case $$f with $$n nodes"; \
			case=$${f%.*}; case=$${case##*.}; \
			cp $$f $${problem}.h; \
			diff="$$($(DCJ) test --source $@ --nodes $$n --output all 2>/dev/null | diff - $${problem}.$${case}.ans)"; \
			rm $${problem}.h $${problem}; \
			if [ $${#diff} -gt 0 ]; then \
				echo "error, diff:\n$$diff"; \
				exit 1; \
			fi; \
		done; \
	done; \
