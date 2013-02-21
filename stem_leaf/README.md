# Stem and Leaf plot in Erlang

This module plots Stem and Leaf graph for a given array of integers.

```erlang
> List = lists:map(fun (_) -> random:uniform(100) end, lists:seq(1,20,1)).
[56,40,34,14,39,68,17,18,54,84,85,50,37,21,85,44,7,100,13,9]
> stem_leaf:plot(List).
    0|79
    1|3478
    2|1
    3|479
    4|04
    5|046
    6|8
    7|
    8|455
    9|
   10|0
ok
```

This module handles negative numbers too.

```erlang
> List2 = lists:map(fun (_) -> random:uniform(100) end, lists:seq(1,10,1)) ++ lists:map(fun (_) -> -random:uniform(100) end, lists:seq(1,10,1)).
[19,9,96,14,24,42,43,36,64,52,-43,-57,-30,-18,-48,-26,-28,-94,-67,-81]
> stem_leaf:plot(List2).
   -9|4
   -8|1
   -7|
   -6|7
   -5|7
   -4|83
   -3|
   -2|1086
   -1|8
   -0|
    0|9
    1|49
    2|4
    3|6
    4|23
    5|2
    6|4
    7|
    8|
    9|6
```
