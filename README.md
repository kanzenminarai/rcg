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
Rcg or Random Character Generator is an open source software that generates random assortments of characters, like letters, numbers and symbols according to the
inserted lenght and type of characters selected, all through the input.

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

# optional: only compile
make

# compile and install
make install

# optional: remove object files
make clean
```

### Execute
```sh
# execute the software (installed version)
rcg

# or use make (locally built version)
make run
```

### Uninstall
```sh
# in case of a removal
make uninstall
```

### Contribution
Forking and merging back changes to this project will be analysed and may be accepted according to the analysis, send an email using the one in the LICENSE file.

### License
This software is licensed under the [MIT License](./LICENSE).
