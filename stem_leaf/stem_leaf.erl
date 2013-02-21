-module(stem_leaf).
-export([plot/1]).

bucket(N) when N < -9 -> 
    N - ((N+10) rem 10);
bucket(N) ->
    (N+10) - ((N+10) rem 10).

leaf(N, Bucket) when N < 0 ->
    Bucket - N;
leaf(N, Bucket) ->
    ((N + 10) - Bucket).

print_stem(0) ->
    io:format("~5s|", ["-0"]);
print_stem(N) when N < 0 ->
    io:format("~5B|", [N div 10]);
print_stem(N) ->
    io:format("~5B|", [N div 10 - 1]).

plot_leaf([H|T], Bucket) when is_integer(H) andalso H =< Bucket -> 
    io:format("~w", [leaf(H, Bucket)]), plot_leaf(T, Bucket);
plot_leaf([H|T], Bucket) when is_integer(H) -> 
    io:format("~n"), plot_stem([H|T], Bucket+10);
plot_leaf([], _Bucket) -> 
    io:format("~n").

plot_stem(Data, Bucket) -> 
    print_stem(Bucket),
    plot_leaf(Data, Bucket).

plot_sorted(Data) -> plot_stem(Data, bucket(hd(Data))).

plot([]) -> io:format("~n");
plot(Data) when is_list(Data) -> plot_sorted(lists:sort(Data)).
