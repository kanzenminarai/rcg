# Random Character Generator

### About
 rcg is a open source software that generates pseudo-random characters, like letters, numbers and symbols 
according to the inserted length and type of characters selected.

![rcg](assets/rcg.gif)

### Dependencies
 rcg was created and tested on Linux system (x86-64 intel), install the following libraries according to your package manager.
```sh
# apt
sudo apt install git libncurses-dev make gcc
```

```sh
# pacman
sudo pacman -S git ncurses make gcc
```

### Install
 Follow the steps described below to download and compile the software.
```sh
# clone the repository
git clone --verbose https://github.com/KanzenMinarai/rcg.git

# change the directory
cd rcg/

# compile and install
sudo make install

# remove built files
make clean
```

### Usage
```sh
# run
rcg

# help argument prints the usage screen
rcg help

# generate create and print the characters according to input in the command line
rcg generate [size] [type]
```

### Uninstall
```sh
sudo make clean uninstall
```

### Contribution
 Pull requests or any Contribution to the code are analysed and accepted if everything is solved through a conversation,
please explain all the changes done in the code and everything that was added, the coding style tries to follow the
principles of "the clean code", please send a message on my discord: **kanzenminarai** or even by
email using the one listed in the [LICENSE](./LICENSE) file if you wish to talk or discuss.

### License
This software is under the [Zero Clause BSD License](./LICENSE).
