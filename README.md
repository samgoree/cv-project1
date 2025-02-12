Starter code for CSC399 Project 1

Your task is to add four “filters” to this photobooth:
* When the user presses the ‘s’ key, transform the video feed to sepia tone. Sepia is kind of like grayscale, but with white replaced by a shade of brown (code R = 101 G=138 B=162)
* When the user presses the ‘b’ key, blur the image.
* When the user presses the ‘e’ key, show only the edges in the image.
* When the user presses the ‘r’ key, apply a random effect of your choosing. I recommend a random convolutional filter, or random recoloring.

These should (mostly) work in any combination, so if the user turns on the edge filter, then the sepia filter, it should show the edges in sepia tone. Pressing the keys again should turn the corresponding filter off.
