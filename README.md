# simple-editor

this repo is a simple text editor written with Qt and c++

## features
- writing bold text
- writing subscript and super script texts

## how to install 
1. clone the repository by `git clone https://github.com/sjkrb/simple-editor.git`
2. make sure that you have `build-essential` and `Qt` if you're using an Ubuntu machine
3. add `cd simple-editor`
4. create a new build directory `mkdir build`
5. go to build directory and use CMake `cd build && cmake ..`
6. if you prefer to use ninja, you can specify by typing `cmake -G Ninja ..`
7. whether you used ninja or Makefile, just type `ninja` or `make` to compile

## contributions
- [ ] add state for writing instead of selecting texts https://github.com/sjkrb/simple-editor/issues/2
- [ ] write bold subscript and superscript https://github.com/sjkrb/simple-editor/issues/1
- [ ] add better support for Unicode 
- [x] add save and load https://github.com/sjkrb/simple-editor/issues/4
