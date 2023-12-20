

# R-TYPE Project

![R-TYPE](https://m.media-amazon.com/images/I/911DV9FiRTL.png)

The goal of this project is to implement a multithreaded server and a graphical client for a well-known legacy video game
called R-Type, using a game engine of your own design.

# Table of contents

1.[Libraries](#libraries)

2.[Prerequisites](#prerequisites)

3.[Build the program](#build-the-program)

4.[Commit Norme](#commit-norme)

5.[Network](#network)

6.[ECS](#ecs)

7.[Documentation](#documentation)

8.[Contribution to R-TYPE](#contribution-to-r-type)

9.[Adding a new feature to R-TYPE](#adding-a-new-feature-to-r-type)


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
./make.sh
```

**Windows:**

Launch with visual studio:
```bash
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

The Network is the brain of this project. It going to receive all the data from the client, process them, and return the result to all the clients.

![Schema](https://media.discordapp.net/attachments/1178690622962552973/1184529314214072450/image.png?ex=658c4de3&is=6579d8e3&hm=7af3c79575854d5c02b0a2cfc57b099a62683f460fcebbe9a7c2c8c0bdf0ee19&=&format=webp&quality=lossless&width=810&height=338)

## ECS

An ECS is an architectural design pattern, mostly used in video game development. This pattern follows
the principle of composition over inheritance. Instead of defining an inheritance tree as usual in Object Ori-
ented Programming, types are split into small yet highly reusable components.

![ECS_SCHEMA](https://media.discordapp.net/attachments/1168528267754614964/1187012022051803156/ECS_CHEMA.png?ex=65955617&is=6582e117&hm=a775f25179079b8cab0157a702ad7337d999cab5f4125e92f0378f8bc6e6e128&=&format=webp&quality=lossless&width=810&height=599)


## Documentation

The code documentation is available [here]().

## Contributing to R-Type

In this document are enumerated the different guidelines related to the contribution to R-Type 🚀.

### Repository structure

- **ECS** : An indispensable directory housing the essential libraries required for the composition of the R-Type project can be found there.

  Keep in mind that the most important part of the R-Type is in this directory.

- **Networking** : This library encapsulates the networking components of R-Type, encompassing the core Sync system and its associated sub-systems.


- **CMakeLists.txt** : We use CMake to build this project. If you don't know how it works, you probably should take a look at the cmake's documentation.

- **server** : Directory containing the C++ source files for the server's part.

- **client** : Directory containing the C++ source files for the client's part.

## Adding a new feature to R-Type

To seamlessly integrate a new aspect into R-Type, adhere to the following procedural steps:

**1.** Create a new branch labeled feature/XX, derived from the primary branch, where XX offers a descriptive identifier for your feature.

**2.** Upon completion of your work, initiate a pull request under the title Feature: XXXX (where XXXX represents a concise commentary on your feature) directed towards the main branch.

**3.** Solicit a comprehensive review during this stage.
Engage in an iterative process, addressing and incorporating feedback and requests as necessary.

**4.** Once all aspects are deemed satisfactory and receive approval, proceed with merging your pull request into the main branch.

**5.** Congratulations, you have successfully introduced a new feature to R-Type!

## Authors


- [@Bilal-Tech18](https://www.github.com/Bilal-Tech18)

- [@nellyyng](https://www.github.com/nellyyng)

- [@Fanks12](https://www.github.com/Fanks12)

- [@AdrianLalardi](https://www.github.com/AdrianLalardi)

- [@Nathan-Warin](https://ww.github.com/Nathan-Warin)