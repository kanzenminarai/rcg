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
according to the inserted length and type of characters selected.

![rcg](assets/rcg.gif)

### Dependencies
 RCG was created and tested on Linux (x86-64), install the following libraries according to your package manager and distribution.
```sh
# apt
sudo apt install git libncurses-dev make gcc
```

```sh
# pacman
sudo pacman -S git ncurses make gcc
```

### Install
 Follow the steps described below to download and install rcg.
```sh
# clone the repository
git clone --verbose https://github.com/KanzenTaiwa/rcg.git

# enter inside the directory
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

# help argument print the usage screen
rcg help

# generate create and print the characters according to input in the command line
rcg generate [size] [type]
```

### Uninstall
```sh
# delete all
sudo make clean uninstall
```

### Contribution
 Pull requests will be analysed and can be accepted if everything is solved through a conversation, explain all the changes 
through comments in the code about every change done, at the same style as the source code, please send a message on my discord: **kanzenminarai** or even by email using the one listed in the LICENSE file if you wish to talk.

### License
This software is under the [Zero Clause BSD License](./LICENSE).
