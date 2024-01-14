<h1 align="center"> Entity Component System (ECS) Documentation </h1>

<br>

<p align="center">
  <a href="#what-is-ecs?">What is ECS</a> &#xa0; | &#xa0;
  <a href="#characteristics">Characteristics</a> &#xa0; | &#xa0;
  <a href="#variants">Variants</a> &#xa0; | &#xa0;
  <a href="#what-is-a-server?">What is a Server?</a> &#xa0; | &#xa0;
  <a href="#what-is-a-client-?">What is a Client?</a> &#xa0; | &#xa0;
  <a href="#sources">Sources</a>
</p>

<br>

## What is ECS ##

Entity Component System (ECS) is a software architecture model primarily utilized in video game development for representing objects in the game world. ECS comprises entities composed of data components, with systems operating on these components. Unlike traditional inheritance-based models, ECS follows the principle of composition, where each entity is defined by its associated components. Systems operate universally on all entities possessing the necessary components.

### Characteristics ###

- `Entity`: Represents a general-purpose object, typically identified by a unique identifier (e.g., an integer).

- `Component`: Labels an entity with a specific aspect and contains data modeling that aspect (e.g., a Health component for damage susceptibility). Implementations use structures, classes, or associative arrays.

- `System`: A process that acts on entities with desired components. For instance, a physics system may operate on entities with mass, velocity, and position components.

Entities' behavior can be modified at runtime by systems, eliminating ambiguity found in deep and broad inheritance hierarchies. ECS is highly compatible with data-driven design, storing component data efficiently in physical memory for systems that operate on many entities.

### Variants ###

Different ECS implementations may vary in data layout, component definitions, and how systems access entity components. An entity often consists only of an ID, offering advantages like robust referencing, external state storage, and efficient memory access.

Examples of ECS variants include:

- **Unity Game Engine**: Utilizes tables with columns of components, defining entity types based on their components. Archetypes contain component columns, and entities are accessed by finding the correct archetype and indexing into component columns.

- **Apparatus for Unreal Engine**: Introduces type hierarchy support for components, allowing systems to query base component types and match all descendants. This adds flexibility to ECS by supporting common logic on different components.

### What is a Server? ###

A server, in computing, is hardware or software providing functionality for clients. Servers can offer various services, such as data sharing or computation. Servers operate on the client-server model, responding to client requests. This architecture allows a single server to serve multiple clients, running on the same or different devices.

### What is a Client? ###

A client is a computer or program that sends requests to access services provided by a server. Clients can include web browsers, email clients, or multiplayer game instances. In a client-server model, clients connect to servers, and the term applies to both devices running client software and users using client software.

## How To Use the UCS

### Create an Entity

```cpp
    // Create a new entity and store its identifier in the variable 'player'
    int player = components->createEntity();

    // Add a "Drawable" component to the entity, representing the graphical appearance with a specified image and dimensions
    components->setComponentToEntity(player, "Drawable", Draw("asset/space.png", 100, 50));

    // Add a "HitboxR" component to the entity, representing a rectangular collision box with specified dimensions
    components->setComponentToEntity(player, "HitboxR", Hitbox(100, 50));

    // Add a "Position" component to the entity, specifying its initial position in the game space
    components->setComponentToEntity(player, "Position", Position(50, 50));

    // Add a "Speed" component to the entity, representing the movement speed
    components->setComponentToEntity(player, "Speed", Speed());

    // Add a "Control" component to the entity, specifying the controls associated with this entity (here, a player identifier -1)
    components->setComponentToEntity(player, "Control", Control(-1));

    // Add a "Shoot" component to the entity, representing the shooting capability of the entity
    components->setComponentToEntity(player, "Shoot", Shoot());

    // Add a "Health" component to the entity, specifying the health of the entity (here, initialized to 50)
    components->setComponentToEntity(player, "Health", Health(50));

    // Add a "Team" component to the entity, specifying the team to which the entity belongs (here, team 1)
    components->setComponentToEntity(player, "Team", Team(1));

    // The function does not seem to use the 'path' parameter, and it does not return anything (void).

    // Return the identifier of the newly created entity (may be useful depending on code usage)
    return player;

```


## Sources ##

- [Entity Component System - Wikipedia](https://en.wikipedia.org/wiki/Entity_component_system)
- [Server (computing) - Wikipedia](https://en.wikipedia.org/wiki/Server_(computing))
- [Client (computing) - Wikipedia](https://en.wikipedia.org/wiki/Client_(computing))
- ECS-documentation.md
