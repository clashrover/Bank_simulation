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
	./bin/qSim 100 13 60 2.3
	./bin/qSim 100 14 60 2.3
	./bin/qSim 100 15 60 2.3
	./bin/qSim 100 16 60 2.3
	./bin/qSim 100 17 60 2.3
	./bin/qSim 100 18 60 2.3
	./bin/qSim 100 19 60 2.3
	./bin/qSim 100 100 60 2.3
	./bin/qSim 100 21 60 2.3
	./bin/qSim 100 22 60 2.3
	./bin/qSim 100 23 60 2.3
	./bin/qSim 100 24 60 2.3
	./bin/qSim 100 25 60 2.3
	./bin/qSim 100 26 60 2.3
	./bin/qSim 100 27 60 2.3
	./bin/qSim 100 28 60 2.3
	./bin/qSim 100 29 60 2.3
	./bin/qSim 100 30 60 2.3
	./bin/qSim 100 31 60 2.3
	./bin/qSim 100 32 60 2.3
	./bin/qSim 100 33 60 2.3
	./bin/qSim 100 34 60 2.3
	./bin/qSim 100 35 60 2.3
	./bin/qSim 100 36 60 2.3
	./bin/qSim 100 37 60 2.3
	./bin/qSim 100 38 60 2.3
	./bin/qSim 100 39 60 2.3
.PHONY: RUN clean no_stats last_modified
# specific commands
RUN: 
	@echo ".............\nRunning final exectuable\n............." 
	@$(final) 
	


clean:
	@echo "All exe and obj cleared" 
	@rm ./bin/* ./output/* 
	@#@ is used to silence the make command/comment

no_stats:
	@make -s

last_modified:
	@echo "last modified $(NUM) files are =>"
	@find . -type f -printf '%T@ %p\n' | sort -k1,1nr | head -$(NUM)

