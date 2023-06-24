# CLI Progress Bar

Easy Progress Bar for cli applications in c++

## Instructions

### Install

Download files using curl

```bash
curl -o progressbar.cpp https://gitlab.com/my-mini-utilities/cli-progress-bar-cpp/-/raw/main/progressBar.cpp

curl -o progressbar.h https://gitlab.com/my-mini-utilities/cli-progress-bar-cpp/-/raw/main/progressBar.h
```

Compile Accordingly

``` bash
g++ main.cpp progressbar.cpp
```

### Run Example

```bash
g++ example.cpp progressBar.cpp && ./a.out
```

## Usage

Create Instance with current progress value and max progress value

```cpp
MyProgressBar::progressBar Progress(0, 1567);
```

Increment when you move forward

```cpp
Progress.increment();     // increment progress by 1
Progress.increment(213);  // increment progress by 213
```

Display Current Progress

```cpp
Progress.simple();  // simple styled progress update
Progress.fancy();   // fancy progress bar
```

Display Finish Message

```cpp
Progress.finish();
```

See source code for more

## To-Do

### General

* [x] Move to new Group "My Mini Utilities"
* [x] Class based implementation
* [x] Turn this into a easily usable library file
* [x] Cleanup
* [x] Add library to a namespace ??
* [x] Consider the width of the screen before making progress bar
* [x] Type Cleanup. Using variable width types.
* [x] Usage: How would someone use this effectively ? curl the files ? wget ?
* [x] Better Readme

### Future

* [ ] Can I and should I unit test this ??
* [ ] Build Tests ??
