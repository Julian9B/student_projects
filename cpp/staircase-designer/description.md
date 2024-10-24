# Staircase designer

## 1. About

This exercise is about creating app that can design a stairs based on user input data. We start from a console app and modify it to be a window app later.

### 1.1. Use case

| USE CASE       | Staircase designer app |
| -------------- | ---------------------- |
| ACTOR          | User of system |
| GOAL           | User wants to get data about stairs steps' height and depth, based on height and length of entire staircase |
| BASIC FLOW     | 1. User opens the app. <br> 2. User enters height and length of the staircase [m] into 'Staircase height' and 'Staircase length' fields. <br> 3. App defines that it is possible to create a staircase with user's data. <br> 4. App calculates number, height and depth of the steps [cm] and returns them to the user. |
| EXCEPTION FLOW | 1. User opens the app. <br> 2. User enters height and length of the staircase [m] into 'Staircase height' and 'Staircase length' fields. <br> 3. App defines that it is impossible to create a staircase with user's data. <br> 4. App returns message 'Invalid input data' to the user. |

Tab.1.

### 1.2. The problem

To calculate height and depth of the steps, we first need to calculate their number. We do that by dividing staircase's height by height of ergonomic step's height and rounds the result. Then, the we divide the height of the staircase by number of steps to get exact height of single step. Finally, we divide the length of staircase by number of steps minus one (because the last step is already the next floor so we don't need to count it) to get the depth of single step.
 
If calculated height and depth are very unreal (i.e. 1cm/10cm), the program should return invalid data message. To do that, we need to check if their propotions of height to depth fits in ergonomic dimensions of staircase's steps.

### 1.3. Plan for code

We need two functions - one for calculating dimensions, and the other one their validation. We're going to have them in 'functions.cpp' file. In the 'main.cpp' file we're going to get user's input, call the functions and returns data or invalid message, based on second function's result.

## Authors
[Julian9B](https://github.com/Julian9B)
