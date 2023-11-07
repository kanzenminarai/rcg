```
██████╗     ██████╗    ██████╗
██╔══██╗   ██╔════╝   ██╔════╝
██████╔╝   ██║        ██║  ███╗
██╔══██╗   ██║        ██║   ██║
██║  ██║██╗╚██████╗██╗╚██████╔╝
╚═╝  ╚═╝╚═╝ ╚═════╝╚═╝ ╚═════╝
```

### About
 Random Character Generator is a open source software that generates random assortments of characters, like letters, numbers and symbols 
according to the inserted length and type of characters selected, all through the input.

![rcg](assets/rcg.gif)

### Dependencies
 RCG was created and tested on Linux (x86_64), install the following libraries according to your package manager and distribution.
```sh
# apt (debian based distros)
sudo apt install git libncurses-dev make gcc
```

```sh
# pacman (arch linux based distros)
sudo pacman -S git ncurses make gcc
```

### Install
 Follow the steps described below to download and install rcg.
```sh
# clone the repository
git clone --verbose https://github.com/KanzenTaiwa/rcg.git

# enter inside the directory
cd rcg/

# compile
make

# compile and install
sudo make install

# (optional) remove built files
make clean
```

### Usage
```sh
# run using help argument to print the usage screen
rcg help

# run using generate will print the characters according to input in the command line
rcg generate [size] [type]

# run
rcg

# run locally built
./rcg
```

### Uninstall
```sh
# delete and leave built files
sudo make uninstall

# delete all
sudo make clean uninstall
```

### Contribution
 Pull requests will be analysed and can be accepted if everything is solved through a conversation, explain all the changes 
through comments in the code about every change done, at the same style as the source code, please send a message on my discord: **kanzenminarai** or even by email using the one listed in the LICENSE file if you desire to talk.

### License
This software is under the [Zero Clause BSD License](./LICENSE).
