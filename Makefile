


dependencies: 
	sudo apt update
	sudo apt install \
		libxrandr-dev \
		libxcursor-dev \
		libudev-dev \
		libopenal-dev \
		libflac-dev \
		libvorbis-dev \
		libgl1-mesa-dev \
		libegl1-mesa-dev \
		libdrm-dev \
		libgbm-dev \
		libfreetype6-dev

all: 
	cmake -B build -DCMAKE_BUILD_TYPE=Release
	cmake --build build --config Release
	./build/bin/main

build-cmake: 
	cmake -B build -DCMAKE_BUILD_TYPE=Release
	cmake --build build --config Release

run: 
	./build/bin/main