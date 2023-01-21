:- style_check(-singleton).

schedule(istanbul, izmir, 2).
schedule(istanbul, rize, 4).
schedule(istanbul, ankara, 1).

schedule(rize, istanbul, 4).
schedule(rize, ankara, 5).

schedule(ankara, rize, 5).
schedule(ankara, istanbul, 1).
schedule(ankara, van, 4).
schedule(ankara, izmir, 6).
schedule(ankara, diyarbakir, 8).

schedule(van, ankara, 4).
schedule(van, gaziantep, 3).

schedule(diyarbakir, ankara, 8).
schedule(diyarbakir, antalya, 4).

schedule(gaziantep, van, 3).

schedule(izmir, istanbul, 2).
schedule(izmir, ankara, 6).
schedule(izmir, antalya, 2).

schedule(antalya, diyarbakir, 4).
schedule(antalya, izmir, 2).
schedule(antalya, erzincan, 3).

schedule(erzincan, antalya, 3).
schedule(erzincan, canakkale, 6).

schedule(canakkale, erzincan, 6).

%ADDITIONS
schedule(canakkale, gaziantep, 10).
schedule(gaziantep, canakkale, 10).
schedule(istanbul, erzincan, 7).
schedule(erzincan, istanbul, 7).

connection(X, Y, C) :- schedule(X, Y, C).

route_finder(S, D, C) :-
    route_finder(S, D, C, []).

route_finder(S, D, C, Visiteds) :-
    (
        %Direct path
        connection(S, D, C),
        append([D], Visiteds, Newlist)
    )
    ;%OR
    (
        %First S to X,
        %Then  X to D.
        %In this process, append S to Visited Cities

        connection(S, X, Ctemp),
        append([S], Visiteds, Newlist),
        \+consists(X, Visiteds),
        route_finder(X, D, Ctemp2, Newlist),

        %Avoid loops
        \+(S = D),

        %Add temporary costs to find total cost
        C is Ctemp + Ctemp2

        
    ).

consists(E, [H|T]) :-
    E = H;
    consists(E, T).