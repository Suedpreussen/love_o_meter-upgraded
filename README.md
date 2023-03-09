# love_o_meter-upgraded

I changed the code so that LED expresses the temperature more aptly.

The main new functionality is that this system has an output that is continuously dependent on the temperature. The frequency of LED flickering is dependent on the temperature so that, as I touch the temperature sensor, the LED flickers faster.
This dependency is stronger for smaller differences between baseline temperature and the cureent one and gets weaker the greater the difference is. That way the effect is more visible from the very start and stays stable for some bigger deviations.

Electrical system is the same as in the Handbook except it utilises only one LED instead of three.
