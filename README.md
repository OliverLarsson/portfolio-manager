[![Build Status](https://travis-ci.com/OliverLarsson/portfolio-manager.svg?branch=master)](https://travis-ci.com/OliverLarsson/portfolio-manager)
# portfolio-manager
CSCI 3010 - Individual Project 

Hi! Welcome to my individual project for CSCI 3010 at CU Boulder. This is a automated Portfolio Manager game that takes your real attributes and matches it with real financial assets. It will also forecast the expected growth of your portfolio based on historical trends. 

DISCLAIMER: I do not have any rights, licenses, or exceptional knowledge that warrants any of this to be legitimate financial advise. Do NOT use it as a reliable source for financial planning. :) 

That being said... have fun with it! To download the game, follow these steps on your command line after installing git: (https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)

    1. git clone https://github.com/OliverLarsson/portfolio-manager 
    2. cd portfolio-manager

Once you complete the downloading steps, it's time to play. To run the game, make sure you are in the portfolio-manager directory, then follow these steps on the command line: 

    1. make all
    2. ./portfolio

If you want to test the game, follow these steps on the command line: 

    1. make all 
    2. ./test

Have fun! 

********************

Additional information on functionality, features, dependencies, etc. 

Lucy.jpg: 
- This is Lucy the coding support dog. She's at the foundation of all the work on his project. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Lucy.jpg)

System requirements: 
- This entire application has been built and maintained on MacOS. It has not been tested on Linux or Windows. 

Framer X mockup: 
- Framer X is a software that allows you to draw, style, and export responsive mockups. It comes with loads of features both locally and in the Framer X store, giving you plenty of options in designing the product. 
- You'll need to download the Framer X software to view the mockup.framerx file. It comes with a 14-day free trial with no card needed, so you don't have to worry about accidentally forgetting to cancel the subscription and getting charged.
- I'll also be uploading a PDF of the mockup into the Checkpoints/Checkpoint_1 folder on GitHub so it's viewable without the software. 
- https://framer.com/

Data: 
- Data comes from a CSV file containing information from stocks in both the Dow Jones Industrial Average (DJIA, "Dow") and the Nasdaq 100 ("Nasdaq"). For clarity's sake, I've generalized the Dow to be the "Industrial" market and the Nasdaq to be the "Technology" market. 
- https://www.nasdaq.com/article/difference-between-dow-nasdaq-and-sp-500-major-facts-opportunities-cm1001888

Back-end: 
- I went with a SQLite database. The two tables, Market and Portfolio, will be loaded with the CSV file mentioned above. It's linked to the application by the sqlite3 header file. sqlite3 is standard on MacOS, so there is no installation process if you are running on a Mac. 

Front-End: 
- The front-end is currently a Text UI. Once the application is near completion it will be changed to an HTML UI with the Ultralight HTML UI Engine. Ultralight is implemented within the C++ application. 
- All documentation on Ultralight and how to set up is here: https://github.com/ultralight-ux/ultralight/blob/1.9.1/README.md#getting-started
- It requires: 
    - Cmake 2.8.12 or later
    - OpenGL 3.2 or later 
    - Compiler with C++11 or later 
    - XCode 8.0
- An example of Ultralight is under the Ultralight directory in the portfolio-manager repo. To run it, navigate: 
    - /Ultralight/build/samples/Browser/Browser (open second browser)
- https://ultralig.ht/

Testing: 
- Testing in the current state is done with Catch2. This is implemented in the C++ application using a Catch2 header file. 
- https://github.com/catchorg/Catch2

