:- dynamic(room/4).
:- dynamic(occupancy/3).
:- dynamic(student/3).
:- dynamic(course/4).
:- dynamic(instructor/3).
:- style_check(-singleton).

room(z23, 100, [smart_board, projector], handicapped).
room(z10, 80, [projector], not_handicapped).
room(z06, 60, [], not_handicapped).
room(z11, 40, [smart_board], handicapped).

occupancy(z23, 241, 8).
occupancy(z23, 241, 9).
occupancy(z23, 102, 11).
occupancy(z23, 102, 12).
occupancy(z23, 341, 2).

occupancy(z10, 341, 10).
occupancy(z10, 233, 10).
occupancy(z10, 341, 11).
occupancy(z10, 233, 11).

occupancy(z06, 233, 12).
occupancy(z06, 233, 1).

occupancy(z11, 241, 9).
occupancy(z11, 241, 10).
occupancy(z11, 102, 9).
occupancy(z11, 102, 10).
occupancy(z11, 101, 11).
occupancy(z11, 101, 12).

%student(ID, ATTENDED COURSES LIST, HANDICAPPED)
student(s1, [102, 233], handicapped).
student(s2, [341], not_handicapped).
student(s3, [101], not_handicapped).
student(s4, [233, 241], handicapped).
student(s5, [102], not_handicapped).

%course(ID, INSTRUCTOR, CAPACITY, NEEDS).
course(101, mg, 30, [smart_board]).
course(102, gk, 40, [projector, smart_board]).
course(241, ysa, 50, [projector]).
course(233, ez, 60, []).
course(341, yg, 80, [projector]).

%instructor(ID, COURSES, PREFERENCES)
instructor(ysa, [241], [projector]).
instructor(yg, [341], [projector, smart_board]).
instructor(ez, [233], [projector, smart_board]).
instructor(gk, [102], [projector]).
instructor(mg, [101], [projector]).

get_occupancy(X) :-
    occupancy(X, Y, Z),
    format('There is ~w course in room ~w at ~w o\'clock', [Y, X, Z]).

add_room(ROOM, CAPACITY, EQUIPMENTS, ACCESS) :-
    \+room(ROOM, _, _, _),
    assertz(room(ROOM, CAPACITY, EQUIPMENTS, ACCESS)).

add_occupancy(ROOM, COURSE, TIME) :-
    \+occupancy(ROOM, COURSE, TIME),
    assertz(occupancy(ROOM, COURSE, TIME)).

add_course(ID, INSTRUCTOR, CAPACITY, NEEDS) :-
    \+course(ID, _, _, _),
    assertz(course(ID, INSTRUCTOR, CAPACITY, NEEDS)).

add_student(ID, COURSES, H) :-
    \+student(ID, _, _),
    assertz(student(ID, COURSES, H)).

add_instructor(ID, COURSES, PREFERENCES) :-
    \+instructor(ID, _, _),
    assertz(instructor(ID, COURSES, PREFERENCES)).

check_scheduling_conflict(Course1, Course2) :-
    occupancy(ROOM1, Course1, TIME1),
    occupancy(ROOM2, Course2, TIME2),
    \+(Course1 = Course2), ROOM1 = ROOM2, TIME1 = TIME2,
    format('There is conflict in ~w at ~w for courses ~w and ~w ~n', [ROOM1, TIME1, Course1, Course2]), false.

check_room(COURSE, ROOM) :-

    course(COURSE, _, CAP_NEED, NEEDS),
    room(ROOM, CAPACITY, EQUIPMENTS, _),

    ((\+check_handicapped_student(COURSE) ; \+room(ROOM, _, _, not_handicapped)),
    CAPACITY >= CAP_NEED, is_subset(NEEDS, EQUIPMENTS)).

check_handicapped_student(COURSE) :-
    student(S, Courses, handicapped),
    member(COURSE, Courses).


check_enrol(ID, CLASS) :-
    student(ID, CLASSES, _),
    list_classes(CLASS, CLASSES).

check_enrol_all(ID) :-
    student(ID, CLASSES, _),
    list_classes(CLASS, CLASSES),
    nl, write('Other courses can be taken'), nl.

is_subset([], _).
is_subset([H|T], List) :-
    member(H, List), delete(List, H, Rest),
    is_subset(T, Rest).

list_classes(COURSE, []).
list_classes(COURSE, [H|T]) :-
    check_scheduling_conflict(COURSE, H);
    list_classes(COURSE, T).





