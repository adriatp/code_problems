B. Truck Traffic
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
As he often does, Lazy Bob decides that today of all days is one of the best days to take a chair to the side of the freeway and look at trucks. At one static point in time, he notices that every vehicle he can at least partially see is a truck (due to his poor depth perception, Bob merges lanes in his head into one big lane)!

Bob's view can be represented by a string s
 of length N
 (1≤N≤100
) units, where the character 'T' represents one unit of truck, and the character '.' represents one unit of empty road.

Bob also knows that the mayor is planning to expand the freeway by adding one more lane, and he has Q
 (1≤Q≤100
) questions: if he added a truck of length li
 (1≤li≤N
) units to this new lane, what is the maximum number of units of truck that he could see?

Lane 1: TT...TT.TTTT....

Lane 2: .T.T....TTT.....

Lane 3: TT.T.T.T.T.T..T.

Bob's Chair

Bob's view: TT.T.TTTTTTT..T.

1 5 2 3 8 4 7

Because Lazy Bob does not want to answer these questions himself, he asks you to do it for him. Please help Lazy Bob find the answer to each question.

Input
Line 1: Two space-separated integers, N
 and Q
 (1≤N,Q≤100
).

Line 2: The string s
 of length N
, representing Bob's view of the freeway

Line 3…Q
-2: One integer, li
 (1≤li≤N
)

Output
Line 1…Q
: One integer, the maximum number of units of truck Bob could see if he added a truck of length li
 to the new freeway lane

Example
inputCopy
8 3
TT..T.T.
1
3
8
outputCopy
5
6
8
Note
In the first case, Bob can put the truck in the third position in the new lane, resulting in TTT.T.T., so 5
 units of truck visibility In the second case, Bob can the put the truck in the 3
rd, 4
th, and 5
th positions, resulting in TTTTT.T., so 6
 units of truck visibility In the third case, Bob can put the truck in all 8
 positions, resulting in TTTTTTTT, so 8
 units of truck visibility. It can be shown that no better answer can be obtained for any of the three cases.