# EV
EV is my take on using machine learning to train virtual creatures.



![ev screenshot](https://raw.githubusercontent.com/alobo/loboaaron.com/master/content/images/ev-preview.jpg)

## Theory

### Creatures
A creatre is simply a circle (red) with an eye (green) and a field of view (white triangle). Creatures have a finite energy supply which depletes over time - if this is not replenished by eating, the creature dies. A creature can move within the environment by rotating and accelerating forward.

### Environment
The environment is 2-dimensional and rendered in a top-down view. It is backed by a simple rigid-body physics engine, which allows the creatures to have realistic interactions with the walls and each other. The environment is also randomly seeded with 100 pieces of 'food' (yellow circles).

### Neural Network
The creatres are backed by a neural network consisting of an input, output and two hidden layers.

Inputs into the neural net currently consist of distance to closest food and the creature's energy level. The outputs of the network control the creature's rotation and forward acceleration.

![ev neural net](https://raw.githubusercontent.com/alobo/loboaaron.com/master/content/images/ev-2.png)

### Evolution
The neural network is trained using a genetic algorithm and based on a simplistic model of evolution in nature.

The initial population of creatres are created with randomized network weightings. At the end of every generation (30 seconds), the most sucessful creatures - those with the highest energy - are taken, their networks are then duplicated and mutated and reintroduced into the environment as the next generation.

## Results
With generation 0, the creatures exhibit erratic behaviour, either spinning in place, shooting off to the corners or showing a weak attraction to food. Interesting patterns emerge after approximately 10 generations - creatures now actively 'hunt' for food and demonstrate markedly better control over movement.

## Requirements
* [SFML](http://www.sfml-dev.org/) - Used for rendering graphics ([zlib/png license](http://www.sfml-dev.org/license.php))
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) - Used to perform linear algebra calculations ([MPL2 licence](http://eigen.tuxfamily.org/index.php?title=Main_Page#License))

## Installation
* Install SFML: ```sudo apt-get install libsfml-dev```
* Install Eigen: ```sudo apt-get install libeigen3-dev```
* Clone the repo and run ```make```
