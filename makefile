dev:
	g++ --std=gnu++17 scan.cpp -o scan -g

prod:
	g++ --std=gnu++17 scan.cpp -o scan 

clean:
	rm scan
