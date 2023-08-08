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

<video src="./assets/vid0.mp4" width="640" height="480" controls></video>

### Dependencies
RCG was created and tested on linux x86_64 based OS, install the following libraries according to your package manager and distribution.

```sh
# using apt (debian based distros)
sudo apt install libncurses-dev make
```

```sh
# using pacman (arch linux based distros)
sudo pacman -S ncurses make
```

### Installation
Follow the steps described below to download and install rcg.

```sh
# cloning the repository on the actual directory 
git clone --verbose https://github.com/KanzenTaiwa/rcg.git

# entering the directory
cd rcg/

# compiling the software
make

# executing the software
rcg
```

### Contribution
Forking and commiting the changes into this project will be analised and may be accepted according to the analisys, send a email using the one on LICENSE.

### License
This software is under the [MIT License](./LICENSE).