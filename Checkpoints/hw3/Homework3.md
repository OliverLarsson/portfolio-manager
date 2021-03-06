# Homework 3 - 10/12
Oliver Larsson 
CSCI 3010 - Felix Muzny 

1) The initial plan for Homework 3 in the project proposal: 
    - Studying: Since this is the first step of the project, the work will include studying and freshening up on tools and technologies that I’m either not familiar with or haven’t used recently. This is particularly important for SOCI and Ultralight since I have not used these before. Further practice in implementation will have to be done in the use of multiple classes, seeing as I didn’t do a great job of that on Homework 1. This will be especially important to me as it will give me a self-led example of how C++ classes and object look in a full-stack (or close to) environment. 
    - Structure: To begin the project, adequate structure has to be laid out. For this step, the database, back end, front end, and UI base must be set up and ready to be built on. This means that the MySQL server should be connected to the back end through SOCI and the UI should be connected to the front end through Ultralight. 
    - Initial header files: To help visualize the product it’s important to begin with header files. This way I can piece together all methods and fields that will be involved with the Investor class, the Financial Asset class, and the Portfolio class. 
    - Mock-up program: Again, to help visualize, I think it’s important to have a mock-up of the UI and functionality. This sketch can also serve as a storyboard to demonstrate what certain methods will do at which times, and how objects from different classes will interact. This sketch will be as detailed as possible to give the best insight into how the functionality should look from a user’s standpoint. 
    - Find real and mock data: The most important part of this functionality revolves around data. Without a data set of assets to pull from, the three of the four classes – financial assets, portfolio, and forecast – are useless. For this reason, it’s especially important to secure both the primary and backup data. The primary data in this case will be a reliable API to pull from, while the backup data will be mock stocks with mock numbers that will allow the program to test its functionality. Real data needs to be decided on by Saturday, October 13, or else mock data will be used. 
    - Preliminary test cases: The earlier, the better! This portion will involve writing Catch2 tests for the base code, plus writing some anticipatory tests for what I envision will happen in the next phases. This is a good way to build from the top down, as prewritten tests can ensure that methods stay on track with their intended function.
    - Create investor class: Since this class is independent of the data from the start, it can be implemented prior to the other three classes. Finishing this class in the first phase will also allow for more room to work on the heavier classes in the later phases. To create this, all methods and fields in the header file should be implemented in investor.cpp and an object should be ready to be instantiated. 
    - What knowledge will I need to know? Along with everything we have learned so far in this class, I will need to know how SOCI and Ultralight work. I am not familiar with these two tools, so I will need to study their implementation techniques and how they are worked into C++ code. I will also need to know where the data will be coming from and how that will be drawn into the program. 
    - What will I need to learn? Referencing the question above and the first “Study” point, I’ll need to learn tools that I have not had experience in before. 

2) What was completed or modified from each task in initial plan: 
    - Studying: Most of the studying came along with linking the MySQL C++ Connector (detailed in Structure section) and Ultralight to the project. Since I had never worked with either of these tools before, it took some time to actually understand how and why they should be used. 
    - Structure: I elected to go with a Sqlite database and connection. While I initially planned on using a MySQL server with SICO to connect to the app, I took into consideration the scope of the project and what part the data would play. For this reason, I chose a lighter alternative that can be hosted locally in the application. The tables are accessed through Investment.db. Ultralight was a bit difficult to implement due to a lack of documentation, but the base connection has been made so I'll continue to learn as I build on it in the later Homeworks. Directions to run an Ultralight example within the portfolio-manager repo are detailed in the README.md. The includes for Ultralight are commented out because I am not fully implementing Ultralight until Homework 5, as stated in the proposal. 
    - Initial header files: Done. They are subject to change as I integrate them into the project, but as it stands I believe the methods and fields are listed properly for how the classes will be used. I didn't list the Forecast class in the proposal, but that was always part of the plan and documented elsewhere in that submission. I changed the "Asset" class to be the "Market" class, since it's a class for all the Assets, aka a Market. 
    - Mock-up program: I started out on paper with a storyboard to plan what I wanted the program to look like. I then used a software called Framer X to visualize and link the pages together. The file for this is in the repo as mockup.framerx, but you'll need to download the software in order to view it interactively. A 14-day free trial is offered without providing a card number, so you can download and view the file without worrying about cancelling the subscription. I also uploaded a .png of the flowchart and am happy to show you the interactive version with button linking in person. Framer X is noted in the main README.md. 
    - Find real and mock data: Mentioned in this step was the need to find real data by October 13th. As I spoke on in person, Yahoo Finance's API was removed so all API's that provide financial data tend to be on a subscription basis. After some research into the API's I mentioend (Alpha Vantage, etc.) I decided that it's less plausible to use one of these since they limit calls without paying for a subscription. For the sake of testing purposes and not spending money when there are alternatives, I won't be going with a real-time API. Instead, I'll be downloading a couple hundred stocks into a CSV and loading that into the database. While this won't be real-time, it still provides recent and real data that can be used for all the same purposes. I'm happy to discuss how this will look in further detail, but the gist of it is that it will provide the same features as any other option, but with quotes delayed a few weeks. 
    - Preliminary test cases: Done. I created a few test cases to run through the program as it stands for Homework 3 using Catch2. These are pretty basic and relate to the Investor class. The testing will be built upon further in the project as the data is loaded and the front-end has transitioned to a GUI from its current Text UI state. 
    - Create Investor class: Done. Objects are created using user input and tests for functionality have come back positive. 

3) What was planned for in the Homework 4 proposal and any changes: 
    - Draw data into project: This phase will need to access data from the first phase and insert it into a database. This data will be used by the three classes yet to be implemented: financial assets, portfolio, and forecast. 
        - Still the plan. 
    - Create financial asset class: This class will be the first to be created following the investor class in the first phase. It will involve pulling data from the database and sorting it by sector, date, and price. It will then have to be accessible by the investor class, the portfolio class, and the forecast class. 
        - Still the plan. 
    - Create portfolio class: This class will use the prior two – investor and financial assets – and create a portfolio based on the characteristics of the two. It will then create a portfolio object consisting of financial assets that cater to the investor’s profile. 
        - Still the plan. 
    - Create algorithms for risk assessment and forecasting: Both these algorithms will be reliant on the decided data in this phase, so it’s a good point to create algorithms for future use.  (taken out from Homework 3) 
        - The risk assessment of the investor was done in Homework 3 since it aligned with the Investor class. The risk assessment for assets themselves and how they're matched with the Investor's risk will be done in Homework 4. This step is more background functionality than UI, so it doesn't have a corresponding slide in the mock-up. The Forecasting algorithm will still be done in Homework 4. 
    - Create initial text UI: Unless there is more time left in this phase than anticipated, a text UI in the terminal will be the best way to test the current state. This way I can work through the functionality without worrying about a pretty UI. Furthermore, the state at this point should be able to run without the final class – forecasting. 
        - Still the plan. The Text UI is already created for the Investor class so it will be built upon. 
    - What knowledge will I need to know? Everything we’ve gone over in classes with class, object, and the like. How to draw data into a database and access it, using SOCI. 
        - No longer using SOCI. I'll have to do the same task for MySQL C++ Connector. 
    - What will I need to learn? I’m new to the SOCI library so along with the initial studying done in the first phase, I’ll need to be sure to implement it correctly here. 
        - No longer using SOCI. I'll have to do the same task for MySQL C++ Connector. 

4) These screenshots show the current functionality of the program. Included with each Text UI screenshot is a screenshot of the same functionality on the GUI mock-up. 

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