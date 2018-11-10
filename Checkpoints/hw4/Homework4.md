# Homework 4 - 11/9
Oliver Larsson 
CSCI 3010 - Felix Muzny 

1) The initial plan for Homework 4 in the project proposal: 
-	Draw data into project: This phase will need to access data from the first phase and insert it into a database. This data will be used by the three classes yet to be implemented: financial assets, portfolio, and forecast. 
-	Create financial asset class: This class will be the first to be created following the investor class in the first phase. It will involve pulling data from the database and sorting it by sector, date, and price. It will then have to be accessible by the investor class, the portfolio class, and the forecast class. 
-	Create portfolio class: This class will use the prior two – investor and financial assets – and create a portfolio based on the characteristics of the two. It will then create a portfolio object consisting of financial assets that cater to the investor’s profile. 
-	Create algorithms for risk assessment and forecasting: Both these algorithms will be reliant on the decided data in this phase, so it’s a good point to create algorithms for future use.  (taken out from Homework 3) 
-	Create initial text UI: Unless there is more time left in this phase than anticipated, a text UI in the terminal will be the best way to test the current state. This way I can work through the functionality without worrying about a pretty UI. Furthermore, the state at this point should be able to run without the final class – forecasting. 
-	What knowledge will I need to know? Everything we’ve gone over in classes with class, object, and the like. How to draw data into a database and access it, using SOCI. 
-	What will I need to learn? I’m new to the SOCI library so along with the initial studying done in the first phase, I’ll need to be sure to implement it correctly here.

2) What was completed or modified from each task in initial plan: 
- Draw data into project: This phase will need to access data from the first phase and insert it into a database. This data will be used by the three classes yet to be implemented: financial assets, portfolio, and forecast. 
    - Completed. I went into more depth as to what data I would be using in Homework 3. Briefly here for clarity, I decided to fill the market table with data from barchart.com. This consists of their data on the DOW composite stocks, all Nasdaq 100 stocks, and the top 61 performing ETFs.
- Create financial asset class: This class will be the first to be created following the investor class in the first phase. It will involve pulling data from the database and sorting it by sector, date, and price. It will then have to be accessible by the investor class, the portfolio class, and the forecast class. 
    - Completed as intended. Although the class is now called 'Market'. 
- Create portfolio class: This class will use the prior two – investor and financial assets – and create a portfolio based on the characteristics of the two. It will then create a portfolio object consisting of financial assets that cater to the investor’s profile. 
    - Completed nearly as intended. The functionality of all methods work as I planned aside from loading the portfolio. I have been having trouble with inserting assets from the market into the portfolio according to the wealth of the investor. While this means that data currently in the portfolio isn't as accurate as it could be, all functionality of the methods that deal with the portfolio work as intended. So it's just a matter of writing a couple different SQL scripts. 
- Create algorithms for risk assessment and forecasting: Both these algorithms will be reliant on the decided data in this phase, so it’s a good point to create algorithms for future use.  (taken out from Homework 3) 
    - Completed. I explained this a little in Homework 3 that I needed risk assessments for the Investor class, so I ended up doing this step in Homework 3. However, I still needed to do the risk of each financial asset in the Market and Portfolio classes in this homework. Forecast will be implemented in Homework 5. 
- Create initial text UI: Unless there is more time left in this phase than anticipated, a text UI in the terminal will be the best way to test the current state. This way I can work through the functionality without worrying about a pretty UI. Furthermore, the state at this point should be able to run without the final class – forecasting. 
    - Completed. This stayed the same. After Homework 3 only the Investor class was implemented, so I built the Text UI for the Portfolio and Market class. 
- What knowledge will I need to know? Everything we’ve gone over in classes with class, object, and the like. How to draw data into a database and access it, using SOCI. 
    - Using SQLite instead of SOCI. 
- What will I need to learn? I’m new to the SOCI library so along with the initial studying done in the first phase, I’ll need to be sure to implement it correctly here. 
    - Using SQLite instead of SOCI. 

3) What was planned for in the Homework 5 proposal and any changes: 
- Create forecasting class: This class will use the historical financial asset data within the current portfolio to create a new object of a possible future state of that portfolio. It likely won’t involve very complex financial modeling since that involves variables that aren’t present in the data, but it will be moderate and reasonable nonetheless. 
    - Still the plan.
- Create a pretty UI: The final piece to this is turning the text UI into a better interface with Ultralight. This will likely be an extensive portion of this phase since it’s a tool I am not familiar with. 
    - Still the plan.
- What knowledge will I need to know? Everything from this semester. How to implement a forecasting algorithm into the data from the database and present it as an object. How to use Ultralight to create a nice UI with BI data visualizations. 
    - Still the plan.
- What will I need to learn? New to Ultralight so more research will have to go into that along with the initial studying in the first phase. Also will need research into how to best implement a forecasting strategy. 
    - Still the plan.
- Additionally: I'll need to sort out the issue of filling the portfolio table with data from the market table based on the investor's wealth. I was more focused on the functionality of the Market and Portfolio methods in Homework 4, so it should be a quick fix when I dedicate more time to it.

4) These screenshots show the current functionality of the program. Included with each Text UI screenshot is a screenshot of the same functionality on the GUI mock-up. I included the same screenshots from Homework 3 for what was already done.  

- Build 

![alt text](https://github.com/OliverLarsson/portfolio-manager/blob/master/Checkpoints/hw3/t1.png)

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
