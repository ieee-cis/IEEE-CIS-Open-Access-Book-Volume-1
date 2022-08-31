Simulated Annealing
===================

This is the Supplementary Material to the chapter on Simulated Annealing (SA). In the ```code''' folder you can find
the code we used in the experiments presented in this chapter, and the scripts to automatically configure and generate
SA algorithms. 
In the ```data''' folder we provide the instances used in our experiments.


How to instantiate a simulated annealing
========================================

First, install the ```emili``` framework. The code provided in this Supplementary Material corresponds to the ```sa''' branch of the official [repository](https://github.com/federicoPagnozzi/emili), to which we refer for more advanced instructions. For the purpose of this chapter, the following commands are sufficient:

```
cd code/emili
mkdir build
cd build
cmake ../
make
```

Launch ```emili``` as (e.g.)
```
emili path/to/instanceFile QAP SA random exchange RANDOMWALKINITTEMP 10000 8.979 METROPOLIS LINEARCOOLING 0.9163 SASQUAREDNEIGHSIZEMAXITERSTEMPRESTART 83 NEVERTERM PROBSIZETEMPLEN 51 SARANDOMEXPLORATION -it 10
```

The flag ```-it 10''' indicates a runtime cutoff of 10 seconds.

How to tune or generate a simulated annealing
=============================================

Use the template scripts provided in ```code/tuning'''.

Install the [```irace``` configurator](https://iridia.ulb.ac.be/irace/).

Add the training instances in the ```instances.txt``` file.

Set the correct paths and the parameters for the tuning in ```scenario.txt```. Set the correct paths in ```target-runner```.

Select the desired grammar (or edit one), generate the parameter for ```irace``` with
```
grammar2code grammar.xml -p parameters.txt
```
and launch the tuning with ```irace```.
~                                             
