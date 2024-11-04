# Staircase designer

## 1. About

This exercise is about creating app that can design a stairs based on user input data. We start from a console app and modify it to be a window app later.

### 1.1. Use case

| USE CASE       | Staircase designer app |
| -------------- | ---------------------- |
| ACTOR          | User of system |
| GOAL           | User wants to get data about stairs steps' height and depth, based on height and length of entire staircase |
| BASIC FLOW     | 1. User opens the app. <br> 2. User enters height and length of the staircase [m] into 'Staircase height' and 'Staircase length' fields. <br> 3. App defines that it is possible to create a staircase with user's data. <br> 4. App calculates number, height and depth of the steps [cm] and returns them to the user. |
| EXCEPTION FLOW | 1. User opens the app. <br> 2. User enters height and length of the staircase [m] into 'Staircase height' and 'Staircase length' fields. <br> 3. App defines that it is impossible to create a staircase with user's data. <br> 4. App returns an error message to the user. |

Tab.1.

### 1.2. The problem

If given height and length are very unreal (i.e. 10m/1m), the program should return invalid data message. To do that, we need to check if their height to length ratio fits in ergonomic dimensions of staircase. 
 
To calculate height and depth of the steps, we first need to calculate their number. We do that by dividing staircase's height by height of ergonomic step's height and round the result. Then, the we divide the height of the staircase by number of steps to get exact height of single step. Finally, we divide the length of staircase by number of steps minus one (because the last step is already the next floor so we don't need to count it) to get the depth of single step.

### 1.3. Plan for code

We need two functions - one for validating user data, and the other one for calculating dimensions. We're going to have them in 'functions.cpp' file. In the 'main.cpp' file we're going to get user's input, call the functions and calculate data or return invalid message, based on first function's result.

## 2. Code

### 2.1. Functions file

We have two functions in file 'functions.cpp' - one function validates input data, and the other one calculates output data. 

### 2.2. Main program
 
In the file 'main.cpp' we have 'main' function that gets overall height and length of the staircase from user, then decides whether to calculate output or return an error message, based on result of validating function. 
 
Other files are useful to compile the program.

## 3. Result

## 4. Conclusion

## Authors
[Julian9B](https://github.com/Julian9B)
