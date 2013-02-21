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
