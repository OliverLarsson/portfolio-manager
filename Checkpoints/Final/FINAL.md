# Final Submission -- 12/12 
## Oliver Larsson 
## CSCI 3010 - Muzny 

## 1) The initial plan for Homework 5 in the project proposal:  
- TEST TEST TEST! 
- Clean things up. Stuff like rounding decimals to reasonable places, maybe adding more information on financial terms that aren't straightforward. Edge cases on the Forecasting user inputs might be helpful. 

## 2) What was completed or modified from each task in initial plan:
- TEST TEST TEST! 
    - Yep! I wrote all the Catch2 tests that I could do as far as the application permitted. A bright side of writing both a console and a GUI app, separately, is that I'm almost constantly testing against myself since I'm checking that the functionality lines up. 
    - QT testing: I didn't feel like it was entirely necessary. I know it's important to test everything regardless of how you feel, but due to time constraints and this program being much heavier behind the scenes than it is on the UI, the Catch2 testing on the functions was much more valuable. 
- Clean things up. Stuff like rounding decimals to reasonable places, maybe adding more information on financial terms that aren't straightforward. Edge cases on the Forecasting user inputs might be helpful. 
    - I definitely underestimated what I would be doing in this sprint. However, I still "cleaned things up" on the SQL queries, edge cases for all classes, and financial terms. 
- I scrapped the Ultralight plan entirely. My own stupidity thought that Ultralight was an HTML GUI for C++ applications, but after hour thirty of trying to find a tutorial to point me in a direction, I found that it's actually made for those that want to render HTML apps in C++ code. Obviously not close to what I needed. I put the GUI step off quite a bit, which turned out to be really stressful, but I ended up landing on QT. I think I mistook QT for what it really is because I thought it was only meant for the things that we were doing in class. After doing some googling I found that it has a really great design process and a SQLite wrapper that's superb. The transfer of my console app to QT took about a day, whereas the amount of time I spent on theconsole that felt like 200 hours. That's also because designing the methods from scratch to accurately reflect a market/portfolio/forecast took a bit of time, and all I had to do with QT was copy and paste those methods. Nonetheless, it made me wish I had started with QT, as it would've left me more time to create a bigger program. 
- I left some comments in the QT header files for Portfolio and Forecast about this: I tried to implement both the Singleton and Factory design patterns in their respective classes and was unsuccessful in both. I did literally hours of reading through QT files and looking at forums and couldn't find any solutions that matched my style program. I definitely should've consulted you about this, but since I put the GUI off a bit, I was more honed in on finishing before presentation time. But anyway, that's a matter of poor time management that I should've accounted for. I assumed that the implementations from the console app would directly translate to the QT GUI and I was wrong. Here are the comment blocks from the header files for convenience: 

### Singleton Portfolio class: 

- I tried to implement the Singleton design pattern but I couldn't make it work. Instead of keeping the code that I tried I'll try to explain what happened.
- The implementation that I used in the console app (portfolio-manager/Code/) wasn't suited for this because I don't generally use to portfolio object in this QT version. Instead I use the basic widgets and slots to draw and show information to the user. Additionally, with how the application is set up in this UI, the user cannot create multiple portfolio objects. This isn't an effect of a design pattern, but rather just the structure of the GUI.
-  Furthermore, the explicit constructor declaration ensures that no other QWidget objects are implicitly converted to a Portfolio object. From what I understand in reading on QT is that this replicates the Singleton design of not allowing objects to be reassigned.

### Factory Forecast class: 

- Same as the Portfolio Singleton implementation, I ran into problems with implementing the Factory design pattern.
- I tried creating the three forecasting method classes inherited from the Forecast. The issue I ran into is the Q_OBJECT macro in the beginning of the Forecast class isn't copyable since it's there to tell the compiler that there are GUI element in the class. What I think I understand from reading QT docs is that this cannot be created multiple times since it's used in the compiling process.
- Another issue I ran into was with the QWidget *parent. As I explained in the Portfolio class header file, the explicit declaration of the constructor is designed (to the best of my understanding) not allow reassigning to the class object. This design goes directly against the Factory design pattern since it would require that the whole GUI create a new class object inherited from the parent class. - I thought about implementing some pseudo-Factory method where it runs certain functions based on the forecast that should be run, but that just involves re-writing methods with maybe a few variables that are different.

## 3) Reflection: 
- Learned a ton and had *so* much fun making this. It's an idea I've had for a long time and I can't wait to continue to build on it!

- The Good: 
    - Learned a lot 
    - Adapted a lot too 
    - I like to think I improved my coding research strategy since SQLite and QT involved plenty of research to get right  
    - I ran into quite a few technical difficulties, some due to my ignorance, that made me problem solve more than I have in any CS course. This made the project feel a lot more full and worth the time. 

- The Bad: 
    - I was riding a strong honeymoon phase with the console program and everything was going perfectly. This kind of threw me into a spiral of wanting to build more and more on the Text UI despite it becoming irrelevant in the end. 
    - Time management towards the end. I definitely fell off track in the 5th HW submission and that created more chaos in this step. 

Overall I had an awesome time making this and I'm really thankful you let me take a chance with this!

## 4) These screenshots show the current functionality of the program. Included with each Text UI screenshot is a screenshot of the same functionality on the GUI mock-up. I included the same screenshots from Homework 3, 4, and 5 for what was already done.  

*****************
### EVERYTHING BELOW IS FROM HOMEWORK 3
*****************

- Build (this is actually new to reflect the -w tags) 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/51.png)

- Welcome

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t2.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m1.png)

- Investor Attributes Input 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t3.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m2.png)

- Investor's Risk 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t4.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m3.png)

- Investor Attribute Display

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t5.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m4.png)

- Investor Risk Profile & Portfolio Distribution

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t6.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m8.png)

- Mock-up only: Changed the Technology vs Industrial input to after the Investor's Risk input

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m5.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m6.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/m7.png)

- Full Text UI build and display 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t7.png)

- Full GUI mock-up flowchart 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/portfolio-manager.png)

- Testing

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t8.png)

- Sqlite database and tables created 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/d3.png)

- Ultralight build and run 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/u1.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/u2.png)

*****************
### EVERYTHING ABOVE IS FROM HOMEWORK 3
*****************
### EVERYTHING BELOW IS FROM HOMEWORK 4 
*****************

- Some warnings come up on 'make all.' These do not affect the functionality or performance of the application at all, and I can't figure out how to get them to go away. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/45.png)

- The beginning of the application is mostly the same, but with some refactoring and edge case handlers to make sure user input is accurate. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/44.png)

- For this whole demo the sector chosen is Technology. The functionality is the same for Industrial, but the Market is queried differently and the Porfolio is loaded differently. The first picture belows shows the standard view of the Porfolio contents followed by the view based on the price of the ticker in the Market table. All other screenshots below are the other options. Each option queries the Portfolio table differently. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/43.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/42.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/39.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/38.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/37.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/36.png)
![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/35.png)


- This final screenshot shows the action of moving on to the Forecast class, which will be created and implemented in Homework 5. The Portfolio table is deleted at the end of the application. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw4/41.png)

*****************
### EVERYTHING ABOVE IS FROM HOMEWORK 4
*****************
### EVERYTHING BELOW IS FROM HOMEWORK 5
*****************

- Picking up roughly where we left off. Here's the action of moving on to the forecast after the portfolio is built. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/52.png)

- There are three methods of forecasting that can be done. Since they're the least clear of all the financial ideas in this program, the user can select to view information on each individually. They can then move on to choosing a forecasting method. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/53.png)

- When the user selects a method to forecast with, the Factory design pattern will work its magic and create an instance of that method. Below are the three confidence intervals (99%, 95%, 90%) pertaining to the first method by market. Confidence intervals in this context are the interval in which we would expect the true forecasted growth to fall in xx% of the time. They are created using the sample mean (sample here is all applicable rows queried), a Z-statistic (standardized stat given confidence level and sample size), the standard deviation (in my SQL query I computed sqrt(variance) which equals stdev) of the data set, and the sample size. The higher a confidence level the larger the bracket of possible values will be. This is reflected in all the examples below. 

- Forecast by market: Considers all data from the industry that the user selected (tech or industrial)

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/54.png)

- Forecast by solo: Solo meaning the user's portfolio data only. This forecast is the most relevant to the user since it's all data that applies to their preferences. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/55.png)

- Forecast by economy: Economy or econometric forecasting takes the entire economy into account. In this program that means using data from all industries aka the entire 'market' table. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/56.png)

- A few things to note if you run through the application a few times: 
    - The Solo forecast will return a larger confidence interval than the market and economy. This is because the sample size is smaller and the possibility of 19 stocks averaging 2% growth is much higher than the possibility of 220 stocks averaging 2% growth. 
    - Statistically the highest returning portfolios will be those that are young and reckless. Consequently these portfolios can tank harder than others as well. If you enter your information as young and reckless (e.g. 21 years old, risk tolerance of 10 and risk requirement of 100) vs old and safe (e.g. 75 years old, risk tolerance of 1 and risk requirement of 2) the young will have a larger confidence interval since their portfolio is more likely to move radically. 
    - These notes are reflected below for both the 99% and 90% intervals with both age and risk examples. They both have $500,000 and are investing in technology. The examples show their solo forecasts since it takes their portfolio into account. 

- 99% and 90% CI: 21 y/o.

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/57.png)

- 99% and 90% CI: 75 y/o. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/58.png)

- Finally, you can close out the program any time by selecting 4. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/59.png)

- The initial mockup of the forecasting. I had planned to have only one forecasting method, but this changed in the process following mockup. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/60.png)

*****************
### EVERYTHING ABOVE IS FROM HOMEWORK 5
*****************
### EVERYTHING BELOW IS FOR FINAL SUBMISSION 
*****************

- GUI Home Screen 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/Final/f1.png)

- GUI Investor Screen 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/Final/f2.png)

- GUI Market Screen 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/Final/f3.png)

- GUI Portfolio Screen 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/Final/f4.png)

- GUI Forecast Screen 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/Final/f5.png)

*****************
# THANK YOU! 
*****************