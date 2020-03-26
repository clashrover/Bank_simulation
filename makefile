final = ./bin/qSim

qSim:
	gcc ./src/qSim.c -o ./bin/qSim
	./bin/qSim 100 4 60 2.3
	./bin/qSim 100 5 60 2.3
	./bin/qSim 100 6 60 2.3
	./bin/qSim 100 7 60 2.3
	./bin/qSim 100 8 60 2.3
	./bin/qSim 100 9 60 2.3
	./bin/qSim 100 10 60 2.3
	./bin/qSim 100 11 60 2.3
	./bin/qSim 100 12 60 2.3
.PHONY: RUN clean no_stats last_modified
# specific commands
RUN: 
	@echo ".............\nRunning final exectuable\n............." 
	@$(final) 
	


clean:
	@echo "All exe and obj cleared" 
	@rm -f ./bin/* ./ouput/*
	@#@ is used to silence the make command/comment

no_stats:
	@make -s

last_modified:
	@echo "last modified $(NUM) files are =>"
	@find . -type f -printf '%T@ %p\n' | sort -k1,1nr | head -$(NUM)

