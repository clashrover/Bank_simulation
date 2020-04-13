final = ./bin/qSim

qSim:
	gcc ./src/qSim.c -o ./bin/qSim
	./bin/qSim 5000 2 60 2.3
	./bin/qSim 5000 3 60 2.3
	./bin/qSim 5000 4 60 2.3
	./bin/qSim 5000 5 60 2.3
	./bin/qSim 5000 6 60 2.3
	./bin/qSim 5000 4 60 2.3
	./bin/qSim 5000 5 60 2.3
	./bin/qSim 5000 6 60 2.3
	./bin/qSim 5000 7 60 2.3
	./bin/qSim 5000 8 60 2.3
	./bin/qSim 5000 9 60 2.3
	./bin/qSim 5000 10 60 2.3
	./bin/qSim 5000 11 60 2.3
	./bin/qSim 5000 12 60 2.3
	./bin/qSim 5000 13 60 2.3
	./bin/qSim 5000 14 60 2.3
	./bin/qSim 5000 15 60 2.3
	./bin/qSim 5000 16 60 2.3
	./bin/qSim 5000 17 60 2.3
	./bin/qSim 5000 18 60 2.3
	./bin/qSim 5000 19 60 2.3
	./bin/qSim 5000 20 60 2.3
	./bin/qSim 5000 21 60 2.3
	./bin/qSim 5000 22 60 2.3
	./bin/qSim 5000 23 60 2.3
	./bin/qSim 5000 24 60 2.3
	./bin/qSim 5000 25 60 2.3
	./bin/qSim 5000 26 60 2.3
	./bin/qSim 5000 27 60 2.3
	./bin/qSim 5000 28 60 2.3
	./bin/qSim 5000 29 60 2.3
	./bin/qSim 5000 30 60 2.3
	./bin/qSim 5000 31 60 2.3
	./bin/qSim 5000 32 60 2.3
	./bin/qSim 5000 33 60 2.3
	./bin/qSim 5000 34 60 2.3
	./bin/qSim 5000 35 60 2.3
	./bin/qSim 5000 36 60 2.3
	./bin/qSim 5000 37 60 2.3
	./bin/qSim 5000 38 60 2.3
	./bin/qSim 5000 39 60 2.3
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

