```
██████╗     ██████╗    ██████╗
██╔══██╗   ██╔════╝   ██╔════╝
██████╔╝   ██║        ██║  ███╗
██╔══██╗   ██║        ██║   ██║
██║  ██║██╗╚██████╗██╗╚██████╔╝
╚═╝  ╚═╝╚═╝ ╚═════╝╚═╝ ╚═════╝
```

##### Formerly: _Random Character Generator_

### About
RCG is a open source software that generates random assortments of characters, like letters, numbers and symbols according to the
inserted length and type of characters selected, all through the input.

https://github.com/KanzenTaiwa/rcg/assets/120531165/c6787a2f-31de-4e86-aa95-384f26271783

### Dependencies
RCG was created and tested on linux x86_64 based OS, install the following libraries according to your package manager and distribution.
```sh
# using apt (debian-based distros)
sudo apt install libncurses-dev make gcc
```

```sh
# using pacman (arch linux based distros)
sudo pacman -S ncurses make gcc
```

### Install
Follow the steps described below to download and install rcg.
```sh
# clone the repository
git clone --verbose https://github.com/KanzenTaiwa/rcg.git

# enter inside of rcg directory
cd rcg/

# compile
make

# compile and install
sudo make install

# remove built files
make clean
```

### Execute
```sh
# run the installed software
rcg

# run the locally built software
./rcg
```

### Uninstall
```sh
# delete the installed software
sudo make uninstall
```

### Contribution
Forking and merging back changes to this project will be analysed and may be accepted according to the analysis, send a message
on discord: **kanzentaiwa** or even an email using the one in the LICENSE file.

### License
This software is under the [MIT License](./LICENSE).
