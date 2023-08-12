```
██████╗     ██████╗    ██████╗
██╔══██╗   ██╔════╝   ██╔════╝
██████╔╝   ██║        ██║  ███╗
██╔══██╗   ██║        ██║   ██║
██║  ██║██╗╚██████╗██╗╚██████╔╝
╚═╝  ╚═╝╚═╝ ╚═════╝╚═╝ ╚═════╝
```

##### Formely: _Random Character Generator_

### About
Rcg or Random Character Generator is a open source software that generates randomic characters, like letters, numbers and symbols according to the
inserted size and the type of characters selected, all through the input.

https://github.com/KanzenTaiwa/rcg/assets/120531165/c6787a2f-31de-4e86-aa95-384f26271783

### Dependencies
RCG was created and tested on linux x86_64 based OS, install the following libraries according to your package manager and distribution.
```sh
# using apt (debian based distros)
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

# compile and install
make install

# optional: removing object files
make clean
```

### Initializing
```sh
# execute the software (global)
rcg

# or use make (local)
make run
```

### Uninstall
```sh
# in case of a removal
make uninstall
```

### Contribution
Forking and commiting the changes into this project will be analised and may be accepted according to the analisys, send a email using the one on LICENSE.

### License
This software is under the [MIT License](./LICENSE).