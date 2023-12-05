dev:
	g++ --std=gnu++17 scan.cpp algorithm.cpp -o scanDebug -g

prod:
	g++ --std=gnu++17 scan.cpp algorithm.cpp -o scan 

clean:
	rm scan
