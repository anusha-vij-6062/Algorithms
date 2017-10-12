# Algorithms
Practice problems of algorithms
### Question 1: Find the longest Substring in a given string without repeating characters
File: longestSubstring.cpp: <br>

```
Given: abcabcd
MaxLength: 4 (abcd)

Given: pwwwekd!87
MaxLength:7

Given: oohom
MaxLength:3
```
### Question 2: 
A computer robot which moves in infinite plane, starting at 0,0 facing North.It understands 3 types of commands:<br>
1. G : Straight <br> 
2. L : Turn left <br>
3. R : Turn Right <br>
The robot performs the instruction for an infinte number of times. The program finds out in the given command list exists a circular path whose radius is a real positive number.<br>
A "YES" indicated there exsits a circle while "NO" indicates otherwise. <br>
File: encircular.cpp <br>
## Inputs
```
3     (Number of test cases)
G     (1st test case)
LGGG  (2nd test case)
GLGR  (3rd test case)
```

```
---------------------------------------------------
Command:G
Starting point is:(0,0) North
Current Direction: N
Updated step: (0,1)
---------------------------------------------------
Command:LGGG
Starting point is:(0,0) North
New Direction: W
Current Direction: W
Updated step: (-1,0)
Current Direction: W
Updated step: (-2,0)
Current Direction: W
Updated step: (-3,0)
---------------------------------------------------
Command:GLGR
Starting point is:(0,0) North
Current Direction: N
Updated step: (0,1)
New Direction: W
Current Direction: W
Updated step: (-1,1)
New Direction: N
--------------------Final Answer--------------------------
G :NO
LGGG :YES
GLGR :NO


```
