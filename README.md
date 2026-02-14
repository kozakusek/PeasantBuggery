# LeetCode Solutions

This repository contains my solutions to selected LeetCode problems. 

## About Runtime “Hacks”

Just to be clear: we **do not** do things like this:

```cpp
auto init = atexit([]() {
    ofstream("display_runtime.txt") << "0";
});
```

Nor do we indulge in any other half-baked magic to stuff data into the `.data` section just to make your memory usage look impressive.

If you feel the urge to try this… maybe get a hobby? Or, you know, *write code that actually works*.

## Questions worth going back to

* 0004.Median-Of-Two-Sorted-Arrays  
* 0025.Reverse Nodes in k-Group  
* 0030.Substring-with-Concatenation-of-All-Words  
* 0084.Largest-Rectangle-in-Histogram  
* 0085.Maximal-Rectangle  
* 0087.Scramble-String  
