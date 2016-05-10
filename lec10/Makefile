default: build/Makefile
	make -C build

TEST = Int_vector_tests

hard: build/$(TEST)
	$<

build/$(TEST): build/Makefile
	make -C build $(TEST)

build/Makefile: CMakeLists.txt
	mkdir -p build
	cd build; cmake ..
