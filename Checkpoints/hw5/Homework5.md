# Homework 5 - 11/30
Oliver Larsson 
CSCI 3010 - Felix Muzny 

1) The initial plan for Homework 5 in the project proposal:  
- Create forecasting class: This class will use the historical financial asset data within the current portfolio to create a new object of a possible future state of that portfolio. It likely won’t involve very complex financial modeling since that involves variables that aren’t present in the data, but it will be moderate and reasonable nonetheless. 
- Create a pretty UI: The final piece to this is turning the text UI into a better interface with Ultralight. This will likely be an extensive portion of this phase since it’s a tool I am not familiar with. 
- What knowledge will I need to know? Everything from this semester. How to implement a forecasting algorithm into the data from the database and present it as an object. How to use Ultralight to create a nice UI with BI data visualizations. 
- What will I need to learn? New to Ultralight so more research will have to go into that along with the initial studying in the first phase. Also will need research into how to best implement a forecasting strategy. 
- Additionally: I'll need to sort out the issue of filling the portfolio table with data from the market table based on the investor's wealth. I was more focused on the functionality of the Market and Portfolio methods in Homework 4, so it should be a quick fix when I dedicate more time to it.

2) What was completed or modified from each task in initial plan:
- Create forecasting class: This class will use the historical financial asset data within the current portfolio to create a new object of a possible future state of that portfolio. It likely won’t involve very complex financial modeling since that involves variables that aren’t present in the data, but it will be moderate and reasonable nonetheless. 
    - Done. I'm super happy with how the forecasting turned out. The "won't involve very complex financial modeling" idea was scrapped. I decided to use formulas from ECON 3818 that I'm taking right now to find the Confidence Intervals that the forecasting returns. This involved significantly more work than I had anticipated because of differences in SQLite's ability and the ability of larger SQL tools (the "Lite" really showed here). The differences included lack of standard SQL aggregate functions like SQRT, STDEV, and VAR, along with some structural issues that didn't allow me to nest my queries and made it much harder to read. It took literally hours to create all the forecasting queries, which might be a reflection of my ability along with the road blocks, so completing them was the most rewarding part of the project so far. Unfortunately I decided to really take a break over break and didn't work much, which showed on the next step. 
- Create a pretty UI: The final piece to this is turning the text UI into a better interface with Ultralight. This will likely be an extensive portion of this phase since it’s a tool I am not familiar with. 
    - I spoke with you briefly in class about this that I was questioning Ultralight because of poor documentation of their example GUI. I decided to still create the HTML/CSS skeleton to reflect the functionality of the app and will work hard the next two weeks to make sure that the application links with the skeleton through Ultralight. We spoke about the possibility of the GUI step bleeding into Homework 6 at our check-in after Homework 4 and that is the case. This does mean that this step wasn't fully completed, but it will give me more to do in the final weeks other than testing. Additionally the feedback I recieved from those who tested my mock-up will add to the creation of the GUI. 
- Mockup reflection / User testing: 
    - I walked through the mockup with my two roommates that aren't CS related at all, so it was nice to get some good feedback from outsiders. I also ran through it with my twin who does private wealth management at Morgan Stanley and got some good tips on how his actual job compares to this program. Summed up in a few points: 
        - Point 1
        - Point 2
        - Point 3
        - Point 4 
- What knowledge will I need to know? Everything from this semester. How to implement a forecasting algorithm into the data from the database and present it as an object. How to use Ultralight to create a nice UI with BI data visualizations. 
    - The forecasting algorithm was definitely a learning process but it worked out better than I had hoped. I also understand the Factory design pattern much better after implementing it and am 100% sure it was the right choice to change the Forecast class to Factory from Iterator. Ultralight… is… unique. The HTML/CSS skeleton provides a necessary backbone for the time being so the final step will be connecting it to the program. 
- What will I need to learn? New to Ultralight so more research will have to go into that along with the initial studying in the first phase. Also will need research into how to best implement a forecasting strategy. 
    - Ultralight is a learning process for sure. I'm excited to create the final product though.
- Additionally: I'll need to sort out the issue of filling the portfolio table with data from the market table based on the investor's wealth. I was more focused on the functionality of the Market and Portfolio methods in Homework 4, so it should be a quick fix when I dedicate more time to it.
    - Wasn't priority in this Homework since it involves fixing one query. Still need to do it. 

3) What was planned for in the Homework 6 / final submission and any changes: 
- TEST TEST TEST! 
    - Still need to do lots of testing! But as I mentioned and as you predicted, the GUI was more to handle than I anticipated, and with the difficulty of finishing the Forecasting class, GUI work will have to be done in the weeks leading up to the final submission. Fortunately, most the testing of the code in the Text UI has been done so the testing will be less rigorous than it would be in one big go.
- Clean things up. Stuff like rounding decimals to reasonable places, maybe adding more information on financial terms that aren't straightforward. Edge cases on the Forecasting user inputs might be helpful. 

4) These screenshots show the current functionality of the program. Included with each Text UI screenshot is a screenshot of the same functionality on the GUI mock-up. I included the same screenshots from Homework 3 and 4 for what was already done.  

*****************
EVERYTHING BELOW IS FROM HOMEWORK 3
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
EVERYTHING ABOVE IS FROM HOMEWORK 3
*****************
EVERYTHING BELOW IS FOR HOMEWORK 4 
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
EVERYTHING ABOVE IS FROM HOMEWORK 4
*****************
EVERYTHING BELOW IS FOR HOMEWORK 5
*****************

- Picking up roughly where we left off. Here's the action of moving on to the forecast after the portfolio is built. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/52.png)

- There are three methods of forecasting that can be done. Since they're the least clear of all the financial ideas in this program, the user can select to view information on each individually. They can then move on to choosing a forecasting method. 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw5/53.png)

- When the user selects a method to forecast with, the Factory design pattern will work its magic and create an instance of that method. Below are the three confidence intervals (99%, 95%, 90%) pertaining to the first method by market. Confidence intervals are created using the sample mean (sample here is all applicable rows queried), a Z-statistic (standardized stat given confidence level and sample size) and the standard deviation of the data set. The higher a confidence level the larger the bracket of possible values will be. This is reflected in all the examples below. 

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
Thanks for following along! 
*****************