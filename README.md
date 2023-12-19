
# R-TYPE Project

![R-TYPE](https://m.media-amazon.com/images/I/911DV9FiRTL.png)

The goal of this project is to implement a multithreaded server and a graphical client for a well-known legacy video game
called R-Type, using a game engine of your own design.

# Table of contents

1.[Libraries](#libraries)
2.[Prerequisites](#prerequisites)
3.[Build the program](#build-the-program)
4.[Commit Norme](#commit-norme)
5.[Networking](#networking)
6.[Documentation](#documentation)


## Libraries

The project is composed of two parts, both in C++:
- **The server**
- **The client**

Using thoses libraries:

- **Asio:** used to manage communication threads and processes.
- **SMFL:** used to display.

## Prerequisites

To build our project, you will need, C++ 20 and CMake 3.17.0 Compiler.
## Build the program

**Linux:**

```bash
cmake . -G "Unix Makefiles" && cmake --build .
```

**Windows:**

```bash
Launch with visual studio
cmake
```
## Example of use

**To launch the server:**

```bash
./server --help
Options:
  --help                 Show help message
  --tcp_port arg (=8082) Specify the TCP port number
  --udp_port arg (=8080) Specify the UDP port number
```

**To launch the client:**

```bash
./client
```
## Commit Norme

Git is a widely used distributed version control system for tracking changes in source code during software development.

The commit convention, often referred to as a commit message convention, is a practice of following a set of rules or guidelines when writing commit messages in a Git repository. The primary goal of this convention is to make the source code history more readable, understandable, and consistent.

A Conventional Commits message typically consists of the following elements:

**Type:** Indicates the purpose of the commit (e.g., feat for a new feature, fix for a bug fix, docs for documentation changes, etc.).

**Optional - Scope:** Optional but can indicate the scope of the change (i.e., the section of code or module affected).

**Description:** A brief description of the change.

An example of a Conventional Commits compliant commit message might look like this:

```bash
feat: add connection functional
```
```bash
fix(database): resolve issue with data retrieval
```
Using a commit convention like Conventional Commits makes it easier to automate the process of generating release notes, managing versions, and quickly understanding the changes made to a project
## Network

The network serves as the vital core of this project, acting as its operational brain. Its essential function involves receiving all data transmitted by clients, subjecting them to a sophisticated processing mechanism, and ultimately redistributing the generated results to all stakeholders. This strategic component ensures effective management of information exchanges, thereby guaranteeing cohesion and overall project performance.

![Schema](https://media.discordapp.net/attachments/1178690622962552973/1184529314214072450/image.png?ex=658c4de3&is=6579d8e3&hm=7af3c79575854d5c02b0a2cfc57b099a62683f460fcebbe9a7c2c8c0bdf0ee19&=&format=webp&quality=lossless&width=810&height=338)
## Documentation

The code documentation is available here.

## Authors


- [@Bilal-Tech18](https://www.github.com/Bilal-Tech18)

- [@nellyyng](https://www.github.com/nellyyng)

- [@Fanks12](https://www.github.com/Fanks12)

- [@AdrianLalardi](https://www.github.com/AdrianLalardi)

- [@Nathan-Warin](https://ww.github.com/Nathan-Warin)