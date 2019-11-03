# Project 2: Passed

## Part 1
Good!

A few things:

There is an error in the loop in your insert method which results in it not working correctly. You write:
~~~~c++
for (int i=size-1;i<index;i--){
    *(data+i+1)=*(data+i);
}
~~~~
But `i` starts at `size-1` and should be reduced while it is larger than or equal to the index, so this should rather be:
~~~~c++
for (int i=size-1;i>=index;i--){
    *(data+i+1)=*(data+i);
}
~~~~
Also in insert-method, using the current size as the index should be equivalent to using the append-method, but this is not implemented.


Some of your code also feels clunky and unintuitive, like the bit shifts for finding the power of 2, and the notation you use for setting and getting the values in the data array. I.e. instead of
~~~~c++
*(data+i)
~~~~
to get the value of the data array at position i, I would recommend simply using
~~~~c++
data[i]
~~~~
which does exactly the same.\
Your methods are not incorrect, but they seem a little overcomplicated for what we are trying to achieve.

In your `pop()` method you throw an error when `size = 1`, however you should still be able to pop the element when there is only one element left in the list.

## Part 2
The insert method does not work correctly for `index = 0`

Your remove method does not work correctly. It removes for one index above the given value, so if you use `remove(2)` it actually removes the value from index 3. Your own example does not show this, as you attempt to remove index 2 from a list where both index 2 and index 3 contains the value 3. When making tests it's good practice to create cases where you cannot get the correct answer with the wrong method. Changing the loop to `while (i<(index-1))` fixes this, but you must then treat the edge case of `index = 0` separately.

The pop method gets the value from the correct index, but does not work for `index = 0`.

As a note, some places you use `(*node).value` and some places you use `node->value`. These are equivalent, but it's good to stick with one notation. `node->value` is normally used most from my experience.

## Part 3
Good!

## Part 4
Good!

If you have any questions about the exercises or the feedback you are welcome to send me an email: j.o.f.akerholm@fys.uio.no
